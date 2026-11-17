#include <stdio.h>
#include <stdlib.h>


//GLOBALES


char	*input_map = "#######;#...#.#;#.....#;#..OO@#;#..O..#;#.....#;#######";
char	*rules = "";
char	**map;

char	**wide_map;

int	row_pos;
int	col_pos;


int	row_len = 0;
int	row_max = 0;

int	wide_row_pos;
int	wide_col_pos;


int	wide_row_len = 0;
int	wide_row_max = 0;


//int	total = 0;

//******************************
//******************************

char	**ft_split(char const *s, char c);	//classic split

//******************************
//******************************

void	size_and_pos()	//consigue la posicion inicial y las dimensiones del mapa
{
	int	i;
	int	j;
	
	
	
	i = 0;
	while (map[i] != 0)
	{
		
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '@')
			{
				row_pos = i;
				col_pos = j;
			}
			if (i == 0)
			{
				row_len++;
			}
			j++;
		}
		row_max++;
		i++;
	}
}

//*******************************
//*******************************

void	move_boxes()	//movida de cajas
{
	int	s;
	int	k;
	k = 0;
	
	while (rules[k] != '\0')
	{
	
		s = 0;
		if (rules[k] == '^')	//ARRIBA
		{
			if (map[row_pos - 1][col_pos] != '#')	//si no es muro, haz cosas
			{
				if (map[row_pos - 1][col_pos] == 'O') //si hay caja
				{
					while (map[row_pos - 1 - s][col_pos] == 'O') //mirar donde acaban las cajas
					{
						s++;
					}
					if (map[row_pos - 1 - s][col_pos] != '#') //si no es muro, mover caja(s)
					{
						map[row_pos - 1 - s][col_pos] = 'O';
						map[row_pos - 1][col_pos] = '@';
						map[row_pos][col_pos] = '.';
						row_pos = row_pos - 1;
					}
				}
				else	//si no hay caja
				{
					map[row_pos - 1][col_pos] = '@';
					map[row_pos][col_pos] = '.';
					row_pos = row_pos - 1;
				}
			}
		}
		
		
		//*********
		
		if (rules[k] == 'v')	//ABAJO
		{
			if (map[row_pos + 1][col_pos] != '#')	//si no es muro, haz cosas
			{
				if (map[row_pos + 1][col_pos] == 'O') //si hay caja
				{
					while (map[row_pos + 1 + s][col_pos] == 'O') //mirar donde acaban las cajas
					{
						s++;
					}
					if (map[row_pos + 1 + s][col_pos] != '#') //si no es muro, mover caja(s)
					{
						map[row_pos + 1 + s][col_pos] = 'O';
						map[row_pos + 1][col_pos] = '@';
						map[row_pos][col_pos] = '.';
						row_pos = row_pos + 1;
					}
				}
				else	//si no hay caja
				{
					map[row_pos + 1][col_pos] = '@';
					map[row_pos][col_pos] = '.';
					row_pos = row_pos + 1;
				}
			}
		}
		
		//**********
		
		if (rules[k] == '<')	//IQUIERDA
		{
			if (map[row_pos][col_pos - 1] != '#')	//si no es muro, haz cosas
			{
				if (map[row_pos][col_pos - 1] == 'O') //si hay caja
				{
					while (map[row_pos][col_pos - 1 - s] == 'O') //mirar donde acaban las cajas
					{
						s++;
					}
					if (map[row_pos][col_pos - 1 - s] != '#') //si no es muro, mover caja(s)
					{
						map[row_pos][col_pos - 1 - s] = 'O';
						map[row_pos][col_pos - 1] = '@';
						map[row_pos][col_pos] = '.';
						col_pos = col_pos - 1;
					}
				}
				else	//si no hay caja
				{
					map[row_pos][col_pos - 1] = '@';
					map[row_pos][col_pos] = '.';
					col_pos = col_pos - 1;
				}
			}
		}
		
		//**********
		
		if (rules[k] == '>')	//DERECHA
		{
			if (map[row_pos][col_pos + 1] != '#')	//si no es muro, haz cosas
			{
				if (map[row_pos][col_pos + 1] == 'O') //si hay caja
				{
					while (map[row_pos][col_pos + 1 + s] == 'O') //mirar donde acaban las cajas
					{
						s++;
					}
					if (map[row_pos][col_pos + 1 + s] != '#') //si no es muro, mover caja(s)
					{
						map[row_pos][col_pos + 1 + s] = 'O';
						map[row_pos][col_pos + 1] = '@';
						map[row_pos][col_pos] = '.';
						col_pos = col_pos + 1;
					}
				}
				else	//si no hay caja
				{
					map[row_pos][col_pos + 1] = '@';
					map[row_pos][col_pos] = '.';
					col_pos = col_pos + 1;
				}
			}
		}
		
		
		k++;
	}
}

//*******************************
//*******************************

void	map_print()
{
	int	i = 0;
	int	j = 0;
	
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


//*******************************
//*******************************

/*
void	map_count()
{
	int	i = 0;
	int	j = 0;
	
	while (i < row_max)
	{
		j = 0;
		while (j < row_len)
		{
			if (map[i][j] == 'O')
			{
				total += (i*100) + j;
			}
			j++;
		}
		i++;
	}
}
*/

//*******************************
//*******************************

void	map_widener()
{
	int	i = 0;
	int	j = 0;
	
	wide_map = (char **)malloc(sizeof(char *) * row_max + 1);
	wide_map[row_max] = 0;
	
	while (i < row_max)
	{
		wide_map[i] = (char *)malloc(sizeof(char) * 2 * row_len + 1);
		i++;
	}
	
	i = 0;
	
	while (i < row_max)
	{
		j = 0;
		while (j < row_len)
		{
			if (map[i][j] == '#')
			{
				wide_map[i][2*j] = '#';
				wide_map[i][2*j+1] = '#';
			}
			if (map[i][j] == 'O')
			{
				wide_map[i][2*j] = '[';
				wide_map[i][2*j+1] = ']';
			}
			if (map[i][j] == '.')
			{
				wide_map[i][2*j] = '.';
				wide_map[i][2*j+1] = '.';
			}
			if (map[i][j] == '@')
			{
				wide_map[i][2*j] = '@';
				wide_map[i][2*j+1] = '.';
			}
			j++;
		}
		wide_map[i][2*j] = '\0';
		i++;
	}
}


//*******************************
//*******************************

void	wide_print()
{
	int	i = 0;
	int	j = 0;
	
	while (i < row_max)
	{
		j = 0;
		while (wide_map[i][j] != '\0')
		{
			printf("%c", wide_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


//*******************************
//*******************************

void	wide_size_pos()
{
	//consigue la posicion inicial y las dimensiones del mapa

	int	i;
	int	j;
	
	
	
	i = 0;
	while (wide_map[i] != 0)
	{
		
		j = 0;
		while (wide_map[i][j] != '\0')
		{
			if (wide_map[i][j] == '@')
			{
				wide_row_pos = i;
				wide_col_pos = j;
			}
			if (i == 0)
			{
				wide_row_len++;
			}
			j++;
		}
		wide_row_max++;
		i++;
	}

}

//*******************************
//*******************************
int	main()
{
	map = ft_split(input_map, ';');
	size_and_pos();
	
	
	map_print();
	
	//move_boxes();
	
	printf("\n=====================================================\n");
	
	map_widener();
	
	wide_size_pos();
	
	wide_print();
	
	//map_count();
	
	//printf("%d", total);
	
}



