/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhajja <melhajja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:34:14 by melhajja          #+#    #+#             */
/*   Updated: 2023/02/24 17:07:59 by melhajja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_lines(int fd, char *store)
{
	ssize_t	read_bytes;
	char	*buffer;

	read_bytes = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (read_bytes > 0 && position(store) == -7)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			if (store)
				free(store);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		store = ft_str_join(store, buffer);
	}
	free(buffer);
	return (store);
}

char	*get_one_line(char *store)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	if (!*store)
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\n')
		i += 1;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	j = 0;
	while (store[i] && store[i] != '\n')
		line[j++] = store[i++];
	if (store[i] == '\n')
		line[j++] = store[i++];
	line[j] = '\0';
	return (line);
}

char	*ft_trim(char *store)
{
	char	*tmp;

	if (!*store)
	{
		free(store);
		return (NULL);
	}
	tmp = ft_ssubstr(store, position(store) + 1, ft_str_len(store));
	free(store);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	store = read_lines(fd, store);
	if (!store)
		return (NULL);
	line = get_one_line(store);
	store = ft_trim(store);
	return (line);
}
