/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_multiple_pipes_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:03:15 by melhajja          #+#    #+#             */
/*   Updated: 2023/03/13 10:02:54 by melhajja         ###   ########.fr       */
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
		ft_print_notfound();
	else
	{
		fpid = open_file(outfile, 2);
		args = ft_split(cmd2, ' ');
		paths = get_paths(envp, args[0]);
		if (slash(args) == 3)
			cmd_path = args[0];
		else
			cmd_path = check_command(cmd2, paths);
		ft_free(paths);
		err_check(dup2(fd, STDIN_FILENO), "dup2 failed");
		close(fd);
		err_check(dup2(fpid, STDOUT_FILENO), "dup2 failed");
		close(fpid);
		err_check(execve(cmd_path, args, envp), "execve failed");
	}
}

int	exec_last_child(char **av, int ac, char **envp, int save_fd)
{
	int	pid;
	int	status;

	status = 0;
	pid = fork();
	if (pid == 0)
		last_child(av[ac - 1], av[ac - 2], envp, save_fd);
	close(save_fd);
	//waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

void	midd_child(char *cmd1, char **envp, int fd[], int save_fd)
{
	char	**args;
	char	*cmd_path;
	char	**paths;

	if (cmd1[0] == '\0')
		ft_print_notfound();
	else
	{
		if (save_fd == -1)
		{
			exit(1);
		}
		args = ft_split(cmd1, ' ');
		paths = get_paths(envp, args[0]);
		if (slash(args) == 3)
			cmd_path = args[0];
		else
			cmd_path = check_command(cmd1, paths);
		ft_free(paths);
		err_check(dup2(save_fd, STDIN_FILENO), "dup2 failed");
		close(save_fd);
		err_check(dup2(fd[1], STDOUT_FILENO), "dup2 failed");
		close(fd[1]);
		err_check(execve(cmd_path, args, envp), "execve failed");
	}
}

int	exec_midd_child(char *cmd, char **envp, int *fd, int save_fd)
{
	int	pid;
	int	status;

	status = 0;
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		midd_child(cmd, envp, fd, save_fd);
	}
	close(save_fd);
	close(fd[1]);
	// waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

int	multiple_pipes(int ac, char **av, char **envp)
{
	int	count;
	int	save_fd;
	int	fd[2];
	int	status;

	status = 0;
	count = 1;
	save_fd = open(av[1], O_RDONLY);
	if (save_fd == -1)
	{
		write(2, av[1], ft_strlen(av[1]));
		perror(" ");
	}
	while (++count < ac - 1)
	{
		if (count == ac - 2)
			status = exec_last_child(av, ac, envp, save_fd);
		else
		{
			err_check(pipe(fd), "pipe failed");
			status = exec_midd_child(av[count], envp, fd, save_fd);
			save_fd = fd[0];
		}
	}
	return (status);
}
