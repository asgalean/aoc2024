#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to evaluate the expression with given numbers and operators
int evaluate_expression(int *numbers, char *operators, int n) {
    int result = numbers[0];
    for (int i = 1; i < n; i++) {
        if (operators[i - 1] == '+') {
            result += numbers[i];
        } else if (operators[i - 1] == '*') {
            result *= numbers[i];
        }
    }
    return result;
}

// Function to check if an equation can be true with the given operators
int check_equation(int test_value, int *numbers, int n) {
    int total_combinations = 1 << (n - 1);  // 2^(n-1) combinations for n-1 positions
    
    // Iterate over all possible combinations of '+' and '*'
    for (int i = 0; i < total_combinations; i++) {
        char *operators = (char *)malloc((n - 1) * sizeof(char));
        for (int j = 0; j < n - 1; j++) {
            if ((i >> j) & 1) {
                operators[j] = '*';
            } else {
                operators[j] = '+';
            }
        }
        
        // Evaluate the current combination of operators
        int result = evaluate_expression(numbers, operators, n);
        free(operators);  // Free the dynamically allocated operators array
        
        if (result == test_value) {
            return 1; // Valid equation found
        }
    }
    return 0; // No valid equation
}

// Function to calculate the total calibration result
int calculate_calibration_result() {
    int total = 0;
    char *line = NULL;
    size_t len = 0;

    // Read lines until EOF
    while (getline(&line, &len, stdin) != -1) {
        int test_value;
        int *numbers = (int *)malloc(10 * sizeof(int)); // Start with a buffer for up to 10 numbers
        int num_count = 0;

        // Parse the line into the test value and numbers
        char *token = strtok(line, ":");
        test_value = atoi(token); // Test value before the colon

        token = strtok(NULL, " ");
        while (token != NULL) {
            // Resize the numbers array if needed
            if (num_count >= 10) {
                numbers = (int *)realloc(numbers, (num_count + 1) * sizeof(int));
            }
            numbers[num_count++] = atoi(token);
            token = strtok(NULL, " ");
        }

        // Check if the equation is valid
        if (check_equation(test_value, numbers, num_count)) {
            total += test_value;  // Add to the total if valid
        }

        free(numbers);  // Free the numbers array for this equation
    }

    free(line);  // Free the line buffer
    return total;
}

int main() {
    // Calculate the total calibration result by reading from stdin
    int result = calculate_calibration_result();
    printf("Total Calibration Result: %d\n", result);

    return 0;
}

