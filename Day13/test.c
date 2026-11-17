#include<stdio.h>
#include<stdlib.h>



char	*input = "Button A: X+94, Y+34.Button B: X+22, Y+67.Prize: X=8400, Y=5400";

char	**eq_array;

long long	xa;
long long	ya;
long long	xb;
long long	yb;
long long	xtot;
long long	ytot;


char	**ft_split(char const *s, char c);	//puto split


void	parseo_papu(char *eq_sys)	//parseo cada parrafo/sistema de ecuaciones yn las 6 vasriable
{
	long long	i;
	long long	counter;
	i = 0;
	counter = 0;
	while (eq_sys[i] != '\0')
	{
		if (eq_sys[i] == 'X')
		{
			i += 2;
			if (counter == 0)
			{
				xa = atoll(&eq_sys[i]);
				counter++;
			}
			if (counter == 2)
			{
				xb = atoll(&eq_sys[i]);
				counter++;
			}
			if (counter == 4)
			{
				xtot = atoll(&eq_sys[i]);
				counter++;
			}
		}
		if (eq_sys[i] == 'Y')
		{
			i += 2;
			if (counter == 1)
			{
				ya = atoll(&eq_sys[i]);
				counter++;
			}
			if (counter == 3)
			{
				yb = atoll(&eq_sys[i]);
				counter++;
			}
			if (counter == 5)
			{
				ytot = atoll(&eq_sys[i]);
				counter++;
			}
		}
		i++;
	}
}



int	main()
{
	long long	a_temp_xb;
	long long	a_temp_xtot;
	
	long long	b_temp_xa;
	long long	b_temp_xtot;
	
	
	eq_array = ft_split(input, ';');
	parseo_papu(eq_array[0]);
	
	a_temp_xb = xb % xa;
	a_temp_xtot = xtot % xa;
	
	b_temp_xa = xa % xb;
	b_temp_xtot = xtot % xb;
	
	long long	i;
	long long	j;
	
	j = 0;
	i = 0;
	
	while (i < xa)
	{
		if ((a_temp_xb * i) % xa == a_temp_xtot)
			printf("hay solucion: i = %lld\n", i);		
		//else
			//printf("Paso %lld, no hay soluion\n", i);
		i++;
	}
	while (j < xb)
	{
		if ((b_temp_xa * j) % xb == b_temp_xtot)
			printf("hay solucion: j = %lld\n", j);		
		//else
			//printf("Paso %lld, no hay soluion\n", j);
		j++;
	}
	
	printf("===============================\n");
	
	long long	a_temp_yb;
	long long	a_temp_ytot;
	
	long long	b_temp_ya;
	long long	b_temp_ytot;


	a_temp_yb = yb % ya;
	a_temp_ytot = ytot % ya;
	
	b_temp_ya = ya % yb;
	b_temp_ytot = ytot % yb;

	j = 0;
	i = 0;
	
	while (i < ya)
	{
		if ((a_temp_yb * i) % ya == a_temp_ytot)
			printf("hay solucion: i = %lld\n", i);		
		//else
		//	printf("Paso %lld, no hay soluion\n", i);
		i++;
	}
	while (j < yb)
	{
		if ((b_temp_ya * j) % yb == b_temp_ytot)
			printf("hay solucion: j = %lld\n", j);		
		//else
			//printf("Paso %lld, no hay soluion\n", j);
		j++;
	}


}
