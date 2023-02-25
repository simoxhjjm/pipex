/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:34:19 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/24 17:07:48 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		position(char *str);
size_t	ft_str_len(char *str);
char	*get_next_line(int fd);
char	*ft_str_join(char *s1, char *s2);
char	*ft_ssubstr(char *s, unsigned int start, unsigned int stop);

#endif
