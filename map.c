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

#include "cub3d.h"
int file_check(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	i--;
	if(str[i] == 'b' && str[i-1] == 'u' && str[i-2] == 'c' && str[i-3] == '.')
		return (1);
	else
		return (-1);
	return (0);
}
int file_size(t_cub *main, int i)
{
	char *str;
	int fd;
	
	if(file_check(main->file_path) == -1)
		return (ft_putendl_fd("File extension is wrong.",2), -1);
	fd = open(main->file_path,O_RDWR,0644);
	if(fd == -1)
		return (ft_putendl_fd("Map Fd Error!",2), -1);
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
		return (ft_putendl_fd("Mapline does not exist.",2), -1);
	return (1);
}

void get_loc_attr(t_cub *main,int i,int j)
{
	
}

int get_file(t_cub *main,int i)
{
	char	**map;
	int		fd;
	int		start = 0;

	fd = open(main->file_path,O_RDWR,0644);
	map = malloc(sizeof(char * ) * (main->map_size + 1));
	if(!map)
		return (ft_putendl_fd("Map Allocate Error!",2), -1);
	while(main->map_size > i)
		map[i++] = get_next_line(fd);
	map[i] = 0;
	main->map = map;
	return (1);
}