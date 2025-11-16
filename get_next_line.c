/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:35:24 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/16 10:27:03 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <strings.h>

void	*ft_calloc(size_t size, size_t nb)
{
	void	*result;
	size_t	i;

	if (size == 0 || nb == 0)
		return (NULL);
	if (size > (size_t) - 1 / nb)
		return (NULL);
	result = malloc(size * nb);
	if (!result)
		return (NULL);
	i = 0;
	while (i < (size * nb))
		((unsigned char*)result)[i++] = 0;
	return (result);
}

size_t	count_to_nl(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*get_read_line(int fd, char *s_line)
{
	char	*buf;
	char	*result;
	ssize_t	bytes_read;

	if (s_line)
		result = s_line;
	else if (!s_line)
	{
		result = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!result)
			return (NULL);
	}
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buf, '\n'))
	{
		//attention bzero
		bzero(buf, BUFFER_SIZE);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf);
			if (!s_line)
				free(result);
			return (NULL);
		}
		result = ft_strjoin(result, buf);
		if(!result)
		{
			free (buf);
			free (result);
			return (NULL);
		}
	}
	free(buf);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*s_line = {0};
	char		*result;
	char		*line;
	size_t		count_n;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = get_read_line(fd, s_line);
	if (!line)
	{
		if (s_line)
			free(s_line);
		s_line = NULL;
		return (NULL);
	}
	count_n = count_to_nl(line);
	result = ft_strndup(line, count_n);
	if (count_n == 0)
	{
		free(result);
		result = NULL;
	}
	len = ft_strlen(line) - (count_n);
	s_line = ft_substr(line, count_n, len);
	if (len == 0)
	{
		free(s_line);
		s_line = NULL;
	}
	free(line);
	return (result);
}
