#include <stdlib.h>
#include <stdio.h>


//GLOBALES

char	*input = "2411751540035530";

int	A = 64196994;
int	B = 0;
int	C = 0;

int	i = 0;

//************************
//************************

int	power(int nb, int power);

//************************
//************************


void	opcode_0(char a)
{
	int	operand;
	
	operand = a - '0';
	
	if (operand >= 0 && operand <= 3)
		A = A / (power(2, operand));
	if (operand == 4)
		A = A / (power(2, A));
	if (operand == 5)
		A = A / (power(2, B));
	if (operand == 6)
		A = A / (power(2, C));
}

void	opcode_1(char a)
{
	int	operand;
	
	operand = a - '0';
	B = B ^ operand;
}

void	opcode_2(char a)
{
	int	operand;
	
	operand = a - '0';
	
	if (operand >= 0 && operand <= 3)
		B = operand % 8;
	if (operand == 4)
		B = A % 8;
	if (operand == 5)
		B = B % 8;
	if (operand == 6)
		B = C % 8;
}

void	opcode_3(char a)
{
	if (A)
	{
		i = a - '0';
	}
}


void	opcode_4()
{
	B = B ^ C;
}

void	opcode_5(char a)
{
	int	operand;
	
	operand = a - '0';
	if (operand >= 0 && operand <= 3)
		printf("%d,", operand % 8);
	if (operand == 4)
		printf("%d,", A % 8);
	if (operand == 5)
		printf("%d,", B % 8);
	if (operand == 6)
		printf("%d,", C % 8);
}

void	opcode_6(char a)
{
	int	operand;
	
	operand = a - '0';
	
	if (operand >= 0 && operand <= 3)
		B = A / (power(2, operand));
	if (operand == 4)
		B = A / (power(2, A));
	if (operand == 5)
		B = A / (power(2, B));
	if (operand == 6)
		B = A / (power(2, C));
}

void	opcode_7(char a)
{
	int	operand;
	
	operand = a - '0';
	
	if (operand >= 0 && operand <= 3)
		C = A / (power(2, operand));
	if (operand == 4)
		C = A / (power(2, A));
	if (operand == 5)
		C = A / (power(2, B));
	if (operand == 6)
		C = A / (power(2, C));
}






int	main()
{
	//printf("%d", 7^5);
	int	flag = 0;
	
	while (input[i+1] != '\0')
	{
		flag = 0;
		if (input[i] == '0')
		{
			opcode_0(input[i+1]);
		}
		else if (input[i] == '1')
		{
			opcode_1(input[i+1]);
		}
		else if (input[i] == '2')
		{
			opcode_2(input[i+1]);
		}
		else if (input[i] == '3')
		{
			opcode_3(input[i+1]);
			flag = 1;
		}
		else if (input[i] == '4')
		{
			opcode_4();
		}
		else if (input[i] == '5')
		{
			opcode_5(input[i+1]);
		}
		else if (input[i] == '6')
		{
			opcode_6(input[i+1]);
		}
		else if (input[i] == '7')
		{
			opcode_7(input[i+1]);
		}
		
		if (input[i+2] == '\0')
			break ;
		
		if (flag == 0)
			i = i + 2;
		

	}
	
	
}




























