/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 10:39:34 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/25 14:18:56 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
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
//--------------------------------//
char	**get_paths(char **envp);
void	child2(char *outfile, char *cmd2, char **envp, int fd[2]);
void	child1(char *infile, char *cmd1, char **envp, int fd[2]);
char	*check_command(char *arg, char **paths);
void	fail_cheack(int status, char *message);
void	errprint(void);
int		slash(char **cmd);
int		open_file(char *file_name, int status);
void	print_notfound(void);

#endif