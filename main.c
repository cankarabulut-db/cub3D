/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:26:15 by nkarabul          #+#    #+#             */
/*   Updated: 2024/11/24 21:49:01 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void start_parse(t_cub *main)
{
	(void)main;
}
int start_cub(char **av)
{
	t_cub	main;

	main.file_path = av[1];
	if(map_size(&main,0) == 1 && get_map(&main,0) == 1)
	{
		start_parse(&main);
		return (1);
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