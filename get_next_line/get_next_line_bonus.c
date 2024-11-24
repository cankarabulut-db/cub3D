/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:11:19 by nkarabul          #+#    #+#             */
/*   Updated: 2024/01/20 19:11:22 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		dst = ft_strjoin(dst, buff);
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
	str = malloc(sizeof(char) * (ft_strlen(dst) - i + 1));
	if (!str)
		return (NULL);
	while (dst[i])
		str[len++] = dst[i++];
	str[len] = '\0';
	free(dst);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*dst[10240];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dst[fd] = ft_readline(fd, dst[fd]);
	if (!dst[fd])
		return (NULL);
	str = ft_getline(dst[fd]);
	dst[fd] = ft_get_left(dst[fd]);
	return (str);
}
