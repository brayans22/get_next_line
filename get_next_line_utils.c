/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaiago- <bsaiago-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:58:52 by bsaiago-          #+#    #+#             */
/*   Updated: 2023/10/01 18:55:05 by bsaiago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub = (char *)malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = NULL_CHARACTER;
		return (sub);
	}
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[start] && i < len)
		sub[i++] = s[start++];
	sub[i] = NULL_CHARACTER;
	return (sub);
}

static char	*get_strjoin(char *s1, char *s2, size_t len_s1, size_t len_s2)
{
	int		i;
	int		j;
	char	*new_str;

	new_str = (char *)malloc(len_s1 + len_s2 + 1);
	if (!new_str)
		return (free_str(&s1));
	i = -1;
	j = 0;
	while (s1[++i])
		new_str[i] = s1[i];
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[len_s1 + len_s2] = NULL_CHARACTER;
	free(s1);
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len_s1;
	size_t	len_s2;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = NULL_CHARACTER;
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	return (get_strjoin(s1, s2, len_s1, len_s2));
}
