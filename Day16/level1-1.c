#include <stdio.h>
#include <stdlib.h>

//GLOBALES	



char	*input = "#################;#...#...#...#..E#;#.#.#.#.#.#.#.#.#;#.#.#.#...#...#.#;#.#.#.#.###.#.#.#;#...#.#.#.....#.#;#.#.#.#.#.#####.#;#.#...#.#.#.....#;#.#.#####.#.###.#;#.#.#.......#...#;#.#.###.#####.###;#.#.#...#.....#.#;#.#.#.#####.###.#;#.#.#.........#.#;#.#.#.#########.#;#S#.............#;#################;";


char	**map;
char	**ff_map;

//int	goal_reached = 0;

int	global_step = 2000000000;

int	row_len;
int	row_max;

int	start_row;
int	start_col;

//*****************************
//*****************************

char	**ft_split(char const *s, char c);

//*****************************
//*****************************

void	move_east(int i, int j, int step);
void	move_west(int i, int j, int step);
void	move_north(int i, int j, int step);
void	move_south(int i, int j, int step);

//*****************************
//*****************************


//MOVIVIMIENTO


void	move_east(int i, int j, int step)
{
	//printf("east\n");
	ff_map[i][j] = 'W';
	if (map[i][j+1] == 'E')	//final
	{
		step += 1;
		if (step <= global_step)	//nos quedamos con el mas pequeño
			global_step = step;
		return ;
	}
	if (map[i][j+1] != '#' && ff_map[i][j+1] != 'W')		//si no hay muro, p'alante
		move_east(i, j+1, step+1);
	if (map[i][j+1] == '#')		//si hay muro, checkear lados
	{
		if (map[i-1][j] == '#' && map[i+1][j] == '#') //callejon cerrado
			return ;
	}
	if (map[i-1][j] != '#' && ff_map[i-1][j] != 'W')		//p'arriba
	{
		move_north(i, j, step+1000);
	}
	if (map[i+1][j] != '#' && ff_map[i+1][j] != 'W')		//p'abajo
	{
		move_south(i, j, step+1000);
	}
	return ;
}

//si peta, añadirle que escriba '.' en la pos actual antes de los returns



void	move_west(int i, int j, int step)
{
	//printf("west\n");
	ff_map[i][j] = 'W';
	if (map[i][j-1] == 'E')
	{
		step += 1;
		if (step <= global_step)
			global_step = step;
		return ;
	}
	if (map[i][j-1] != '#' && ff_map[i][j-1] != 'W')
		move_west(i, j-1, step+1);
	if (map[i][j-1] == '#') 
	{
		if (map[i-1][j] == '#' && map[i+1][j] == '#') 
			return ;
	}
	if (map[i-1][j] != '#' && ff_map[i-1][j] != 'W')
	{
		move_north(i, j, step+1000); 
	}
	if (map[i+1][j] != '#' && ff_map[i+1][j] != 'W')
	{
		move_south(i, j, step+1000); 
	}
	
	return ;
}


void	move_north(int i, int j, int step)
{
	//printf("north\n");
	ff_map[i][j] = 'W';
	if (map[i-1][j] == 'E')
	{
		step += 1;
		if (step <= global_step)
			global_step = step;
		return ;
	}
	if (map[i-1][j] != '#' && ff_map[i-1][j] != 'W') 
		move_north(i-1, j, step+1);
	if (map[i-1][j] == '#') 
	{
		if (map[i][j-1] == '#' && map[i][j+1] == '#') 
			return ;
	}
	if (map[i][j+1] != '#' && ff_map[i][j+1] != 'W')
	{
		move_east(i, j, step+1000); 
	}
	if (map[i][j-1] != '#' && ff_map[i][j-1] != 'W')
	{
		move_west(i, j, step+1000); 
	}
	
	return ;
}


void	move_south(int i, int j, int step)
{
	//printf("south\n");
	ff_map[i][j] = 'W';
	if (map[i+1][j] == 'E') 
	{
		step += 1;
		if (step <= global_step)
			global_step = step;
		return ;
	}
	if (map[i+1][j] != '#' && ff_map[i+1][j] != 'W') 
		move_south(i+1, j, step+1);
	if (map[i+1][j] == '#') 
	{
		if (map[i][j-1] == '#' && map[i][j+1] == '#') 
			return ;
	}
	if (map[i][j+1] != '#' && ff_map[i][j+1] != 'W')
	{
		move_east(i, j, step+1000);
	}
	if (map[i][j-1] != '#' && ff_map[i][j-1] != 'W')
	{
		move_west(i, j, step+1000); 
	}
	
	return ;
}

//*********************************************
//*********************************************


void size_and_pos()
{
	int	i = 0;
	int	j = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'S')
			{
				start_row = i;
				start_col = j;
			}
			j++;
		}
		i++;
	}
	row_max = i;
	row_len = j;
}

//********************************************
//********************************************

int	main()
{
	map = ft_split(input, ';');
	size_and_pos();
	
	ff_map = ft_split(input, ';');
	
	move_east(start_row, start_col, 0);
	
	int i = 0;
	
	
	while (i < row_max)
	{
		printf("%s\n", ff_map[i]);
		i++;
	}
	
	printf("Shortest route : %d", global_step);
}

//plan B
//recorrer el laberinto, cunado encuentra intersecccion, llamar a la funcoin, pero desde el anterior intrseccion hatsta la nueva



