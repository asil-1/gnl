/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:35:24 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/14 17:42:21 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t size, size_t repeat)
{
	void	*result;
	size_t	i;

	if (size == 0 || repeat == 0)
		return (NULL);
	if (size > (size_t) - 1 / repeat)
		return (NULL);
	result = malloc(size * repeat);
	if (!result)
		return (NULL);
	i = 0;
	while (i < (size * repeat))
		((unsigned char*)result)[i++] = 0;
	return (result);
}

char	*read_line(int fd, char *buffer)
{
	char	*line_read;
	char	*result;
	ssize_t	bytes_read;

	bytes_read = 0;
	line_read = ft_calloc(BUFFER_SIZE + 2, 1);
	if (!line_read)
		return (NULL);
	while (bytes_read > 0 && !ft_strchr(line_read, '\n'))
	{
		bytes_read = read(fd, line_read, BUFFER_SIZE);
		if (bytes_read < 0)
			free(line_read);
		result = ft_strjoin(buffer, line_read);
		if(!result)
		{
			free (line_read);
			return (NULL);
		}
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;
	char		*result;
	size_t		n;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, next_line);
	n = 0;
	while (line[n] != '\n')
		n++;
	result = ft_strncpy(line, n + 1);
	len = ft_strlen(line) - (n + 2);
	next_line = ft_substr(line, n + 2, len);
	return (line);
}












// char	*read_line(int fd, char *buffer)
// {
// 	char	*line;
// 	ssize_t	byte_read;

// 	line = ft_calloc(BUFFER_SIZE + 2, 1);
// 	if (!line)
// 		return (NULL);
// 	while (byte_read > 0 && !ft_strchr(buffer, '\n'))
// 	{
// 		byte_read = read(fd, line, BUFFER_SIZE);
// 		// if (byte_read < 0)
// 			// free_all
// 		// buffer = ft_join(buffer, line);
// 	}
// 	return (line);
// }
