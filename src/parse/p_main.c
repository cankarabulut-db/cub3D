/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:37:22 by nkarabul          #+#    #+#             */
/*   Updated: 2025/02/13 14:04:33 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void error_write_nfree(char *str)
{
	ft_putendl_fd(str,2);
	exit(1);
}

int find_the_longest(char **str)
{
	int i;
	size_t tmp;

	i = -1;
	tmp = 0;
	while(str[++i])
	{
		if(ft_strlen(str[i]) > tmp)
			tmp = ft_strlen(str[i]);
	}
	return (tmp);
}

int ft_check(char **sur, int y,int x)
{
	if(y == 0 || x == 0)
		return 0;
	if(y >= ft_strplen(sur) || x >= (int)ft_strlen(sur[y]))
		return 0;
	if(sur[y - 1][x] == PARSE_WALL)	
		return (0);
	else if(sur[y + 1][x] == PARSE_WALL)
		return (0);
	else if(sur[y][x + 1] == PARSE_WALL)
		return (0);
	else if(sur[y][x - 1] == PARSE_WALL)
		return (0);
	return (1);
}
int walkability_check(t_cub *main,int x,int y)
{
	char **sur;
	sur = surrounded_map(main);
	find_the_player_loc(main,sur);

	if(!ft_check(sur,main->char_y,main->char_x))
	{
		free_double_ptr(sur);
		return (0);
	}
	while(sur[y])
	{
		x = 0;
		while(sur[y][x])
		{
			if(sur[y][x] == '0' && !ft_check(sur,y,x))
			{
				free_double_ptr(sur);
				return (0);
			}
			x++;
		}
		y++;
	}
	free_double_ptr(sur);
    return (1);
}
int content_control(t_cub *main,int x,int y,int flag)
{
	while(main->map[++y])
	{
		x = 0;
		while(main->map[y][x])
		{
			if(main->map[y][x] == ' ')
				x++;
			else if(main->map[y][x] == '1' || main->map[y][x] == '0')
				x++;
			else if(main->map[y][x] == 'N' || main->map[y][x] == 'W' || main->map[y][x] == 'S' || main->map[y][x] == 'E')
			{
				if(flag == 1)
					return (0);
				flag = 1;
				x++;
			}
			else
				return (0);
		}
	}
	if(flag != 1)
		return (0);
	return (1);	
}

void map_content_walk_free(t_cub *main)
{
	free_double_ptr(main->map);
	free_attr(main);
	ft_putendl_fd("Map Error",2);
	exit(1);
}
void start_parse(t_cub *main)
{
	if(check_if_seperated(main,0) == 1)
	{
		if(!get_map(main,0) || !content_control(main,0,-1,0))
			map_content_walk_free(main);
		if(!side_by_side_check(main))
			map_content_walk_free(main);
		if (!walkability_check(main,0,0))
			map_content_walk_free(main);
	}
	else
	{
		ft_putendl_fd("Map Error",2);
		free_attr(main);
		free_double_ptr(main->file);
		exit(1);
	}
	free_double_ptr(main->map);
	free_attr(main);
}