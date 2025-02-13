/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:37:04 by nkarabul          #+#    #+#             */
/*   Updated: 2025/02/13 12:37:09 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if(!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int ft_strplen(char **str)
{
	int i = 0;
	if(!str)
		return (i);
	while(str[i])
		i++;
	return (i);
}

int ft_exist(char *str,char a)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == a)
			return (1);
		i++;
	}
	return (0);
}
char **ft_strddup(char **str,int x)
{
	char **new;

	new = malloc(sizeof(char *) * (ft_strplen(str) + 1));
	while(str[x])
	{
		new[x] = ft_strdup(str[x]);
		x++;
	}
	new[x] = 0;
	return (new);
}

void make_empty(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		str[i] = EMPTY;
		i++;
	}
}
