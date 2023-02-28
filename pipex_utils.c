/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:24:01 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/27 18:32:28 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	err_check(int status, char *message)
{
	if (status == -1)
	{
		perror(message);
		exit(errno);
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
		write(2, file_name, ft_strlen(file_name));
		perror(" ");
		exit(1);
	}
	return (fpid);
}

void	print_notfound(char *cmd, int status)
{
	if (status == 1)
	{
		write(2, cmd, ft_strlen(cmd));
		write(2, "command not found\n", 18);
	}
	else
	{
		(void)cmd;
		write(2, "command not found\n", 18);
	}
	exit(127);
}

void	print_error(char *cmd)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, " :command not found\n", 20);
	exit(127);
}
