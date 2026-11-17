/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgalean <asgalean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:08:34 by asgalean          #+#    #+#             */
/*   Updated: 2024/11/29 17:21:34 by asgalean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static char	**create_list(char const *s, char c)
{
	size_t	word_count;
	size_t	i;
	char	**list;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c )
			i++;
		if (s[i] != c)
			word_count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	list = (char **)malloc(sizeof(char *) * (word_count + 1));
	list[word_count] = 0;
	return (list);
}

//if it crashes or breaks, use calloc instead of malloc and use the new
//free lines to make "if (!(malloc_created_array)) -> return (0);"
char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word_i;
	char	**word_list;

	word_i = 0;
	i = 0;
	word_list = create_list(s, c);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (s[i + j] == '\0' && s[i + j - 1] == c)
			break ;
		word_list[word_i] = (char *)malloc(sizeof(char) * (j + 1));
		j = 0;
		while (s[i] != c && s[i] != '\0')
			word_list[word_i][j++] = s[i++];
		word_list[word_i][j] = '\0';
		word_i++;
	}
	return (word_list);
}
