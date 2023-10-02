/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:57:58 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/10/01 18:07:05 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* INCLUDES */
# include <stdlib.h>
# include <unistd.h>

/* MACRO BUFFER */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 420000000
# endif

/* CONSTANTS */
# define ERROR           -1
# define LINE_BREAK      '\n'
# define NULL_CHARACTER  '\0'
# define OPEN_MAX_FD     10240

/* PROTOTYPE FUNCTIONS */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);
char	*free_str(char **str);
#endif
