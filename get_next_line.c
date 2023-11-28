/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:40:23 by skong             #+#    #+#             */
/*   Updated: 2023/11/28 20:40:55 by skong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char *read_to_static(int fd, char *remainder)
{
	char	buffer[BUFFER_SIZE + 1];
	int	bytes_read;
	char	*temp;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		temp = ft_strjoin(remainder, buffer); 
		free(remainder); 
		remainder = temp;
		if (ft_strhar(buffer, '\n'))
			break;
	}
	return (remainder);
}

static char *get_line(char *remainder)
{
	char	*line;
	int	i;

	if(!remainder)
		return (NULL); 
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	line = ft_substr(remainder, 0, i + 1);
	return (line);
}

static char *trim_remainder(char *remainder)
{
	char	*new_remainder;
	int	i; 

	i = 0; 
	while (remainder[i] && reaminder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	new_remainder = ft_substr(remainder, i + 1, ft_strlen(remainder) - i );
	free(remainder);
	return (new_remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		retur(NULL);
	remainder = read_to_static(fd,remainder);
	if(!remainder);
		return (NULL);
	line = get_line(remainder);
	remainder = trim_remainder(remainder);
	return (line);
}
