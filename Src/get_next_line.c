#include "../Includes/get_next_line.h"
#include <stdio.h>

char	*read_file(int fd, char *storage)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = NULL_CHARACTER;
	while (read_bytes > 0 && !(ft_strchr(buffer, LINE_BREAK)))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = NULL_CHARACTER;
			storage = ft_strjoin(storage, buffer);
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

char	*get_line_storage(char *storage)
{
	char	*aux;
	char	*line;
    int     i;
	int		len;

	aux = ft_strchr(storage, LINE_BREAK);
    if (!aux)
        return (NULL);
    len = 0;
    while (aux[len] && aux[len] != LINE_BREAK)
    {
        len++; 
    }
	line = ft_substr(storage, 0, len + 2);
	if (!line)
		return (NULL);
	return (line);
}

char	*update_storage(char *storage)
{
	char	*new_storage;
	char	*str;
	int		len_first_line;

	str = ft_strchr(storage, LINE_BREAK);
	if (!str)
	{
        free(storage);
		return (NULL);
	}
    len_first_line = 0;
    while (str[len_first_line] && str[len_first_line] != LINE_BREAK)
        len_first_line++;
	len_first_line++;
    if (storage[len_first_line] == NULL_CHARACTER)
    {
        free(storage);
        return (NULL);
    }
	new_storage = ft_substr(storage, len_first_line, ft_strlen(storage) - len_first_line);
	free(storage);
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
	storage = read_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = get_line_storage(storage);
	if (!line)
    {
        free(storage);
		return (NULL);
    }
	storage = update_storage(storage);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd = open("file.txt", O_RDONLY);
    if (!fd)
        return (ERROR);
    char *s = get_next_line(fd);
    while (s != NULL)
    {
        printf("%s", s);
        free(s);
        s = get_next_line(fd);
    }
    printf("%s", s);
    return (0);
}