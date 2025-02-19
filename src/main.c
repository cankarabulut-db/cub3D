#include "cub3d.h"



int ft_digit_check(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int ft_alpha_check(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}
int attr_digitcheck(char **str)
{
	int tmp;
	int i = 0;
	while(str[i])
	{
		tmp = ft_atoi(str[i]);
		if((tmp >= 0 && tmp <= 255) && ft_digit_check(str[i]))
			i++;
		else
			return (0);
	}
	return 1;
}

void	wall_drawing(t_cub3D *cub3d)
{
	float	line_height;
	float	ray_len;
	int		i;

	i = 0;
	while (i < HEIGHT)
	{
		if (ft_vec2_equ(cub3d->collisions[i].pos, g_vec2_null))
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


int start_cub(char **av)
{
	t_cub	main;
	t_cub3D	cub3d;

	s_init(&main);
	main.file_path = av[1];
	if(!map_size(&main,0))
		error_write_nfree("File Error.");
	if(!get_file(&main,0))
		error_write_nfree("File Error.");
	if(!get_loc_attr(&main, 0, 0))
	{
		free_double_ptr(main.file);
		ft_putendl_fd("Something is wrong in xpm path.",2);
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

int main(int ac,char **av)
{
	(void)av;
	if(ac != 2)
	{
		ft_putendl_fd("Wrong Argument!",2);
		exit(1);
	}
	if(start_cub(av) == 1)
		return (0);
}