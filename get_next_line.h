/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clora-ro <clora-ro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:40:40 by clora-ro          #+#    #+#             */
/*   Updated: 2021/11/29 17:10:10 by clora-ro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*ft_strjoin(char *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *source);
char	*ft_strndup(const char *s, int len);
char	*ft_substr(char *s, int start, int len);
char	*get_next_line(int fd);

#endif