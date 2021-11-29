/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:39:26 by clora-ro          #+#    #+#             */
/*   Updated: 2021/11/29 17:17:59 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	str = malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* (sizeof(char)));
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *)(s)) || !len)
		return (ft_strdup(""));
	if (len > ft_strlen((char *)(s)) - start)
		len = ft_strlen((char *)(s)) - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *source)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!source)
		return (NULL);
	cpy = malloc((ft_strlen((char *)source) + 1) * (sizeof(char)));
	if (!cpy)
		return (NULL);
	while (source[i])
	{
		cpy[i] = source[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strndup(const char *s, int len)
{
	char	*cpy;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	cpy = malloc((len + 1) * (sizeof(char)));
	if (!cpy)
		return (NULL);
	while (s[i] && i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
