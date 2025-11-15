/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:28:47 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/15 19:04:06 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// int	main(void)
// {
// 	int	fd;
// 	char	*files;

// 	fd = open("NY", O_RDONLY);
// 	files = get_next_line(fd);
// 	printf("%s\n", files);
// 	free (files);
// 	close(fd);
// 	return (0);
// }

int	main(void)
{
	char	*next_line;
	int		fd;

	fd = open("two_lines", O_RDONLY);
	while (1)
	{
		next_line = get_next_line(fd);
		if (!next_line)
			break ;
		printf("%s", next_line);
		free(next_line);
	}
	close(fd);
	return (0);
}
