#include "../cub3d.h"

int	free_double_ptr(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	if (str)
		free(str);
	str = NULL;
	return (0);
}

void flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if(x >= (int)ft_strlen(map[y]) || y >= ft_strplen(map))
		return ;
	if (map[y][x] == PARSE_WALL)
		return ;
	map[y][x] = PARSE_WALL;
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
int ft_map_attr_finder(char *str,char *tb_found,int i,int j)
{
	if(!str)
		return 2;
	while(str[i])
	{
		j = 0;
		while(tb_found[j])
		{
			if(str[i] == tb_found[j])
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int fill_control(char *str,char a,int i)
{
	while(str[i])
	{
		if(str[i] == a || (str[i] == ' ' || str[i] == '\t'))
			i++;
		else
			return (0);
	}
	return (1);
}

int extension_checker(char *str)
{
	int size;

	size = ft_strlen(str);
	if(str[size - 1] == 'm' && str[size - 2] == 'p' && str[size - 3] == 'x' && str[size - 4] == '.') 
		return (1);
	return (0);
}