/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarabul <nkarabul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 20:26:13 by nkarabul          #+#    #+#             */
/*   Updated: 2024/11/24 22:29:22 by nkarabul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int file_check(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	i--;
	if(str[i] == 'b' && str[i-1] == 'u' && str[i-2] == 'c' && str[i-3] == '.')
		return (1);
	return (-1);
}
int map_size(t_cub *main, int i)
{
	char *str;
	int fd;
	
	if(file_check(main->file_path) == -1)
		return (0);
	fd = open(main->file_path,O_RDWR,0644);
	if(fd == -1)
		return (0);
	while(1)
	{
		str = get_next_line(fd);
		if(str == NULL)
			break;
		else
			i++;
	}
	close(fd);
	main->map_size = i;
	if(i == 0)
		return (0);
	return (1);
}

void empty_replacer(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] >= '\t' && str[i] <= 'r')
		{
			str[i] = ' ';
		}
		i++;
	}
}

int get_file(t_cub *main,int i)
{
	char	**map;
	char	*tmp;
	int		fd;

	fd = open(main->file_path,O_RDWR,0644);
	map = malloc(sizeof(char * ) * (main->map_size + 1));
	if(!map)
		return (0);
	while(main->map_size > i)
	{
		map[i] = get_next_line(fd);
		tmp = map[i];
		map[i] = ft_strtrim(map[i],"\n");
		free(tmp);
		i++;
	}
	map[i] = 0;
	main->file = map;
	return (1);
}
int check_if_seperated(t_cub *main,int i)
{
	int flag;

	flag = 0;
	main->map_size = 0;
	while(!ft_map_attr_finder(main->file[i], "01N", 0, 0))
		i++;
	if(!main->file[i])
		return (0); // free
	main->map_start = i;
	while(main->file[i])
	{
		if(ft_map_attr_finder(main->file[i], "01N", 0, 0))
		{
			if(flag == 1)
				return (0);
			main->map_size++;
		}
		else
			flag = 1;
		i++;
	}
	if(main->map_size < 3)
		return (0);
	return (1);
}