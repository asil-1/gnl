/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:35:24 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/18 18:31:09 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	ft_get_read_line(int fd, char *buf, char **s_line)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0 && !ft_strchr(buf, '\n'))
	{
		buf[bytes_read] = '\0';
		*s_line = ft_strjoin_and_free(*s_line, buf);
		if (!*s_line)
			return ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		free(*s_line);
		*s_line = NULL;
		return ;
	}
	buf[bytes_read] = '\0';
	if (ft_strchr(buf, '\n'))
		*s_line = ft_strjoin_and_free(*s_line, buf);
}

void	ft_get_line(int fd, char **s_line)
{
	char	*buf;

	if (!*s_line)
	{
		*s_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!*s_line)
			return ;
	}
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
	{
		free(*s_line);
		*s_line = NULL;
		return ;
	}
	ft_get_read_line(fd, buf, s_line);
	free(buf);
}

char	*line_formatting(char **s_line, size_t i)
{
	char	*result;
	char	*tmp;
	size_t	len;

	result = NULL;
	if (i > 0)
		result = ft_strndup(*s_line, i);
	len = ft_strlen(*s_line) - i;
	if (len == 0 || !result)
	{
		free(*s_line);
		*s_line = NULL;
		return (result);
	}
	tmp = *s_line;
	*s_line = ft_substr(tmp, i, len);
	free(tmp);
	if (!*s_line)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*s_line = NULL;
	char		*result;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_get_line(fd, &s_line);
	if (!s_line)
		return (NULL);
	i = 0;
	while (s_line[i] && s_line[i] != '\n')
		i++;
	if (s_line[i] == '\n')
		i++;
	result = line_formatting(&s_line, i);
	return (result);
}
