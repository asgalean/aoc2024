#include <stdlib.h>
#include <stdio.h>

char *input = "190: 10 19;3267: 81 40 27;83: 17 5;156: 15 6;7290: 6 8 6 15;161011: 16 10 13;192: 17 8 14;21037: 9 7 18 13;292: 11 6 16 20;729: 13 14 27";
char **input_in_char_array;
long long input_row_max = 0;  // number of rows
long long *keys;              // values to calculate
long long **numbers;          // array of numbers for each row
long long row_len = 0;        // length of numbers in each row
long long row = 0;            // current row for iteration

// Split function
char **ft_split(char const *s, char c);  // Implementation of the split function (you can use any of your preferred split methods here)

// Count the number of rows in the input
void input_len_guesser() {
    long long i = 0;
    while (input_in_char_array[i] != 0) {
        input_row_max++;
        i++;
    }
}

// Parse keys from input
void keys_getter() {
    long long i = 0, j = 0;
    while (i < input_row_max) {
        j = 0;
        keys[i] = atoll(&input_in_char_array[i][j]);
        i++;
    }
}

// Parse numbers from each row (without the key)
void int_array_maker(char *row_i) {
    long long i = 0, num_index = 0;
    row_len = 0;
    
    // Find length of the row (number of numbers)
    while (row_i[i] != ':') i++;
    i++;
    
    while (row_i[i] != '\0') {
        if (row_i[i] <= '9' && row_i[i] >= '0') {
            row_len++;
            while (row_i[i] != ' ' && row_i[i] != '\0') i++;
        }
        i++;
    }
    
    numbers[row] = (long long *)malloc(sizeof(long long) * row_len);
    
    // Fill the numbers array
    i = 0;
    num_index = 0;
    while (row_i[i] != ':') i++;
    i++;
    while (row_i[i] != '\0') {
        if (row_i[i] <= '9' && row_i[i] >= '0') {
            numbers[row][num_index] = atoll(&row_i[i]);
            num_index++;
            while (row_i[i] != ' ' && row_i[i] != '\0') i++;
        }
        i++;
    }
}

// Evaluate the numbers with the given operators
long long evaluate(long long *nums, long long len, char *operators) {
    long long result = nums[0];
    for (long long i = 1; i < len; i++) {
        if (operators[i-1] == '+') {
            result += nums[i];
        } else if (operators[i-1] == '*') {
            result *= nums[i];
        }
    }
    return result;
}

// Backtracking to try all combinations of + and * 
int operator_backtracking(long long *nums, long long len, long long target) {
    char operators[len - 1];
    for (long long i = 0; i < (1 << (len - 1)); i++) {
        // Generate operator combination
        for (long long j = 0; j < len - 1; j++) {
            operators[j] = (i & (1 << j)) ? '*' : '+';
        }
        // Evaluate the current combination
        if (evaluate(nums, len, operators) == target) {
            return 1;
        }
    }
    return 0;
}

int main() {
    row = 0;
    input_in_char_array = ft_split(input, ';');
    input_len_guesser();
    keys = (long long *)malloc(sizeof(long long) * input_row_max);
    numbers = (long long **)malloc(sizeof(long long *) * input_row_max);
    keys_getter();

    long long total_calibration_result = 0;

    while (row < input_row_max) {
        int_array_maker(input_in_char_array[row]);

        if (operator_backtracking(numbers[row], row_len, keys[row])) {
            total_calibration_result += keys[row];
        }

        free(numbers[row]);
        row++;
    }

    printf("Total Calibration Result: %lld\n", total_calibration_result);
    free(keys);
    free(numbers);
    return 0;
}

