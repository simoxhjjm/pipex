/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:25:04 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/24 19:11:32 by melhajja         ###   ########.fr       */
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

// int	slash(char **cmd)
// {
// 	if (ft_strchr(cmd[0], '/') == 1 && access(cmd[0], X_OK) == -1)
// 	{
// 		write(2, cmd[0], ft_strlen(cmd[0]));
// 		write(2, ": No such file or directory\n", 29);
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (ft_strchr(cmd[0], '/') == 1 && access(cmd[0], X_OK) == 0)
// 		return (3);
// 	return (0);
// }

// void	midd_child(char *cmd1, char **envp, int fd[], int save_fd)
// {
// 	char	**args;
// 	char	*cmd_path;
// 	char	**paths;

// 	paths = get_paths(envp);
// 	args = ft_split(cmd1, ' ');
// 	if (slash(args) == 3)
// 		cmd_path = args[0];
// 	else
// 		cmd_path = check_command(cmd1, paths);
// 	//close(fd[0]);
// 	fail_cheack(dup2(save_fd, STDIN_FILENO), "dup2 failed");
// 	fail_cheack(dup2(fd[1], STDOUT_FILENO), "dup2 failed");
// 	close(fd[1]);
// 	fail_cheack(execve(cmd_path, args, envp), "execve failed");
// 	exit(0);
// }
// void    the_executer(int ac, char **av, char **envp, int fdd[]){
//     int fd[2];
//     int save_fd;
//     int count;
// 	int pid;

//     count = 2;
//     save_fd = fdd[0];
//     while(++count < ac -2){
// 		// if (count == 4)
// 		// 	close(f1);
//         // if(count != 3){
//         //     dup2(save_fd, STDIN_FILENO);
//         // }
//         pipe(fd);
//         pid = fork();
//         if(pid == 0){
//             close(fd[0]);
//             midd_child(av[count], envp, fd, save_fd);
//         }
//         else{
//             // if (count != 3)
//             close(save_fd);
//             save_fd = fd[0];
//             waitpid(pid, NULL, 0);
//         }
//     }
// }
// //
// #include "./get_next_line/get_next_line.h"
// #include "pipex.h"
// #include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// //============================================================
// static int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	if (n == 0)
// 		return (0);
// 	i = 0;
// 	while ((s1[i] || s2[i]) && i < n)
// 	{
// 		if (s1[i] != s2[i])
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		i++;
// 	}
// 	if (s1[i] == '\n')
// 		return (0);
// 	return (1);
// }
// //==============================================================

// void	here_doc(char *limiter)
// {
// 	char	*line;
// 	int		fd[2];

// 	if (pipe(fd) == -1)
// 		write(1, "hellohhhhhhhhhh", 17);
// 	//line = NULL;
// 	while (1)
// 	{
// 		write(1, "heredoc> ", 9);
// 		line = get_next_line(0);
// 		if (!line || !ft_strncmp(line, limiter, ft_strlen(limiter))) //line
// 		{
// 			free(line);
// 			break ;
// 		}
// 		write(fd[1], line, ft_strlen(line));
// 		free(line);
// 	}
// }

// int main(){
//     here_doc("end");
// }
// int	main(int ac, char **av, char **envp)
// {
// 	int	fd[2];
// 	int	pid1;
// 	int	pid2;

// 	if (ac == 5)
// 	{
// 		fail_cheack(pipe(fd), "pipe failed");
// 		pid1 = fork();
// 		fail_cheack(pid1, "fork failed");
// 		if (pid1 == 0)
// 			child1(av[1], av[2], envp, fd);
// 		pid2 = fork();
// 		fail_cheack(pid2, "fork failed");
// 		if (pid2 == 0)
// 			child2(av[4], av[3], envp, fd);
// 		close(fd[1]);
// 		close(fd[0]);
// 		waitpid(pid1, NULL, 0);
// 		waitpid(pid2, NULL, 0);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 		errprint();
// }

// int	open_file(char *file_name, int status)
// {
// 	int	fpid;

// 	if (status == 0)
// 		fpid = open(file_name, O_RDONLY);
// 	else
// 		fpid = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if (fpid == -1)
// 	{
// 		perror("open failed : ");
// 		exit(1);
// 	}
// 	return (fpid);
// }

// void	midd_child(char *cmd1, char **envp, int fd[], int save_fd)
// {
// 	char	**args;
// 	char	*cmd_path;
// 	char	**paths;

// 	paths = get_paths(envp);
// 	args = ft_split(cmd1, ' ');
// 	if (slash(args) == 3)
// 		cmd_path = args[0];
// 	else
// 		cmd_path = check_command(cmd1, paths);
// 	fail_cheack(dup2(save_fd, STDIN_FILENO), "dup2 failed");
// 	close(save_fd);
// 	fail_cheack(dup2(fd[1], STDOUT_FILENO), "dup2 failed");
// 	close(fd[1]);
// 	fail_cheack(execve(cmd_path, args, envp), "execve failed");
// 	exit(1);
// }
// void	create_pipe(int *fd)
// {
// 	if (pipe(fd) == -1)
// 	{
// 		perror("pipe");
// 		exit(1);
// 	}
// }

// void	last_child(char *outfile, char *cmd2, char **envp, int fd)
// {
// 	char	**args;
// 	int		fpid;
// 	char	*cmd_path;
// 	char	**paths;

// 	paths = get_paths(envp);
// 	fpid = open_file(outfile, 2);
// 	args = ft_split(cmd2, ' ');
// 	if (slash(args) == 3)
// 		cmd_path = args[0];
// 	else
// 		cmd_path = check_command(cmd2, paths);
// 	fail_cheack(dup2(fd, STDIN_FILENO), "dup2 failed");
// 	close(fd);
// 	fail_cheack(dup2(fpid, STDOUT_FILENO), "dup2 failed");
// 	close(fpid);
// 	fail_cheack(execve(cmd_path, args, envp), "execve failed");
// }

// void	exec_last_child(char **av, int ac, char **envp, int save_fd)
// {
// 	int	pid;

// 	pid = fork();
// 	if (pid == 0)
// 		last_child(av[ac - 1], av[ac - 2], envp, save_fd);
// 	close(save_fd);
// 	waitpid(pid, NULL, 0);
// }
// //=====================================================================

// void	midd_child(char *cmd1, char **envp, int fd[], int save_fd)
// {
// 	char	**args;
// 	char	*cmd_path;
// 	char	**paths;

// 	paths = get_paths(envp);
// 	args = ft_split(cmd1, ' ');
// 	if (slash(args) == 3)
// 		cmd_path = args[0];
// 	else
// 		cmd_path = check_command(cmd1, paths);
// 	fail_cheack(dup2(save_fd, STDIN_FILENO), "dup2 failed-1");
// 	close(save_fd);
// 	fail_cheack(dup2(fd[1], STDOUT_FILENO), "dup2 failed-2");
// 	close(fd[1]);
// 	fail_cheack(execve(cmd_path, args, envp), "execve failed");
// }

// void	exec_midd_child(char *cmd, char **envp, int *fd, int save_fd)
// {
// 	int	pid;

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		midd_child(cmd, envp, fd, save_fd);
// 		exit(1);
// 	}
// 	close(save_fd);
// 	close(fd[1]);
// 	waitpid(pid, NULL, 0);
// }
// //====================================================================

// void	multiple_pipes(char *filename, int ac, char **av, char **envp)
// {
// 	int	count;
// 	int	save_fd;
// 	int	fd[2];

// 	count = 1;
// 	save_fd = open_file(filename, 0);
// 	while (++count < ac - 1)
// 	{
// 		fail_cheack(pipe(fd), "pipe failed");
// 		if (count == ac - 2)
// 			exec_last_child(av, ac, envp, save_fd);
// 		else
// 		{
// 			exec_midd_child(av[count], envp, fd, save_fd);
// 			save_fd = fd[0];
// 		}
// 	}
// }
// void	multiple_pipes(char *filename, int ac, char **av, char **envp)
// {
// 	int	count;
// 	int	save_fd;
// 	int	fd[2];

// 	// int	pid;
// 	count = 1;
// 	save_fd = open_file(filename, 0);
// 	while (++count < ac - 1)
// 	{
// 		fail_cheack(pipe(fd), "pipe failed");
// 		if (count == ac - 2)
// 		{
// 			exec_last_child(av, ac, envp, save_fd);
// 			// pid = fork();
// 			// if (pid == 0)
// 			// 	last_child(av[ac - 1], av[ac - 2], envp, save_fd);
// 			// close(save_fd);
// 			// waitpid(pid, NULL, 0);
// 		}
// 		else
// 		{
// 			exec_midd_child(av[count], envp, fd, save_fd);
// 			save_fd = fd[0];
// 			// pid = fork();
// 			// if (pid == 0)
// 			// {
// 			// 	close(fd[0]);
// 			// 	midd_child(av[count], envp, fd, save_fd);
// 			// 	exit(1);
// 			// }
// 			// close(save_fd);
// 			// close(fd[1]);
// 			// save_fd = fd[0];
// 			// waitpid(pid, NULL, 0);
// 		}
// 	}
// }

// int	main(int ac, char **av, char **envp)
// {
// 	// int	fd[2];
// 	// int	pid1;
// 	// int	pid2;

// 	if (ac >= 5)
// 	{
// 		multiple_pipes(av[1], ac, av, envp); // add exit after execve
// 		// fail_cheack(pipe(fd), "pipe failed");
// 		// pid1 = fork();
// 		// fail_cheack(pid1, "fork failed");
// 		// if (pid1 == 0)
// 		// 	child1(av[1], av[2], envp, fd);
// 		// //close(fd[0]);
// 		// printf("child111111\n");
// 		// // close(fd[1]);
// 		// //dup2(fd[0], STDIN_FILENO);
// 		// the_executer(ac, av, envp, fd);
// 		// printf("ddddddd\n");
// 		// multiple_pipes(av[1], ac, av, envp);
// 		// pid2 = fork();
// 		// fail_cheack(pid2, "fork failed");
// 		// if (pid2 == 0)
// 		// 	child2(av[4], av[3], envp, fd);
// 		// printf("child2\n");
// 		// printf("wsal");
// 		// close(fd[1]);
// 		// close(fd[0]);
// 		// waitpid(pid1, NULL, 0);
// 		// waitpid(pid2, NULL, 0);
// 		// printf("tal lakher");
// 		//system("pipex leaks");
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 		errprint();
// }