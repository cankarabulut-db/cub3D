#include "../cub3d.h"
int player_loc_check(char a)
{
	if(a == 'N' || a == 'W' || a == 'S' || a == 'E')
		return (1);
	return (0);
}
int find_the_player_loc(t_cub *main,char **str)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while(str[y])
	{
		x = 0;
		while(str[y][x])
		{
			if(player_loc_check(str[y][x]) == 1)
			{
				main->char_x = x;
				main->char_y = y;
				main->perspective = str[y][x];
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

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
	main->multiple_map = NULL;
	main->char_x = -1;
	main->char_y = -1;
	main->color_int = 0;
	main->floor_int = 0;
	main->map_start = -1;
	main->perspective = 0;
}
void get_attr_floor_color(t_cub *main,char *str, char b)
{
	char *tmp;

	tmp = str;
	if(b == COLOR)
	{
		main->color = ft_split(tmp + 1,',');
		attr_get_integer(main,COLOR);
	}
	else if(b == FLOOR)
	{
		main->floor = ft_split(tmp + 1,',');
		attr_get_integer(main,FLOOR);
	}
}

int get_map(t_cub *main,int i)
{	
	main->map = malloc(sizeof(char *) * (main->map_size + 1));
	if(!main->map)
		return (-1);
	while(main->map_size + 1 > i)
	{
		if(ft_map_attr_finder(main->file[main->map_start], "01", 0, 0) == 1)
		{
			main->map[i] = ft_strtrim(main->file[main->map_start],"\n");
			i++;
			main->map_start++;
		}
		else
		{
			main->map[i] = 0;
			break;
		}
	}
	
	return (1);
}