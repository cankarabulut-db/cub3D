/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:26:15 by nkarabul          #+#    #+#             */
/*   Updated: 2024/11/24 22:09:15 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void s_init(t_cub *main)
{
	main->file = NULL;
	main->file_path = NULL;
	main->map_size = -1;
	main->east_img = NULL;
	main->west_img = NULL;
	main->south_img = NULL;
	main->north_img = NULL;
	main->floor = NULL;
	main->color = NULL;
	main->map = NULL;
}

int get_attr_count(t_cub *main,int x)
{
	static		int control;

	while(main->file[++x])
	{
		if(main->file[x][0] == 'F')
			control++;
		else if(main->file[x][0] == 'C' && main->file[x][1] == ' ')
			control++;
		else if((main->file[x][0] == 'W' && main->file[x][1] == 'E') && main->file[x][2] == ' ')
			control++;
		else if((main->file[x][0] == 'E' && main->file[x][1] == 'A') && main->file[x][2] == ' ')
			control++;
		else if((main->file[x][0] == 'S' && main->file[x][1] == 'O') && main->file[x][2] == ' ')
			control++;
		else if((main->file[x][0] == 'N' && main->file[x][1] == 'O') && main->file[x][2] == ' ')
			control++;
	}
	return control;
}
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
			return (-1);
	}
	return 1;
}
void attr_get_integer(t_cub *main,int type)
{
	if(type == COLOR)
	{
		main->color_int = malloc(sizeof(int) * (3));
		main->color_int[0] = ft_atoi(main->color[0]);
		main->color_int[1] = ft_atoi(main->color[1]);
		main->color_int[2] = ft_atoi(main->color[2]);
	}
	else if(type == FLOOR)
	{
		main->floor_int = malloc(sizeof(int) * (3));
		main->floor_int[0] = ft_atoi(main->floor[0]);
		main->floor_int[1] = ft_atoi(main->floor[1]);
		main->floor_int[2] = ft_atoi(main->floor[2]);
	}
}
int ft_strplen(char **str)
{
	int i = 0;
	if(!str)
		return (i);
	while(str[i])
		i++;
	return (i);
}
void get_attr_floor_color(t_cub *main,char *str, char b)
{
	char *tmp;
	if(b == COLOR)
	{
		tmp = ft_strdup(str + 1);
		main->color = ft_split(tmp,',');
		if(attr_digitcheck(main->color) == -1 || ft_strplen(main->color) != 3) // free
			printf("bitti\n");
		attr_get_integer(main,COLOR);
		free(tmp);
	}
	else if(b == FLOOR)
	{
		tmp = ft_strdup(str + 1);
		main->floor = ft_split(tmp,',');
		if(attr_digitcheck(main->floor) == -1 || ft_strplen(main->floor) != 3)
			printf("bitti\n");
		attr_get_integer(main,FLOOR);
		free(tmp);
	}
}

int start_cub(char **av)
{
	t_cub	main;

	s_init(&main);
	main.file_path = av[1];
	if(file_size(&main,0) == 1 && get_file(&main,0) == 1)
	{
		start_parse(&main,0,0);
	}
	else
		return (-1);
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