/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_norm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:53:11 by hayigit           #+#    #+#             */
/*   Updated: 2025/02/20 16:04:10 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	start_parse(t_cub *main)
{
	if (check_if_seperated(main, 0) == 1)
	{
		if (!get_map(main, 0) || !content_control(main, 0, -1, 0))
			map_content_walk_free(main);
		if (!side_by_side_check(main))
			map_content_walk_free(main);
		if (!walkability_check(main, 0, 0))
			map_content_walk_free(main);
		player_finder(main);
		single_line(main);
	}
	else
	{
		ft_putendl_fd("Map Error", 2);
		free_attr(main);
		free_double_ptr(main->file);
		exit(1);
	}
}

int	free_end_return(char **main_file)
{
	free_double_ptr(main_file);
	return (0);
}

int	get_map(t_cub *main, int i)
{
	main->map = malloc(sizeof(char *) * (main->map_size + 1));
	if (!main->map)
		free_double_ptr(main->file);
	while (main->map_size + 1 > i)
	{
		if (ft_map_attr_finder(main->file[main->map_start], "01", 0, 0) == 1)
		{
			main->map[i] = ft_strtrim(main->file[main->map_start], "\n");
			make_empty(main->file[main->map_start]);
			i++;
			main->map_start++;
		}
		else
		{
			main->map[i] = 0;
			break ;
		}
	}
	if (!file_validation(main->file))
		free_double_ptr(main->file);
	free_double_ptr(main->file);
	return (1);
}
