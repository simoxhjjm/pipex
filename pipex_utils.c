/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:24:01 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/21 14:19:50 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fail_cheack(int status, char *message)
{
	if (status == -1)
	{
		perror(message);
		exit(EXIT_FAILURE);
	}
}

void	errprint(void)
{
	write(2, "Usage: ./pipex file1 cmd1 cmd2 file2", 36);
	exit(1);
}
