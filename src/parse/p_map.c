/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:37:19 by nkarabul          #+#    #+#             */
/*   Updated: 2025/02/21 14:28:31 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	player_loc_check(char a)
{
	if (a == 'N' || a == 'W' || a == 'S' || a == 'E')
		return (1);
	return (0);
}

int	find_the_player_loc(t_cub *main, char **str)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (player_loc_check(str[y][x]) == 1)
			{
				main->char_x = x;
				main->char_y = y;
				main->perspective = str[y][x];
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	s_init(t_cub *main)
{
	main->file = NULL;
	main->multiple_map = NULL;
	main->file_path = NULL;
	main->map_size = -1;
	main->east_img = NULL;
	main->west_img = NULL;
	main->south_img = NULL;
	main->north_img = NULL;
	main->floor_check = NULL;
	main->color_check = NULL;
	main->attr_location = 0;
	main->floor = NULL;
	main->color = NULL;
	main->map = NULL;
	main->multiple_map = NULL;
	main->char_x = -1;
	main->char_y = -1;
	main->color_int = 0;
	main->floor_int = 0;
	main->map_start = -1;
	main->perspective = 0;
	main->s_line = NULL;
}

void	get_attr_floor_color(t_cub *main, char *str, char b, int i)
{
	char	*tmp;

	tmp = str;
	if (b == COLOR)
	{
		main->color_check = ft_strdup(str);
		main->color = ft_split(tmp + i + 1, ',');
		attr_get_integer(main, COLOR);
	}
	else if (b == FLOOR)
	{
		main->floor_check = ft_strdup(str);
		main->floor = ft_split(tmp + i + 1, ',');
		attr_get_integer(main, FLOOR);
	}
}

int	file_validation(char **file)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (file[y])
	{
		x = 0;
		while (file[y][x])
		{
			if (file[y][x] > 32 && file[y][x] < 127)
				return (0);
			else
				x++;
		}
		y++;
	}
	return (1);
}
