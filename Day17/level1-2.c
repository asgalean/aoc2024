#include <stdlib.h>
#include <stdio.h>


//GLOBALES

//char	*input = "24 11 75 15 40 03 55 30";
char	*input = "035430";

long long	A = 0;
long long	B = 0;
long long	C = 0;

long long	i = 0;
long long	output_pos = 5;

//en el ejemplo simplemente es + ipnut[output_pos] y luego * (0,3) = 2*2*2 = 8






//************************
//************************

long long	power(long long nb, long long power);

//************************
//************************


void	opcode_0(char a)	//reverted
{
	long long	operand;
	
	operand = a - '0';
	
	if (operand >= 0 && operand <= 3)
		A = A * (power(2, operand));
	if (operand == 4)
		A = A * (power(2, A));
	if (operand == 5)
		A = A * (power(2, B));
	if (operand == 6)
		A = A * (power(2, C));
}

void	opcode_1(char a)	//ya es su propia inversa
{
	long long	operand;
	
	operand = a - '0';
	B = B ^ operand;
}

void	opcode_2(char a)
{
	long long	operand;
	
	operand = a - '0';
	
	if (operand == 4)
		B = A % 8;
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

void	opcode_5(char a)	//revereted
{
	long long	operand;
	
	operand = a - '0';
	//if (operand >= 0 && operand <= 3)
		
		//printf("%lld", operand % 8);
	if (operand == 4)
		A = A + input[output_pos] - '0';
	if (operand == 5)
		B = B + input[output_pos] - '0';
	if (operand == 6)
		C = C + input[output_pos] - '0';
}

void	opcode_6(char a) //NO SE USA
{
	long long	operand;
	
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
	long long	operand;
	
	operand = a - '0';
	
	if (operand == 5)
		A = C * power(2, B);
		//C = A / (power(2, B));
}






int	main()
{
	//printf("%d", 7^5);
	
	//long long	flag = 0;
	

	while (output_pos >= 0)
	{
		i = 4;
		//printf("%lld\n", output_pos);
		while (i >= 0)
		{
			//flag = 0;
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
			//else if (input[i] == '3')
			//{
			//	opcode_3(input[i+1]);
			//	flag = 1;
			//}
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
			
			
			i = i - 2;
			
		}
		printf("%lld\n", A);
		output_pos--;
	}
	printf("%lld\n", A);
}




























