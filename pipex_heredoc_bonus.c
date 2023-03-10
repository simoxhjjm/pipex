/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:02:49 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/28 10:32:12 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line/get_next_line.h"
#include "pipex_bonus.h"

int	ft_strn_cmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] == '\n')
		return (0);
	return (1);
}

int	here_doc(char *limiter)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("pipe failed : ");
		exit(1);
	}
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line || !ft_strn_cmp(line, limiter, ft_strlen(limiter)))
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	return (fd[0]);
}

void	first_child(char **av, char **envp, int fd[], int fd_heredoc)
{
	char	**args;
	char	*cmd_path;
	char	**paths;

	if (av[3][0] == '\0')
		ft_print_notfound();
	else
	{
		args = ft_split(av[3], ' ');
		paths = get_paths(envp, args[0]);
		if (slash(args) == 3)
			cmd_path = args[0];
		else
			cmd_path = check_command(av[3], paths);
		ft_free(paths);
		close(fd[0]);
		err_check(dup2(fd_heredoc, STDIN_FILENO), "dup2 failed");
		close(fd_heredoc);
		err_check(dup2(fd[1], STDOUT_FILENO), "dup2 failed");
		close(fd[1]);
		err_check(execve(cmd_path, args, envp), "execve failed");
	}
}
//child2

void	last__child(char **av, char **envp, int fd[])
{
	char	**args;
	int		fpid;
	char	*cmd_path;
	char	**paths;

	if (av[4][0] == '\0')
		ft_print_notfound();
	else
	{
		fpid = open_file(av[5], 1);
		args = ft_split(av[4], ' ');
		paths = get_paths(envp, args[0]);
		if (slash(args) == 3)
			cmd_path = args[0];
		else
			cmd_path = check_command(av[4], paths);
		ft_free(paths);
		err_check(dup2(fd[0], STDIN_FILENO), "dup2 failed");
		close(fd[0]);
		close(fd[1]);
		err_check(dup2(fpid, STDOUT_FILENO), "dup2 failed");
		close(fpid);
		err_check(execve(cmd_path, args, envp), "execve failed");
	}
}

int	exec_heredoc(char **av, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	fd_heredoc;
	int	status;

	status = 0;
	err_check(pipe(fd), "pipe failed");
	fd_heredoc = here_doc(av[2]);
	pid1 = fork();
	err_check(pid1, "fork failed");
	if (pid1 == 0)
		first_child(av, envp, fd, fd_heredoc);
	close(fd_heredoc);
	pid2 = fork();
	err_check(pid2, "fork failed");
	if (pid2 == 0)
		last__child(av, envp, fd);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}
