/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:28:47 by ldepenne          #+#    #+#             */
/*   Updated: 2026/10/30 17:28:34 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


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
	char	*s1;
	// char	*s2;
	// int			fd1 = open("file.txt", O_RDONLY);
	int		fd1 = open("le corbeau et le renard", O_RDONLY);
	// int		fd2 = open("loljesuisla", O_RDONLY);

	do
	{
		s1 = get_next_line(fd1);
		// s2 = get_next_line(fd2);
		s1 ? printf("%s\n", s1) : printf("\n");
		// s2 ? printf("%s\n", s2) : printf("\n"); //FR: ternaires ENG: ternaries
		free(s1);
		// free(s2);
	} while(s1);
	close(fd1);
	// close(fd2);
}


// int	main(void)
// {
// 	char	*file1;
// 	char	*file2;
// 	int	fd1 = open("txt.txt", O_RDONLY);
// 	int	fd2 = open("other.txt", O_RDONLY);

// 	do
// 	{
// 		file1 = get_next_line(fd1);
// 		file2 = get_next_line(fd2);
// 		file1 ? printf("%s", file1) : printf("%s\n", file1);
// 		file2 ? printf("%s", file2) : printf("%s\n", file2);
// 		free(file1);
// 		free(file2);
// 	} while(file1 || file2);
// 	close(fd1);
// 	close(fd2);
// }
