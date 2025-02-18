#include "../cub3d.h"
void	ft_swap_int(int *a, int *b)
{
	if (a == b)
		return ;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void	mirror_tex(t_img *tex)
{
	int	i;
	int	j;

	j = 0;
	while (j < tex->size_line)
	{
		i = 0;
		while (i < tex->line_count / 2)
		{
			ft_swap_int((int *)(&tex->data[j + (i * tex->size_line)].value),
				(int *)(&tex->data[j + ((tex->size_line - i - 1)
						* tex->size_line)].value));
			i++;
		}
		j++;
	}
}

void	rotate_index(t_img *tex)
{
	int	i;
	int	j;

	i = 0;
	while (i < tex->size_line)
	{
		j = i;
		while (j < tex->line_count)
		{
			ft_swap_int((int *)(&(tex->data[j + (tex->size_line * i)].value)),
				(int *)(&(tex->data[i + (tex->line_count * j)].value)));
			j++;
		}
		i++;
	}
}

void	init_tex(t_cub3D *cub3d, t_img *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(cub3d->mlx.mlx, path,
			&tex->size_line, &tex->line_count);
	if (tex->img == NULL)
	{
		printf("cub3d: MLX Texture Error\n");
		exit(EXIT_FAILURE);
	}
	tex->data = (t_color *)mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->size_line, &tex->endian);
	tex->size_line /= (tex->bits_per_pixel / 8);
	rotate_index(tex);
}

void	init_all(t_cub3D *cub3d, t_cub *parser)
{
	cub3d->p = parser;
	cub3d->inputs = (t_input){0};
	cub3d->mlx.mlx = mlx_init();
	init_2(parser, cub3d);
	cub3d->floor.blue = parser->floor_int[2];
	cub3d->floor.red = parser->floor_int[0];
	cub3d->floor.green = parser->floor_int[1];
	cub3d->ceiling.blue = parser->color_int[2];
	cub3d->ceiling.red = parser->color_int[0];
	cub3d->ceiling.green = parser->color_int[1];
	init_tex(cub3d, &cub3d->tex_west, parser->west_img);
	init_tex(cub3d, &cub3d->tex_east, parser->east_img);
	init_tex(cub3d, &cub3d->tex_south, parser->south_img);
	init_tex(cub3d, &cub3d->tex_north, parser->north_img);
	mirror_tex(&cub3d->tex_north);
	mirror_tex(&cub3d->tex_east);
	init_win(cub3d);
	init_map(cub3d);
	init_player(cub3d);
	mlx_put_image_to_window(cub3d->mlx.mlx, cub3d->mlx.win.win,
		cub3d->mlx.img.img, 0, 0);
	mlx_do_key_autorepeatoff(cub3d->mlx.mlx);
}