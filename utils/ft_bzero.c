/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:49:38 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/26 10:43:38 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "../pipex_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
