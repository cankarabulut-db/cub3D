/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_attr1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:37:27 by nkarabul          #+#    #+#             */
/*   Updated: 2025/02/13 12:37:28 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void free_color_floor(int *color_floor)
{
	if(color_floor)
		free(color_floor);
	color_floor = NULL;
}