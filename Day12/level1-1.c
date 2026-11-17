#include <stdlib.h>
#include <stdio.h>

//GAMEPLAN:
//encontramos una casilla, y vamos recorriendo l amatriz hasta cubrr todas esas letras (copiandoas 
//en otro mapa, y luego en ese otro maa vamos mirando su area y perimetro), tambien tenemos otro mapa en el que vamos guardando las areas que ya hemoss checkeado;


//GLOBALES

char	*input = "AAAA;AAAA;AAAB;BBBA";

char	**log_map;	//el mapa en el que guardamos areas ya  checkeadas (para evitar repetir)
char	**step_map;	//mapa qe vams aa resetear y rellenar con cada area, para contar


char	**map;
long long	row_max = 0;
long long	row_len = 0;




long long	total_cost = 0;

long long	step_area = 0;
long long	step_perim = 0;


//*********************************
//*********************************

char	**ft_split(char const *s, char c); //Claassic split

//*********************************
//*********************************

void	map_size()	//sacams las dimensiones del mapa que nos dan
{
	while (map[row_max] != 0)
		row_max++;
	while (map[0][row_len] != '\0')
		row_len++;
}

//********************************
//********************************
void	map_filler()	//llenar log_map y step_map con basura, el log map y se llenará luego
{
	long long	i;
	long long	j;
	
	i = 0;
	while (i < row_max)
	{
		j = 0;
		while (j < row_len)
		{
			log_map[i][j] = '.';
			step_map[i][j] = '.';
			j++;
		}
		i++;
	}
}

//*************************************
//*************************************

void	reset_step_map()	//para resetar step_map con cada nueva area
{
	long long	i;
	long long	j;
	
	i = 0;
	while (i < row_max)
	{
		j = 0;
		while (j < row_len)
		{
			step_map[i][j] = '.';
			j++;
		}
		i++;
	}
}


//*********************************
//*********************************
//copia el area en step_map y en log_map

void	area_copier(char letter, long long i, long long j)
{
	
	step_map[i][j] = letter;
	log_map[i][j] = letter;
	
	if (i - 1 >= 0 && map[i-1][j] == letter && step_map[i-1][j] != letter)
	{
		area_copier(letter, i - 1, j);
	}
	if (i + 1 < row_max && map[i+1][j] == letter && step_map[i+1][j] != letter)
	{
		area_copier(letter, i + 1, j);
	}
	if (j - 1 >= 0 && map[i][j-1] == letter && step_map[i][j-1] != letter)
	{
		area_copier(letter, i, j - 1);
	}
	if (j + 1 < row_len && map[i][j+1] == letter && step_map[i][j+1] != letter)
	{
		area_copier(letter, i, j + 1);
	}
	
}
/*
	if (col < 0 || row < 0 || !step_map[row] || !step_map[row][col])
		return ;
	if (map[row][col] == letter)
	{
		step_map[row][col] = letter;
		log_map[row][col] = letter;
	}
	area_copier(letter, row - 1, col);
	area_copier(letter, row + 1, col);
	area_copier(letter, row, col - 1);
	area_copier(letter, row, col + 1);	
	*/




//*****************************************************
//*****************************************************


void	step_calculator(char letter)	//recorre step_map, y mira donde acaba cada trozo del area
{
	long long	i;
	long long	j;
	
	i = 0;
	while  (i < row_max)
	{
		j = 0;
		while (j < row_len)
		{
			if (step_map[i][j] == letter)
			{
				step_area++;
				if (i == 0 || i == row_max - 1)
					step_perim++;
				if (j == 0 || j == row_len - 1)
					step_perim++;
				if (((i-1) >= 0) && (step_map[i - 1][j] != letter))
					step_perim++;
				if (((i+1) < row_max) && (step_map[i + 1][j] != letter))
					step_perim++;
				if (((j-1) >= 0) && (step_map[i][j - 1] != letter))
					step_perim++;
				if (((j+1) < row_len) && (step_map[i][j + 1] != letter))
					step_perim++;
			}
			j++;
		}
		i++;
	}
}


//*********************************
//*********************************

void	map_printer(char **map)		//printea el mapa dado
{
	long long	i;
	long long	j;
	
	i = 0;
	while (i < row_max)
	{
		j = 0;
		while (j < row_len)
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

//*********************************
//*********************************


int	main()
{
	
	map = ft_split(input, ';');
	log_map = ft_split(input, ';');
	step_map = ft_split(input, ';');
	
	map_size();
	map_filler();
	
	//*****************************
	map_printer(map);
	printf("-------\n");
	
	map_printer(step_map);
	printf("-------\n");
	
	map_printer(log_map);
	printf("-------\n");
	//*****************************
	
	
	long long	i;
	long long	j;
	
	i = 0;
	while (i < row_max)
	{
		j = 0;
		while (j < row_len)
		{
			printf("======= (%lld,%lld)\n", i,j);
			if (map[i][j] != log_map[i][j]) //si no se ha heho ya ese area, hacemos
			{
				step_area = 0;
				step_perim = 0;
				reset_step_map();
				printf("\npeta\n---------\n");
				area_copier(map[i][j], i, j);
				map_printer(step_map);
				printf("-------\n");
				map_printer(log_map);
				printf("\n\n");
				
				step_calculator(step_map[i][j]);
				
				printf("(%lld,%lld)\n", step_area, step_perim);
				total_cost = total_cost + (step_area * step_perim);
				printf("%lld", total_cost);
								
			}
			j++;
		}
		i++;
	}
	//printf("%lld", total_cost);
}













