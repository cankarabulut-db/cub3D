/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_multimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:37:15 by nkarabul          #+#    #+#             */
/*   Updated: 2025/02/13 12:37:17 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void fill_string(char *wall_map,int longest)
{
	int i;

	i = 0;
	while(longest + 2 > i)
	{
		wall_map[i] = PARSE_WALL;
		i++;
	}
	wall_map[i] = '\0';
}
void string_filler(char *str,char *map,int longest)
{
	int i;
	int j;

	j = 0;
	i = 0;
	str[i++] = PARSE_WALL;
	while(longest + 2 > i)
	{
		if(map[j] == '\0')
		{
			str[i] = PARSE_WALL;
			i++;
			continue;
		}
		else if(map[j] == ' ')
			str[i] = PARSE_WALL;
		else
			str[i] = map[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

int check_multimap(char **map)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if(map[y][x] != PARSE_WALL)
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
	
}

char **surrounded_map(t_cub *main)
{
	char **new_map;
	int y_size;
	int x;
	
	x = 0;
	y_size = ft_strplen(main->map) + 2;
	new_map = malloc(sizeof(char *) * (y_size + 1));
	while(y_size > x)
	{
		new_map[x] = malloc(sizeof(char) * (find_the_longest(main->map) + 3));
		if(x == 0 || x == (y_size - 1))
			fill_string(new_map[x],find_the_longest(main->map));
		else
			string_filler(new_map[x],main->map[x - 1],find_the_longest(main->map));
		x++;
	}
	new_map[x] = NULL;	
	return (new_map);
}
int side_by_side_check(t_cub *main)
{
	char **new_map;
	new_map = surrounded_map(main);
	find_the_player_loc(main,new_map);
	flood_fill(new_map,main->char_x,main->char_y);
	main->map_size1.y = ft_strplen(new_map) + 1;
	if(!check_multimap(new_map))
	{
		free_double_ptr(new_map);
		return (0);
	}
	free_double_ptr(new_map);
	return (1);
}