/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:41:36 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/26 10:44:12 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../pipex_bonus.h"

char	*ft_strdup(char *s1)
{
	char	*dest;
	int		i;

	i = -1;
	dest = malloc(ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	dest[i] = '\0';
	return (dest);
}
