#include <stdio.h>


//GLOBAES

char	*input = "";

char	map[71][71];



int	main()
{
	int	i = 0;
	int	j = 0;
	
	while (i < 71)
	{
		j = 0;
		while (j < 71)
		{
			map[i][j] = '.';
			printf("%c", map[i][j]),
			j++;
		}
		printf("\n");
		i++;
	}
}
