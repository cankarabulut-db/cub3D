/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:29:33 by erkoc             #+#    #+#             */
/*   Updated: 2025/02/21 14:32:57 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_exit(void *cub3d)
{
	t_cub3D	*game;

	game = (t_cub3D *)cub3d;
	free(game->p->s_line);
	free(game->p->east_img);
	free(game->p->west_img);
	free(game->p->south_img);
	free(game->p->north_img);
	free(game->p->color_check);
	free(game->p->floor_check);
	free_double_ptr(game->p->color);
	free_double_ptr(game->p->floor);
	free_double_ptr(game->p->map);
	free(game->p->floor_int);
	free(game->p->color_int);
	mlx_destroy_window(game->mlx.mlx, game->mlx.win.win);
	mlx_destroy_image(game->mlx.mlx, game->mlx.img.img);
	mlx_destroy_image(game->mlx.mlx, game->tex_east.img);
	mlx_destroy_image(game->mlx.mlx, game->tex_west.img);
	mlx_destroy_image(game->mlx.mlx, game->tex_north.img);
	mlx_destroy_image(game->mlx.mlx, game->tex_south.img);
	mlx_destroy_display(game->mlx.mlx);
	free(game->mlx.mlx);
	exit(EXIT_SUCCESS);
}

int	arrange_key_press(int keycode, t_cub3D *cub3d)
{
	if (keycode == W_KEY)
		cub3d->inputs.w_key = 1;
	if (keycode == A_KEY)
		cub3d->inputs.a_key = 1;
	if (keycode == S_KEY)
		cub3d->inputs.s_key = -1;
	if (keycode == D_KEY)
		cub3d->inputs.d_key = -1;
	if (keycode == LEFT_KEY)
		cub3d->inputs.left_key = -1;
	if (keycode == RIGHT_KEY)
		cub3d->inputs.right_key = 1;
	if (keycode == ESC_KEY)
		ft_exit(cub3d);
	return (0);
}

int	arrange_key_release(int keycode, t_cub3D *cub3d)
{
	if (keycode == W_KEY)
		cub3d->inputs.w_key = 0;
	if (keycode == A_KEY)
		cub3d->inputs.a_key = 0;
	if (keycode == S_KEY)
		cub3d->inputs.s_key = 0;
	if (keycode == D_KEY)
		cub3d->inputs.d_key = 0;
	if (keycode == LEFT_KEY)
		cub3d->inputs.left_key = 0;
	if (keycode == RIGHT_KEY)
		cub3d->inputs.right_key = 0;
	return (0);
}

t_vec2	ft_vec2_div(t_vec2 vec, float div)
{
	t_vec2	vec_res;

	if (div == 0)
		return ((t_vec2){.x = 0, .y = 0});
	vec_res.x = vec.x / div;
	vec_res.y = vec.y / div;
	return (vec_res);
}

t_vec2	ft_vec2_norm(t_vec2 vec)
{
	return (ft_vec2_div(vec, ft_vec2_magnitude(vec)));
}
