/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:38:04 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/16 09:12:57 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h> //open
# include <unistd.h> //read
# include <stdio.h> //ssize_t & printf
# include <string.h> //memset
# include <stdlib.h> //malloc

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
void	*ft_calloc(size_t size, size_t repeat);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(char *s, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);

#endif
