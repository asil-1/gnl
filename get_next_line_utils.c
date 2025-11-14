/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:36:48 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/14 17:51:30 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s && !(*s == (char)c))
		s++;
	if (*s == (char)c)
		return (s);
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *src, size_t n) //changer ca en strNdup
{
	char	*dst;
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

// va falloir proteger avant
char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	// i = -1;
	// while (s1[++i] && i < size)
	// 	result[i] = s1[i];
	// result[i] = '\0';
	result = ft_strncpy(s1, ft_strlen(s1));
	i = -1;
	j = ft_strlen(result);
	while (s2[++i] && (i + j) < size)
		result[j + i] = s2[i];
	result[j + i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	check;
	char	*result;

	if (s == NULL)
		return (NULL);
	check = ft_strlen(s);
	if (check - start > 0 && check - start < len)
		len = check - start;
	if (start >= check)
		len = 0;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (result)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
