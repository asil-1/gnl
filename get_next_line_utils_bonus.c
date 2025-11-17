/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:36:48 by ldepenne          #+#    #+#             */
/*   Updated: 2025/11/17 13:54:55 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strndup(char *s, size_t n)
{
	size_t	i;
	char	*result;

	if (n > ft_strlen(s))
		return (NULL);
	result = malloc(sizeof(char) * (n + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s && i < n)
	{
		result[i] = s[i];
		i++;
	}
	while (i <= n)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*result;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(sizeof(char) * size);
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	i = -1;
	j = ft_strlen(s1);
	while (s2[++i] && (i + j) < size)
		result[j + i] = s2[i];
	result[j + i] = '\0';
	free(s1);
	return (result);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	check;
	char	*result;

	check = ft_strlen(s);
	if (check - start > 0 && check - start < len)
		len = check - start;
	if (start >= check)
		len = 0;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
