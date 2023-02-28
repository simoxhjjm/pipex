/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:41:12 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/26 10:48:33 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../pipex_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tmp;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	tmp = malloc(count * size);
	if (tmp == NULL)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
