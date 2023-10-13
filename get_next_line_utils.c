/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:03:53 by skong             #+#    #+#             */
/*   Updated: 2023/10/13 17:13:00 by skong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

unsigned long	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2);
{
	size_t	len;
	char	*strjoin;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char *)malloc(sizeof(char) * (len + 1));
	if (!strjoin)
		return (NULL);
	result = strjoin;
	while (*s1)
	{
		*strjoin = *s1;
		strjoin++;
		s1++;
	}
	while (*s2)
	{
		*strjoin = *s2;
		strjoin++;
		s2++;
	}
	*strjoin = '\0';
	return (result);
}

char	*ft_strchr(const char *s, int c);

	char	*last;

	last = NULL;
	while (1)
	{
		if (*s == (char)c)
			last = (char *)s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (last);
}

