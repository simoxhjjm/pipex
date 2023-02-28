/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:32:37 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/28 10:31:17 by melhajja         ###   ########.fr       */
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
int		multiple_pipes(int ac, char **av, char **envp);
char	**get_paths(char **envp, char *args);
char	*check_command(char *arg, char **paths);
void	err_check(int status, char *message);
int		slash(char **cmd);
void	err_check(int status, char *message);
int		exec_heredoc(char **av, char **envp);
void	print_error(char *cmd);
void	ft_print_notfound(void);
void	ft_free(char **str);

#endif