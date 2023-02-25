/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:08:58 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/22 18:02:02 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static size_t	wc(char *s, char c)
{
	size_t	lsize;
	size_t	i;

	i = 0;
	lsize = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] == c && s[i + 1] != 0 && \
			s[i + 1] != c))
			lsize++;
		i++;
	}
	return (lsize);
}

static char	**ft_freelist(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
		free(list[i++]);
	free(list);
	return (NULL);
}

static char	**spliter(char **splited, char *s, size_t rows, char c)
{
	size_t	k;
	size_t	row;
	size_t	start;

	k = 0;
	row = 0;
	while (row < rows && s[k])
	{
		while (s[k] == c)
			k++;
		start = k;
		while (s[k] != c && s[k] != 0)
			k++;
		splited[row] = ft_substr(s, start, k - start);
		if (splited[row++] == 0)
			return (ft_freelist(splited));
	}
	return (splited);
}

char	**ft_split(char *s, char c)
{
	char	**splited;
	size_t	rows;

	if (s == NULL)
		return (NULL);
	rows = wc(s, c);
	splited = ft_calloc(sizeof(char *), (rows + 1));
	if (splited == NULL)
		return (NULL);
	return (spliter(splited, s, rows, c));
}
