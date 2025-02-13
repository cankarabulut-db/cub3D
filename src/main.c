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

int start_cub(char **av)
{
	t_cub	main;

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

void __attribute__((destructor)) f()
{
	system("leaks cub3D");
}