/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:24:01 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/25 14:18:26 by melhajja         ###   ########.fr       */
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

int	open_file(char *file_name, int status)
{
	int	fpid;

	if (status == 0)
		fpid = open(file_name, O_RDONLY);
	else
		fpid = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fpid == -1)
	{
		perror("open failed : ");
		exit(1);
	}
	return (fpid);
}

void	print_notfound(void)
{
	write(2, "command not found\n", 19);
	exit(1);
}
