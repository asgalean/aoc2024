#include	<stdio.h>
#include	<stdlib.h>



//GLOBALES
char	*input = "AAAA;BBCD;BBCC;EEEC";

char	**map;
char	**step_map;
char	**log_map;

long long	row_max = 0;
long long	row_len = 0;

//************************
//************************


char	**ft_split(char const *s, char c); //Split

//***********************
//***********************

void	size_getter()
{
	long long	i = 0;
	long long	j = 0;
	
	while (map[i] != 0)
		i++;
	while (map[0][j] != '\0')
		j++;
	row_max = i;
	row_len = j;
}

//************************
//************************

void	map_init()
{
	long long	i = 0;
	long long	j = 0;
	
	while (i < row_max)
	{
		j = 0;
		while (j < row_len)
		{
			step_map[i][j] = '.';
			log_map[i][j] = '.';
			j++;
		}
		i++;
	}
}

//************************
//************************

void	map_printer(char **onepiece)
{
	int	i = 0;
	int	j = 0;
	
	while (i < row_max)
	{
		j = 0;
		while (j < row_len)
		{
			printf("%c", onepiece[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
//************************
//************************
//intentode floodfill que va a copiar todas las letras del area en log_map y en step_map
void	cumfill(char letra, long long i, long long j)
{
	step_map[i][j] = letra;
	log_map[i][j] = letra;
	if ((i - 1) >= 0 && map[i-1][j] == letra && step_map[i][j] != letra)
		cumfill(letra, i-1, j);
	if ((i + 1) <= row_max - 1 && map[i+1][j] == letra && step_map[i][j] != letra)
		cumfill(letra, i+1, j);
	if ((j - 1) >= 0 && map[i][j-1] == letra && step_map[i][j] != letra)
		cumfill(letra, i, j-1);
	if ((j + 1) <= row_len - 1 && map[i][j+1] && step_map[i][j] != letra)
		cumfill(letra, i, j+1);
	
	return ;
}

//************************
//************************

int	main()
{
	map = ft_split(input, ';');
	step_map = ft_split(input, ';');
	log_map = ft_split(input, ';');
	
	size_getter();
	
	map_init();
	
	long long	i = 0;
	long long	j = 0;
	
	while (i < row_max)
	{
		j = 0;
		while (j < row_len)
		{
			cumfill(map[i][j],i ,j);
			//printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	
	/*
	map_printer(map);
	printf("\n");
	map_printer(step_map);
	printf("\n");
	map_printer(log_map);
	printf("\n");
	*/
}
