/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:23:53 by hayigit           #+#    #+#             */
/*   Updated: 2025/02/20 16:35:58 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_2(t_cub *parser, t_cub3D *cub3d)
{
	if (parser->ch.direction == 'N')
		cub3d->collisions->face = north;
	else if (parser->ch.direction == 'S')
		cub3d->collisions->face = south;
	else if (parser->ch.direction == 'E')
		cub3d->collisions->face = east;
	else if (parser->ch.direction == 'W')
		cub3d->collisions->face = west;
	cub3d->map.size.x = cub3d->p->map_size1.x;
	cub3d->map.size.y = cub3d->p->map_size1.y;
}

int	modify(void *param)
{
	t_cub3D	*cub3d;

	cub3d = (t_cub3D *)param;
	player_modify(cub3d);
	ray_modify(cub3d);
	ceiling_floor_drawing(cub3d);
	wall_drawing(cub3d);
	mlx_put_image_to_window(cub3d->mlx.mlx, cub3d->mlx.win.win,
		cub3d->mlx.img.img, 0, 0);
	return (0);
}

int	start_cub(char **av)
{
	t_cub	main;
	t_cub3D	cub3d;

	s_init(&main);
	main.file_path = av[1];
	if (!map_size(&main, 0) || !get_file(&main, 0))
		error_write_nfree("File Error.");
	if (!get_loc_attr(&main, 0, 0))
	{
		free_double_ptr(main.file);
		ft_putendl_fd("Something is wrong in xpm path.", 2);
		exit(1);
	}
	start_parse(&main);
	init_all(&cub3d, &main);
	mlx_hook(cub3d.mlx.win.win, \
		KeyPress, (1 << 0), arrange_key_press, &cub3d);
	mlx_hook(cub3d.mlx.win.win, \
		KeyRelease, (1 << 1), arrange_key_release, &cub3d);
	mlx_hook(cub3d.mlx.win.win, \
		Destroy, (1 << 17), ft_exit, &cub3d);
	mlx_loop_hook(cub3d.mlx.mlx, modify, &cub3d);
	mlx_loop(cub3d.mlx.mlx);
	return (1);
}
