/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:04:08 by hayigit           #+#    #+#             */
/*   Updated: 2025/02/20 18:09:00 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_vec2	g_south(void)
{
	return ((t_vec2){.x = 0, .y = 1});
}

t_vec2	g_north(void)
{
	return ((t_vec2){.x = 0, .y = -1});
}

t_vec2	g_east(void)
{
	return ((t_vec2){.x = -1, .y = 0});
}

t_vec2	g_west(void)
{
	return ((t_vec2){.x = 1, .y = 0});
}
