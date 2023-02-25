/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:37:55 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/25 16:47:00 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*dest;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	// if (!s1 || !s2)
// 	// 	return (NULL);
// 	if (!s1)
// 		s1 = ft_strdup("");
// 	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (dest == NULL)
// 		return (0);
// 	while (s1[i])
// 		dest[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		dest[j++] = s2[i++];
// 	dest[j] = '\0';
// 	free(s1);
// 	return (dest);
// }
char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_strdup("");
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dest == NULL)
		return (0);
	while (s1[i])
		dest[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}
