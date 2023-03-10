/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:39:40 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/28 10:29:27 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp, char *args)
{
	int		i;
	char	**paths;
	char	*tmp;

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=") > 0)
			break ;
	}
	if (envp[i] == NULL)
	{
		write(2, args, ft_strlen(args));
		write(2, " :command not found\n", 21);
		exit(127);
	}
	tmp = ft_substr(envp[i], 5, ft_strlen(envp[i]));
	paths = ft_split(tmp, ':');
	free(tmp);
	return (paths);
}

char	*check_command(char *arg, char **paths)
{
	char	**command;
	char	*exec;
	char	*check;
	int		i;

	i = -1;
	command = ft_split(arg, ' ');
	exec = ft_strjoin("/", command[0]);
	while (paths[++i])
	{
		check = ft_strjoin(paths[i], exec);
		if (access(check, X_OK) == 0)
			break ;
		free(check);
		check = NULL;
	}
	free(command);
	free(exec);
	if (check == NULL)
		print_error(arg);
	return (check);
}
//check slash in command
//---------------------------------------------------------------------

int	slash(char **cmd)
{
	if (ft_strchr(cmd[0], '/') == 1 && access(cmd[0], X_OK) == -1)
	{
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, ": No such file or directory\n", 29);
		exit(127);
	}
	else if (ft_strchr(cmd[0], '/') == 1 && access(cmd[0], X_OK) == 0)
		return (3);
	return (0);
}
//---------------------------------------------------------------------
// child1

void	child1(char *infile, char *cmd1, char **envp, int fd[])
{
	char	**args;
	char	*cmd_path;
	int		fpid;
	char	**paths;

	if (cmd1[0] == '\0')
		print_notfound(cmd1, 0);
	else
	{
		args = ft_split(cmd1, ' ');
		paths = get_paths(envp, args[0]);
		if (slash(args) == 3)
			cmd_path = args[0];
		else
			cmd_path = check_command(cmd1, paths);
		ft_free(paths);
		close(fd[0]);
		fpid = open_file(infile, 0);
		err_check(dup2(fpid, STDIN_FILENO), "dup2 failed");
		close(fpid);
		err_check(dup2(fd[1], STDOUT_FILENO), "dup2 failed");
		close(fd[1]);
		err_check(execve(cmd_path, args, envp), "execve failed");
	}
}
//child2

void	child2(char *outfile, char *cmd2, char **envp, int fd[])
{
	char	**args;
	int		fpid;
	char	*cmd_path;
	char	**paths;

	if (cmd2[0] == '\0')
		print_notfound(cmd2, 0);
	else
	{
		fpid = open_file(outfile, 1);
		args = ft_split(cmd2, ' ');
		paths = get_paths(envp, args[0]);
		if (slash(args) == 3)
			cmd_path = args[0];
		else
			cmd_path = check_command(cmd2, paths);
		ft_free(paths);
		err_check(dup2(fd[0], STDIN_FILENO), "dup2 failed");
		close(fd[0]);
		close(fd[1]);
		err_check(dup2(fpid, STDOUT_FILENO), "dup2 failed");
		close(fpid);
		err_check(execve(cmd_path, args, envp), "execve failed");
	}
}
