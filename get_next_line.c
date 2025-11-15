/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:35:24 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/15 14:35:29 by ldepenne         ###   ########.fr       */
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

char	*read_line(int fd, char *line_read, char *buffer)
{
	char	*result;
	ssize_t	bytes_read;

	(void)buffer;
	bytes_read = 1;
	result = ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	while (bytes_read > 0 && !ft_strchr(line_read, '\n'))
	{
		bytes_read = read(fd, line_read, BUFFER_SIZE);
		if (bytes_read < 0)
			free(line_read);
		result = ft_strjoin(result, line_read);
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
	static char	*next_line = {0};
	char		*result;
	char		*line;
	size_t		len;
	size_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	if (!line)
		return (NULL);
	line = read_line(fd, line, next_line);
	n = 0;
	while (line[n] != '\n' && line[n])
		n++;
	result = ft_strndup(line, n + 1);
	len = ft_strlen(line) - (n + 1);
	next_line = ft_substr(line, n + 1, len);
	return (result);
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
