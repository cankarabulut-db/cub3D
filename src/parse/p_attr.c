#include "../cub3d.h"

void get_attr(t_cub *main,char *str)
{
	int true;

	true = 1;
	while (*str == ' ' && *str)
    	str++;
	if((str[0] == 'F' && str[1] == ' ' ) && ++true)
		get_attr_floor_color(main,str,FLOOR);
	else if((str[0] == 'C' && str[1] == ' ') && ++true)
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

void free_attr(t_cub *main)
{
	if(main->floor)
		free_double_ptr(main->floor);
	if(main->color)
		free_double_ptr(main->color);
	if(main->east_img)
		free(main->east_img);
	if(main->west_img)
		free(main->west_img);
	if(main->south_img)
		free(main->south_img);
	if(main->north_img)
		free(main->north_img);
	main->floor = NULL;
	main->color = NULL;
	main->east_img = NULL;
	main->west_img = NULL;
	main->south_img = NULL;
	main->north_img = NULL;
}

int get_loc_attr(t_cub *main,int x,int y)
{
	y = get_attr_count(main,-1);
	if(y != 6)
		return (0);
	while(main->file[x])
		get_attr(main,main->file[x++]);
	if(!extension_checker(main->south_img) || !extension_checker(main->west_img)
		|| !extension_checker(main->east_img) || !extension_checker(main->north_img)
		|| attr_digitcheck(main->floor) == -1 || ft_strplen(main->floor) != 3)
	{
		free_attr(main);
		return (0);
	}
	//printf("Floor: %s\n",main->floor[0]);
	//printf("Floor: %s\n",main->floor[1]);
	//printf("Floor: %s\n",main->floor[2]);
	//printf("Color: %s\n",main->color[0]);
	//printf("Color: %s\n",main->color[1]);
	//printf("Color: %s\n",main->color[2]);
	//printf("East: %s\n",main->east_img);
	//printf("West: %s\n",main->west_img);
	//printf("South: %s\n",main->south_img);
	//printf("North: %s\n",main->north_img);
	return (1);
}

int get_attr_count(t_cub *main,int x)
{
	static		int control;

	while(main->file[++x])
	{
		if (*main->file[x] == ' ')
    		main->file[x]++;
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