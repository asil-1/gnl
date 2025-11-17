/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:38:04 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/17 13:54:26 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h> //open
# include <unistd.h> //read
# include <stdio.h> //ssize_t
# include <stdlib.h> //malloc

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
char	*ft_get_line(int fd, char *s_line);
char	*ft_get_read_line(int fd, char *buf, char *next_line);
void	*ft_calloc(size_t size, size_t repeat);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	*ft_strndup(char *s, size_t n);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(char *s);

#endif
