/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:48:07 by bsaiago-          #+#    #+#             */
/*   Updated: 2024/01/24 13:11:39 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_str(char **str)
{
	free(*str);
	(*str) = NULL;
	return (NULL);
}

static char	*read_file(int fd, char *storage)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free_str(&storage));
	buffer[0] = NULL_CHARACTER;
	while (read_bytes > 0 && !(ft_strchr(buffer, LINE_BREAK)))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = NULL_CHARACTER;
			storage = ft_strjoin(storage, buffer);
			if (!storage)
				return (free_str(&buffer));
		}
	}
	free(buffer);
	if (read_bytes == ERROR)
		return (free_str(&storage));
	return (storage);
}

static char	*get_line_storage(char *storage)
{
	char	*line;
	char	*aux;
	int		len;

	aux = ft_strchr(storage, LINE_BREAK);
	if (!aux)
		aux = ft_strchr(storage, NULL_CHARACTER);
	len = (aux - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*update_storage(char *storage)
{
	char	*new_storage;
	char	*aux;
	int		len_line;

	aux = ft_strchr(storage, LINE_BREAK);
	if (!aux)
		return (free_str(&storage));
	len_line = (aux - storage) + 1;
	if (storage[len_line] == NULL_CHARACTER)
		return (free_str(&storage));
	new_storage = ft_substr(storage, len_line, ft_strlen(storage) - len_line);
	free_str(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage || (storage && !ft_strchr(storage, LINE_BREAK)))
		storage = read_file(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line_storage(storage);
	if (!line)
		return (free_str(&storage));
	storage = update_storage(storage);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd = open("giant_line.txt", O_RDONLY);
    if (!fd)
        return (ERROR);
    char *s = get_next_line(fd);
    while (s != NULL)
    {
        printf("%s", s);
        free(s);
        s = get_next_line(fd);
	}
}
*/
