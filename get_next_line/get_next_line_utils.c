/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:11:40 by nkarabul          #+#    #+#             */
/*   Updated: 2024/11/24 19:14:04 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenn(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_exists(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoinn(char *dst, char *src)
{
	char	*allocated;
	int		i;
	int		x;

	allocated = malloc(sizeof(char) * (ft_strlenn(dst) + ft_strlenn(src) + 1));
	if (!allocated)
		return (NULL);
	i = 0;
	x = 0;
	if (!dst)
	{
		dst = malloc(sizeof(char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
	}
	while (dst[i])
		allocated[x++] = dst[i++];
	i = 0;
	while (src[i])
		allocated[x++] = src[i++];
	allocated[x] = '\0';
	free (dst);
	return (allocated);
}
