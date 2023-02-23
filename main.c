/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:25:04 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/21 14:28:44 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (ac == 5)
	{
		fail_cheack(pipe(fd), "pipe failed");
		pid1 = fork();
		fail_cheack(pid1, "fork failed");
		if (pid1 == 0)
			child1(av[1], av[2], envp, fd);
		pid2 = fork();
		fail_cheack(pid2, "fork failed");
		if (pid2 == 0)
			child2(av[4], av[3], envp, fd);
		close(fd[1]);
		close(fd[0]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
		exit(EXIT_SUCCESS);
	}
	else
		errprint();
}
