/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:38:56 by clora-ro          #+#    #+#             */
/*   Updated: 2021/11/29 17:20:23 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_return(char *str)
{
	int		i;

	if (!str)
		return (-10);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-10);
}

char	*cut_line(char *buffer)
{
	int		i;
	char	*tmp;

	i = search_return(buffer);
	if (i == -10)
		tmp = ft_strdup(buffer);
	else
		tmp = ft_strndup(buffer, i + 1);
	free(buffer);
	return (tmp);
}

char	*get_next_line(int fd)
{
	int			i;
	static int	ret = -10;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	static char	*remain = NULL;

	line = NULL;
	if (remain && remain[0] != 0)
	{
		line = ft_strdup(remain);
		free(remain);
	}
	else
	{
		if (ret == 0)
		{
			free(remain);
			return (NULL);
		}
	}
	while (ret != 0 && search_return(line) < 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		buffer[ret] = 0;
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = cut_line(line);
	if (remain != NULL)
		free(remain);
	remain = ft_substr(buffer, i + 1, BUFFER_SIZE);
	return (line);
}

// static buffer
// modifier remain

// une autre fonction qui decoupe la chaine jusqu'au \n inclus
// ret = nbr de char lu dans buffersize
// transformer search_return en fct qui compte l'index du \n
// se servir de search_return dans cut_line avec le strndup