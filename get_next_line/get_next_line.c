/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:11:51 by nkarabul          #+#    #+#             */
/*   Updated: 2025/02/21 16:12:11 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(int fd, char *dst)
{
	int		i;
	char	*buff;

	i = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (i != 0 && !ft_exists(dst, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(dst);
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		dst = ft_strjoinn(dst, buff);
	}
	free(buff);
	return (dst);
}

char	*ft_getline(char *dst)
{
	int		i;
	int		x;
	char	*line;

	i = 0;
	x = 0;
	if (!dst[i])
		return (NULL);
	while (dst[i] && dst[i] != '\n')
		i++;
	if (dst[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (x < i)
	{
		line[x] = dst[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}
char *check_left(char *str){
	if (ft_strlenn(str) == 0)
	{
		free(str);
		return NULL;
	}
	return (str);
}
char	*ft_get_left(char *dst)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	while (dst[i] && dst[i] != '\n')
		i++;
	if (!dst[i])
	{
		free(dst);
		return (NULL);
	}
	if (dst[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlenn(dst) - i + 1));
	if (!str)
		return (NULL);
	while (dst[i])
		str[len++] = dst[i++];
	str[len] = '\0';
	free(dst);
	return check_left(str);
}

char	*get_next_line(int fd)
{
	static char	*dst;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dst = ft_readline(fd, dst);
	if (!dst)
		return (NULL);
	str = ft_getline(dst);
	dst = ft_get_left(dst);
	
	return (str);
}
