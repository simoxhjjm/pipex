/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:31:32 by melhajja          #+#    #+#             */
/*   Updated: 2023/03/14 13:42:06 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_print_notfound(void)
{
	write(2, "command not found\n", 18);
	exit(127);
}

void	print_error(char *cmd)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, " :command not found\n", 20);
	exit(127);
}

int	main(int ac, char **av, char **envp)
{
	int	status;

	status = 0;
	if (!ft_strncmp(av[1], "here_doc", 8) && ac == 6)
	{
		status = exec_heredoc(av, envp);
	}
	else if (ac >= 5)
	{
		status = multiple_pipes(ac, av, envp);
	}
	else
	{
		write(2, "you should use one of the two in bonus part\n", 44);
		write(2, "1--> ./pipex here_doc LIMITER cmd cmd1 file\n", 44);
		write(2, "2--> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", 49);
	}
	while (wait(NULL) != -1)
		;
	return (status);
}
