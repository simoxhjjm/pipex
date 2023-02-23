/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:31:32 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/23 07:52:46 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "pipex_bonus.h"
#include "./get_next_line/get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "pipex.h"
//============================================================
int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
//==============================================================
void	here_doc(char *limiter)
{
	char	*storage;
	char	*line;
	 int		fd[2];
	// char	*ss = NULL;

    if (pipe(fd) == -1)
        write(1,"hellohhhhhhhhhh", 17);
    storage = NULL;
    line = NULL;
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!ft_strncmp(line, limiter, ft_strlen(limiter)) || !line)
        {
            free (line);
			break ;
        }
        write(fd[1], line, ft_strlen(line));
		free(line);
	}
    printf("-%s", storage);
	// if (pipe(fd) == -1)
	// 	write(2, "pipe failed", 12);
	// close(fd[0]);
	// write(fd[1], storage, ft_strlen(storage));
    // read(fd[0], ss, ft_strlen(storage));
}

int main(){
    here_doc("end");
}
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

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
 * loop over commands by sharing
 * pipes.
 */
static void
pipeline(char ***cmd)
{
	int fd[2];
	pid_t pid;
	int fdd = 0;				/* Backup */

	while (*cmd != NULL) {
		pipe(fd);				/* Sharing bidiflow */
		if ((pid = fork()) == -1) {
			perror("fork");
			exit(1);
		}
		else if (pid == 0) {
			dup2(fdd, 0);
			if (*(cmd + 1) != NULL) {
				dup2(fd[1], 1);
			}
			close(fd[0]);
			execvp((*cmd)[0], *cmd);
			exit(1);
		}
		else {
			wait(NULL); 		/* Collect childs */
			close(fd[1]);
			fdd = fd[0];
			cmd++;
		}
	}
}

/*
 * Compute multi-pipeline based
 * on a command list.
 */
int
main(int argc, char *argv[])
{
	char *ls[] = {"ls", "-al", NULL};
	char *rev[] = {"rev", NULL};
	char *nl[] = {"nl", NULL};
	char *cat[] = {"cat", "-e", NULL};
	char **cmd[] = {ls, rev, nl, cat, NULL};

	pipeline(cmd);
	return (0);
}