/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_attr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayigit <hayigit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:36:22 by hayigit           #+#    #+#             */
/*   Updated: 2025/02/21 15:54:43 by hayigit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_attr(t_cub *main, char *str)
{
	int	true;
	int	i;

	i = 0;
	true = 1;
	while ((str[i] == ' ' || str[i] == '\t') && (str[i] != '\0'))
		i++;
	if ((str[i] == 'F' && str[i + 1] == ' ' ) && ++true)
		get_attr_floor_color(main, str, FLOOR, i);
	else if ((str[i] == 'C' && str[i + 1] == ' ') && ++true)
		get_attr_floor_color(main, str, COLOR, i);
	else if ((str[i] == 'W' && str[i + 1] == 'E') && ++true)
		main->west_img = ft_strtrim(str + i + 2, " \n \t");
	else if ((str[i] == 'E' && str[i + 1] == 'A') && ++true)
		main->east_img = ft_strtrim(str + i + 2, " \n \t");
	else if ((str[i] == 'S' && str[i + 1] == 'O') && ++true)
		main->south_img = ft_strtrim(str + i + 2, " \n \t");
	else if ((str[i] == 'N' && str[i + 1] == 'O') && ++true)
		main->north_img = ft_strtrim(str + i + 2, " \n \t");
	if (true == 2)
		make_empty(str);
}

void	free_attr(t_cub *main)
{
	if (main->floor)
		free_double_ptr(main->floor);
	if (main->color)
		free_double_ptr(main->color);
	if (main->east_img)
		free(main->east_img);
	if (main->west_img)
		free(main->west_img);
	if (main->south_img)
		free(main->south_img);
	if (main->north_img)
		free(main->north_img);
	free_color_floor(main->color_int);
	free_color_floor(main->floor_int);
	free(main->floor_check);
	free(main->color_check);
	main->floor_check = NULL;
	main->color_check = NULL;
	main->floor = NULL;
	main->color = NULL;
	main->east_img = NULL;
	main->west_img = NULL;
	main->south_img = NULL;
	main->north_img = NULL;
}

int	get_loc_attr(t_cub *main, int x, int y)
{
	y = get_attr_count(main, -1);
	if (y != 6)
		return (0);
	while (main->file[x])
		get_attr(main, main->file[x++]);
	if (extension_checker_norm(main)
		|| !attr_digitcheck(main->floor)
		|| ft_strplen(main->floor) != 3
		|| ft_strplen(main->color) != 3
		|| !attr_digitcheck(main->color)
		|| how_much_char(main->floor_check,',') != 2
		|| how_much_char(main->color_check,',') != 2)
	{
		free_attr(main);
		return (0);
	}
	if (attribute_space_check_norm(main))
	{
		free_attr(main);
		return (0);
	}

	return (1);
}

int	attr_check(t_cub *main, int control, int x, int i)
{
	int	tmp;

	tmp = control;
	if (main->file[x][i] == 'F')
		control++;
	else if (main->file[x][i] == 'C' &&
	(main->file[x][i + 1] == ' ' || main->file[x][i + 1] == '\t'))
		control++;
	else if ((main->file[x][i] == 'W' && main->file[x][i + 1] == 'E')
	&& (main->file[x][i + 2] == ' ' || main->file[x][i + 2] == '\t'))
		control++;
	else if ((main->file[x][i] == 'E' && main->file[x][i + 1] == 'A')
	&& (main->file[x][i + 2] == ' ' || main->file[x][i + 2] == '\t'))
		control++;
	else if ((main->file[x][i] == 'S' && main->file[x][i + 1] == 'O')
	&& (main->file[x][i + 2] == ' ' || main->file[x][i + 2] == '\t'))
		control++;
	else if ((main->file[x][i] == 'N' && main->file[x][i + 1] == 'O')
	&& (main->file[x][i + 2] == ' ' || main->file[x][i + 2] == '\t'))
		control++;
	if (tmp != control)
		main->attr_location = x;
	return (control);
}

int	get_attr_count(t_cub *main, int x)
{	
	int	control;
	int	i;

	i = 0;
	control = 0;
	while (main->file[++x])
	{
		while (main->file[x][i] == ' ')
			i++;
		control += attr_check(main, 0, x, i);
		i = 0;
	}
	return (control);
}
