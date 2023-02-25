/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:32:37 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/25 15:49:27 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

//--------utils---------//
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strnstr(char *haystack, char *needle);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
void	*ft_memset(void *b, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_strchr(char *s, int c);
//----------------BNS------------------//
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		open_file(char *file_name, int status);
void	multiple_pipes(int ac, char **av, char **envp);
char	**get_paths(char **envp);
char	*check_command(char *arg, char **paths);
void	fail_cheack(int status, char *message);
int		slash(char **cmd);
void	fail_cheack(int status, char *message);
void	exec_heredoc(char **av, char **envp);
void	ft_print_notfound(void);

// # include <errno.h>
// # include <fcntl.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <sys/wait.h>
// # include <unistd.h>

// //--------utils---------//
// char	**ft_split(char *s, char c);
// void	*ft_calloc(size_t count, size_t size);
// char	*ft_substr(char *s, unsigned int start, size_t len);
// int		ft_strnstr(char *haystack, char *needle);
// size_t	ft_strlen(char *s);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strdup(char *s1);
// void	*ft_memset(void *b, int c, size_t n);
// void	ft_bzero(void *s, size_t n);
// int		ft_strchr(char *s, int c);
// //--------------------------------//
// char	**get_paths(char **envp);
// void	child2(char *outfile, char *cmd2, char **envp, int fd[2]); // zayd
// void	child1(char *infile, char *cmd1, char **envp, int fd[2]); // zayd
// char	*check_command(char *arg, char **paths);
// void	fail_cheack(int status, char *message); // bdl smia
// void	errprint(void);
// int		slash(char **cmd);

#endif

// #include "pipex.h"

// int main(){
//     int i = 2;
//     int pipefd[2];
//     int inpid = open("infile", O_RDONLY);
//     dup2(inpid, STDIN_FILENO);

//     execve(); // first commnd
//     //==========================================================
//     // middle
//     // ./pipex_bonus infile cmd1 cmd2 cmd3 cmd4 outfile
//     while (i < ac - 2){
//
// if i == 2 thats mean take the file as stdinput --- i > 2 read from pipe
//         if (i == 2){
//             // use 2 pipes
//             dup2(inpid, STDIN_FILENO);
//             pipe(pipefd);
//             close(pipefd[0]);
//             dup2(pipefd[1], STDOUT_FILENO);
//             execve();
//         }
//         else
//         {

//         }
//     }
//     //last command
//     int outpid = open(outpid, O_WRONLY | O_CREAT | O_TRUNC, 0777);
//     dup2(outpid, STDOUT_FILENO);
//     execve() // last command
// }
