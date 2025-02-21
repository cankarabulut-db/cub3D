/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_main_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:50:30 by hayigit           #+#    #+#             */
/*   Updated: 2025/02/21 14:03:40 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_finder(t_cub *main)
{
	main->ch.direction = main->perspective;
	main->ch.p_loc.x = main->char_x - 1;
	main->ch.p_loc.y = main->char_y - 1;
	printf("Player Location: %d %d\n", main->ch.p_loc.x, main->ch.p_loc.y);
	main->map_size1.x = find_the_longest(main->map) + 2;
}

void	single_line(t_cub *parser)
{
	char	**map;
	char	*temp;
	int		i;

	parser->s_line = ft_strdup("");
	map = surrounded_map(parser);
	i = 0;
	while (map[i])
	{
		temp = parser->s_line;
		parser->s_line = ft_strjoin(parser->s_line, map[i]);
		free(temp);
		i++;
	}
	parser->map_size1.y = ft_strplen(parser->map) + 2;
	free_double_ptr(map);
}

void	map_content_walk_free(t_cub *main)
{
	free_double_ptr(main->map);
	free_attr(main);
	ft_putendl_fd("Map Error", 2);
	exit(1);
}
