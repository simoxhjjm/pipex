/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:34:10 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/24 17:07:30 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_str_join(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	i = 0;
	j = 0;
	dest = malloc(ft_str_len(s1) + ft_str_len(s2) + 1);
	if (dest == NULL)
		return (0);
	while (s1[j])
		dest[i++] = s1[j++];
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int	position(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-7);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (-7);
	return (i);
}

char	*ft_ssubstr(char *s, unsigned int start, unsigned int stop)
{
	char	*dest;
	int		i;

	i = 0;
	if (!*s)
	{
		free(s);
		return (NULL);
	}
	dest = malloc((stop - start) + 2);
	if (!dest)
		return (NULL);
	while (start < stop)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
