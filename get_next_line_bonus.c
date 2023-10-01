/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:56:25 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/10/01 18:50:42 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
static char	*read_file(int fd, char *storage)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer){
		free(storage);
		return (NULL);
	}
	buffer[0] = NULL_CHARACTER;
	while (read_bytes > 0 && !(ft_strchr(buffer, LINE_BREAK)))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = NULL_CHARACTER;
			storage = ft_strjoin(storage, buffer);
			if(!storage)
			{
				free(buffer);
				return NULL;
			}
		}
	}
	free(buffer);
	if (read_bytes == ERROR)
	{
		free(storage);
		return (NULL);
	}
	return (storage);
}

static char	*get_line_storage(char *storage)
{
	char	*line;
	char	*aux;
	int		len;

	if (!storage)
		return (NULL);
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
	{
		free(storage);
		return (NULL);
	}
	len_line = (aux - storage) + 1;
	if (storage[len_line] == NULL_CHARACTER)
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_substr(storage, len_line, ft_strlen(storage) - len_line);
	free(storage);
	return (new_storage);
}


char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage[fd] = read_file(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = get_line_storage(storage[fd]);
	if (!line)
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	storage[fd] = update_storage(storage[fd]);
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd = open("file.txt", O_RDONLY);
    if (!fd)
        return (ERROR);
    int fd2 = open("file2.txt", O_RDONLY);
    if (!fd2)
    {
	close(fd);
 	return (NULL);
    }
    char *s_fd = get_next_line(fd);
    while (s_fd != NULL)
    {
        printf("%s", s_fd);
        free(s_fd);
        s_fd = get_next_line(fd);
	}
 char *s_fd2 = get_next_line(fd2);
    while (s_fd2 != NULL)
    {
        printf("%s", s);
        free(s_fd2);
        s_fd2 = get_next_line(fd2);
	}
*/
