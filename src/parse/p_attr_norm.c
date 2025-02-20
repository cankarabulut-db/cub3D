/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_attr_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:45:41 by hayigit           #+#    #+#             */
/*   Updated: 2025/02/20 15:23:50 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	attr_get_integer(t_cub *main, int type)
{
	if (type == COLOR)
	{
		main->color_int = malloc(sizeof(int) * (3));
		if (!main->color)
			return ;
		if (ft_strplen(main->color) != 3)
			return ;
		main->color_int[0] = ft_atoi(main->color[0]);
		main->color_int[1] = ft_atoi(main->color[1]);
		main->color_int[2] = ft_atoi(main->color[2]);
	}
	else if (type == FLOOR)
	{
		main->floor_int = malloc(sizeof(int) * (3));
		if (!main->floor)
			return ;
		if (ft_strplen(main->floor) != 3)
			return ;
		main->floor_int[0] = ft_atoi(main->floor[0]);
		main->floor_int[1] = ft_atoi(main->floor[1]);
		main->floor_int[2] = ft_atoi(main->floor[2]);
	}
}

int	attribute_space_check(char *str, int x)
{
	while (str[x])
	{
		if ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
			return (1);
		x++;
	}
	return (0);
}

int	extension_checker_norm(t_cub *main)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = !extension_checker(main->south_img);
	b = !extension_checker(main->west_img);
	c = !extension_checker(main->east_img);
	d = !extension_checker(main->north_img);
	return (a || b || c || d);
}

int	attribute_space_check_norm(t_cub *main)
{
	int	east_check;
	int	west_check;
	int	south_check;
	int	north_check;

	east_check = attribute_space_check(main->east_img, 0);
	west_check = attribute_space_check(main->west_img, 0);
	south_check = attribute_space_check(main->south_img, 0);
	north_check = attribute_space_check(main->north_img, 0);
	return (east_check || west_check || south_check || north_check);
}
