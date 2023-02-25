/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:31:32 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/25 15:50:08 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_print_notfound(void)
{
	write(2, "command not found\n", 19);
	exit(1);
}

int	main(int ac, char **av, char **envp)
{
	if (!ft_strncmp(av[1], "here_doc", 8) && ac == 6)
	{
		exec_heredoc(av, envp);
	}
	else if (ac >= 5)
	{
		multiple_pipes(ac, av, envp);
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(2, "you should use one of the two in bonus part\n", 44);
		write(2, "1--> ./pipex here_doc LIMITER cmd cmd1 file\n", 44);
		write(2, "2--> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n", 49);
	}
}
