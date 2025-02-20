/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:21:46 by hayigit           #+#    #+#             */
/*   Updated: 2025/02/20 18:11:01 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_digit_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_alpha_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	attr_digitcheck(char **str)
{
	int	tmp;
	int	i;

	i = 0;
	while (str[i])
	{
		tmp = ft_atoi(str[i]);
		if ((tmp >= 0 && tmp <= 255) && ft_digit_check(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

void	wall_drawing(t_cub3D *cub3d)
{
	float	line_height;
	float	ray_len;
	int		i;

	i = 0;
	while (i < HEIGHT)
	{
		if (ft_vec2_equ(cub3d->collisions[i].pos, g_vec2_null()))
		{
			i++;
			continue ;
		}
		ray_len = ft_vec2_dist(cub3d->collisions[i].pos, cub3d->player.pos);
		line_height = HEIGHT
			/ (ray_len * cos(ft_deg_to_rad(cub3d->coll_deg[i])));
		draw_wall_piece(cub3d, line_height, i, cub3d->collisions[i].face);
		i++;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		ft_putendl_fd("Wrong Argument!", 2);
		exit(1);
	}
	if (start_cub(av) == 1)
		return (0);
}
