/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_multiple_pipes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:03:15 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/25 13:40:17 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	last_child(char *outfile, char *cmd2, char **envp, int fd)
{
	char	**args;
	int		fpid;
	char	*cmd_path;
	char	**paths;

	if (cmd2[0] == '\0')
	{
		write(2, "command not found\n", 19);
		exit(1);
	}
	else
	{
		paths = get_paths(envp);
		fpid = open_file(outfile, 2);
		args = ft_split(cmd2, ' ');
		if (slash(args) == 3)
			cmd_path = args[0];
		else
			cmd_path = check_command(cmd2, paths);
		fail_cheack(dup2(fd, STDIN_FILENO), "dup2 failed");
		close(fd);
		fail_cheack(dup2(fpid, STDOUT_FILENO), "dup2 failed");
		close(fpid);
		fail_cheack(execve(cmd_path, args, envp), "execve failed");
	}
}

void	exec_last_child(char **av, int ac, char **envp, int save_fd)
{
	int	pid;

	pid = fork();
	if (pid == 0)
		last_child(av[ac - 1], av[ac - 2], envp, save_fd);
	close(save_fd);
	waitpid(pid, NULL, 0);
}

void	midd_child(char *cmd1, char **envp, int fd[], int save_fd)
{
	char	**args;
	char	*cmd_path;
	char	**paths;

	if (cmd1[0] == '\0')
	{
		write(2, "command not found\n", 19);
		exit(1);
	}
	else
	{
		paths = get_paths(envp);
		args = ft_split(cmd1, ' ');
		if (slash(args) == 3)
			cmd_path = args[0];
		else
			cmd_path = check_command(cmd1, paths);
		fail_cheack(dup2(save_fd, STDIN_FILENO), "dup2 failed-1");
		close(save_fd);
		fail_cheack(dup2(fd[1], STDOUT_FILENO), "dup2 failed-2");
		close(fd[1]);
		fail_cheack(execve(cmd_path, args, envp), "execve failed");
	}
}

void	exec_midd_child(char *cmd, char **envp, int *fd, int save_fd)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		midd_child(cmd, envp, fd, save_fd);
	}
	close(save_fd);
	close(fd[1]);
	waitpid(pid, NULL, 0);
}

void	multiple_pipes(int ac, char **av, char **envp)
{
	int	count;
	int	save_fd;
	int	fd[2];

	count = 1;
	save_fd = open_file(av[1], 0);
	while (++count < ac - 1)
	{
		if (count == ac - 2)
			exec_last_child(av, ac, envp, save_fd);
		else
		{
			fail_cheack(pipe(fd), "pipe failed");
			exec_midd_child(av[count], envp, fd, save_fd);
			save_fd = fd[0];
		}
	}
}
