/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:35:24 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/18 10:45:22 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		((unsigned char *)result)[i++] = 0;
	return (result);
}

char	*ft_get_read_line(int fd, char *buf, char **next_line, char *tmp)
{
	ssize_t	bytes_read;
	int		need_to_free;

	bytes_read = 1;
	need_to_free = 0;
	while (bytes_read > 0 && !ft_strchr(buf, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buf[bytes_read] = '\0';
		tmp = ft_strjoin_and_free(*next_line, buf);
		if (!tmp)
		{
			if (need_to_free)
			{
				free(*next_line);
				*next_line = NULL;
			}
			return (NULL);
		}
		*next_line = tmp;
		need_to_free = 1;
	}
	return (*next_line);
}

char	*ft_get_line(int fd, char *s_line)
{
	char	*buf;
	char	*next_line;
	char	*result;

	if (s_line)
		next_line = s_line;
	else
	{
		next_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!next_line)
			return (NULL);
	}
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
	{
		free(next_line);
		return (NULL);
	}
	result = ft_get_read_line(fd, buf, &next_line, NULL);
	if (!result && !s_line)
		free(next_line);
	free(buf);
	return (result);
}

char	*line_formatting(char *line, char **s_line)
{
	char	*result;
	size_t	len;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	result = ft_strndup(line, i);
	if (!result)
		return (NULL);
	if (i == 0)
	{
		free(result);
		result = NULL;
	}
	len = ft_strlen(line) - (i);
	if (len != 0)
		*s_line = ft_substr(line, i, len);
	else
		*s_line = NULL;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*s_line[1024] = {0};
	char		*result;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_get_line(fd, s_line[fd]);
	if (!line)
	{
		free(s_line[fd]);
		s_line[fd] = NULL;
		return (NULL);
	}
	result = line_formatting(line, &s_line[fd]);
	free(line);
	return (result);
}
