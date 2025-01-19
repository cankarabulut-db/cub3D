#include "cub3d.h"

void get_attr(t_cub *main,char *str)
{
	int true;

	true = 1;
	if(str[0] == 'F' && ++true)
		get_attr_floor_color(main,str,FLOOR);
	else if(str[0] == 'C' && ++true)
		get_attr_floor_color(main,str,COLOR);
	else if((str[0] == 'W' && str[1] == 'E') && ++true)
		main->west_img = ft_strtrim(str + 2, " \n \t");
	else if((str[0] == 'E' && str[1] == 'A') && ++true)
		main->east_img = ft_strtrim(str + 2, " \n \t");
	else if((str[0] == 'S' && str[1] == 'O') && ++true)
		main->south_img = ft_strtrim(str + 2, " \n \t");
	else if((str[0] == 'N' && str[1] == 'O') && ++true)
		main->north_img = ft_strtrim(str + 2, " \n \t");
	if(true == 2)
		make_empty(str);
}

void get_loc_attr(t_cub *main,int x,int y)
{
	y = get_attr_count(main,-1);
	if(y != 6)
	{
		printf("%s\n","missing arguments "); // free atmayı unutma.
		exit(0);
	}
	x = 0;
	while(main->file[x])
		get_attr(main,main->file[x++]);
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
		if(str[i] == a || str[i] == ' ')
			i++;
		else
			return (0);
	}
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
		return (-1); // free
	main->map_start = i;
	while(main->file[i])
	{
		if(ft_map_attr_finder(main->file[i], "01N", 0, 0))
		{
			if(flag == 1)
				return (-1);
			main->map_size++;
		}
		else
			flag = 1;
		i++;
	}
	if(main->map_size < 3)
		return (-1);
	return (1);
}
int get_map(t_cub *main,int i)
{	
	main->map = malloc(sizeof(char *) * (main->map_size + 1));
	if(!main->map)
		return (-1);
	while(main->map_size + 1 > i)
	{
		if(ft_map_attr_finder(main->file[main->map_start], "01N", 0, 0) == 1)
		{
			main->map[i] = ft_strtrim(main->file[main->map_start], "\n");
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

void	free_double_ptr(char **str)
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
}
int map_surrounding_control(t_cub *main)
{	int x = 0;
	if(fill_control(main->map[0], '1', 0) == 0)
		return (-1);
	if(fill_control(main->map[ft_strplen(main->map) - 1], '1', 0) == 0)
		return (-1);
	while(main->map[x])
	{
		if(main->map[x][0] != '1')
			return (-1);
		if(main->map[x][ft_strlen(main->map[x]) - 1] != '1')
			return (-1);
		x++;
	}
	return (1);
}

int find_the_biggest(char **map)
{
	(void)map;
	return 1;
}
int side_by_side_check(t_cub *main)
{
	(void)main;
	return (1);	
}
void start_parse(t_cub *main,int i,int j)
{
	(void)i;
	(void)j;
	get_loc_attr(main, 0, 0);
	if(check_if_seperated(main,0) == 1)
	{
		get_map(main,0);
		if(map_surrounding_control(main) == -1)
			printf("Map Error\n");
		//if(side_by_side_check(main) == -1)
		//	printf("sidebyside error\n");
	}
	else if(check_if_seperated(main,0) == -1)
	{
		printf("wrong seperated map.\n");
		exit(1);
		free_double_ptr(main->file);
	}

}