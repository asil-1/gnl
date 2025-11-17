/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:28:47 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/17 14:18:42 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// int	main(void)
// {
// 	char	*next_line;
// 	int		fd;

// 	fd = open("le corbeau et le renard", O_RDONLY);
// 	while (1)
// 	{
// 		next_line = get_next_line(fd);
// 		if (!next_line)
// 			break ;
// 		printf("%s", next_line);
// 		free(next_line);
// 	}
// 	close(fd);
// 	return (0);
// }

int	main(void)
{
	// char	*next_line;
	char	*next_line1;
	char	*next_line2;
	// int		fd;
	int		fd1;
	int		fd2;

	// fd = open("long_text", O_RDONLY);
	fd1 = open("le corbeau et le renard", O_RDONLY);
	fd2 = open("fable2", O_RDONLY);
	// next_line = get_next_line(fd);
	next_line1 = get_next_line(fd1);
	printf("%s", next_line1);
	free(next_line1);
	next_line2 = get_next_line(fd2);
	printf("%s", next_line2);
	free(next_line2);

	while (next_line1 || next_line2)
	{
		next_line1 = get_next_line(fd1);
		next_line2 = get_next_line(fd2);
		printf("%s", next_line1);
		printf("%s", next_line2);
		free(next_line1);
		free(next_line2);
	}
	// close(fd);
	close(fd1);
	close(fd2);
	return (0);
}
