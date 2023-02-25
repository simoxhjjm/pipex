/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:31:56 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/24 20:26:06 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

char	**get_paths(char **envp)
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
		write(2, "PATH= not found\n", 15);
		exit(EXIT_FAILURE);
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
	free(paths);
	free(command);
	free(exec);
	if (check == NULL)
	{
		perror("command not found");
		exit(EXIT_FAILURE);
	}
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
		//exit(EXIT_FAILURE);
	}
	else if (ft_strchr(cmd[0], '/') == 1 && access(cmd[0], X_OK) == 0)
		return (3);
	return (0);
}

void	fail_cheack(int status, char *message)
{
	if (status == -1)
	{
		perror(message);
		exit(EXIT_FAILURE);
	}
}
