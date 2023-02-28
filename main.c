/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:25:04 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/28 10:29:45 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	status;

	status = 0;
	if (ac == 5)
	{
		err_check(pipe(fd), "pipe failed");
		pid1 = fork();
		err_check(pid1, "fork failed");
		if (pid1 == 0)
			child1(av[1], av[2], envp, fd);
		pid2 = fork();
		err_check(pid2, "fork failed");
		if (pid2 == 0)
			child2(av[4], av[3], envp, fd);
		close(fd[1]);
		close(fd[0]);
		waitpid(pid1, &status, 0);
		waitpid(pid2, &status, 0);
		return (WEXITSTATUS(status));
	}
	else
		errprint();
}
