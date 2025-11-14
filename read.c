/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:40:52 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/13 18:17:33 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //open
#include <unistd.h> //read
#include <stdio.h> //ssize_t & printf
#include <string.h> //ssize_t & printf

int	main(void)
{
	int		fd;
	char	buf[10];
	// faire un calloc pour l'allocatiom de memoire
	size_t	nbytes;
	ssize_t	result;

	nbytes = sizeof(buf);
	fd = open("NY", O_RDONLY);
	result = 1;
	while (result > 0)
	{
		memset(buf, 0, sizeof(buf));
		result = read(fd, buf, nbytes);
		printf("%s", buf);
	}
}
