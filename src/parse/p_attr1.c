/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_attr1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:37:27 by nkarabul          #+#    #+#             */
/*   Updated: 2025/02/20 17:32:46 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_color_floor(int *color_floor)
{
	if (color_floor)
		free(color_floor);
	color_floor = NULL;
}
int how_much_char(char *str,char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while(str[i]){
		if (str[i] == c)
			count++;
		i++;
	}
	return count;
}