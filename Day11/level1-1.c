#include <stdio.h>
#include <stdlib.h>

//GLOBALES


typedef struct s_list
{
	long long	num;
	struct s_list	*next;
}			Nodo;


Nodo	*n1;

char	*input = "773 79858 0 71 213357 2937 1 3998391";

long long	arr_len;

//**************************
//**************************

//LINKED LISTS
Nodo	*create_node(long long	a) //crear un nodo 
{
	Nodo	*caja;
	
	caja = malloc(sizeof(Nodo));
	caja -> num = a;
	caja -> next = NULL;
	return (caja);
}

//*************************

void	insert_node(Nodo *prev, Nodo *middle)	//insertador de nodos (para cuando se parte en dos)
{
	middle -> next = prev -> next;
	prev -> next = middle;
}	
//**************************

// *start es el puntero al nodo, pero start seria el nodo en si
//	entonces, al hacer start = start -> next, estamos tomando el siguiente nodo directamente!!
long long	list_size(Nodo *start)	//contar cuantos nodos hay
{
	long long	len;
	len = 0;
	while (1)
	{
		len++;
		if (start -> next == NULL)
			break ;
		start = start -> next;
	}
	return (len);
}


//**************************
//**************************


long long	ft_power(long long nb, long long power)	//funcion potencia (no es muy didificl de suponer)
{
	long long	a;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	a = 1;
	a = nb * ft_power(nb, (power - 1));
	return (a);
}

//************************
//************************

long long	even_digits(long long num)	//checkea si el num tiene una cantidad de digitos pares
{					//y devuelve la cantidad de digitios si son pares
	long long	i;			// que ocincide ocn la potenci ad e 10 que al dividir da 0
	
	i = 0;
	while (num / ft_power(10, ++i))
		;
	if (i % 2 == 0)
		return (i);
	else
		return (1);
}


//************************
//************************

/*
void	algorythm(Nodo *n1)		//las normas de cambio
{
	long long	pwr;

	if (n1 -> num == 0)
	{
		n1 -> num = 1;
		//return ;
	}
	else if (even_digits(n1 -> num) % 2 == 0)
	{
		pwr = even_digits(n1 -> num);
		insert_node(n1, create_node((n1 -> num) % ft_power(10, (pwr / 2))));
		n1 -> num = (n1 -> num) / ft_power(10, (pwr / 2));
		n1 = n1 -> next;
		//return ;
	}
	else
		n1 -> num = (n1 -> num) * 2024;
	break ;
	
	
	
}
*/

//************************
//************************


int	main()
{
	Nodo	*n1;
	Nodo	*start;
	long long	i;
	
	i = 0;
	n1 = create_node(atoll(&input[i]));
	start = n1;
	//********************************
	printf("%lld ", atoll(&input[i]));
	//********************************
	
	while ('0' <= input[i] && input[i] <= '9')
		i++;
	while (input[i] == ' ')
		i++;
	while (input[i] != '\0')
	{
		//**********************
		printf("%lld ", atoll(&input[i]));
		//**********************
				
		insert_node(n1, create_node(atoll(&input[i])));
		n1 = n1 -> next;
		while ('0' <= input[i] && input[i] <= '9')
			i++;
		while (input[i] == ' ')
			i++;
	}
	
	//****************************
	printf("\n Lista virgen :");
	
	
	n1 = start;
	
	while (1)
	{
		printf("%lld ", n1 -> num);
		if (n1 -> next == NULL)
			break ;
		n1 = n1 -> next;
	}
	//*****************************
	
	long long	blinks;
	blinks = 0;
	
	n1 = start;
	while (blinks < 6)
	{
		n1 = start;
		while (1)
		{
			//algorythm(n1);
		
			long long	pwr;

			if (n1 -> num == 0)
			{
				n1 -> num = 1;
			}
			else if (even_digits(n1 -> num) % 2 == 0)
			{
				pwr = even_digits(n1 -> num);
				insert_node(n1, create_node((n1 -> num) % ft_power(10, (pwr / 2))));
				n1 -> num = (n1 -> num) / ft_power(10, (pwr / 2));
				n1 = n1 -> next;
			}
			else
				n1 -> num = (n1 -> num) * 2024;
		
			if (n1 -> next == NULL)
				break ;
			n1 = n1 -> next;
		}
		blinks++;
	}
	
	
	//*****************************
	/*
	printf("\n Lista modificada :");
	n1 = start;
	
	while (1)
	{
		printf("%lld ", n1 -> num);
		if (n1 -> next == NULL)
			break ;
		n1 = n1 -> next;
	}
	*/
	//*****************************
	
	n1 = start;
	
	long long	size;
	
	size = list_size(n1);
	
	printf("\n%lld", size);

	
	
	
	
}
