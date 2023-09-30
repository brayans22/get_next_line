#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* MACROS */
/* 
Si no se define un buffer al compilar
se agrega este valor por defecto.
*/
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 420000
#endif

/* INCLUDES */
#include <stdlib.h>
#include <unistd.h>

/* CONSTANTS */
#define ERROR           -1
#define END_OF_FILE     0
#define LINE_BREAK      '\n'
#define NULL_CHARACTER  '\0'

/* PROTOTYPE FUNCTIONS */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);

/* STRUCT */
typedef struct s_list
{
    char    *last_line;
    char    *next_line;
    size_t  bytes_reads;
}t_list;

#endif