#include "../cub3d.h"

void get_attr(t_cub *main,char *str)
{
	int true;
	int i;

	i = 0;
	true = 1;
	while((str[i] == ' ' || str[i] == '\t' ) && str[i] != '\0')
		i++;
	if((str[i] == 'F' && str[i + 1] == ' ' ) && ++true)
		get_attr_floor_color(main,str,FLOOR);
	else if((str[i] == 'C' && str[i + 1] == ' ') && ++true)
		get_attr_floor_color(main,str,COLOR);
	else if((str[i] == 'W' && str[i + 1] == 'E') && ++true)
		main->west_img = ft_strtrim(str + 2, " \n \t");
	else if((str[i] == 'E' && str[i + 1] == 'A') && ++true)
		main->east_img = ft_strtrim(str + 2, " \n \t");
	else if((str[i] == 'S' && str[i + 1] == 'O') && ++true)
		main->south_img = ft_strtrim(str + 2, " \n \t");
	else if((str[i] == 'N' && str[i + 1] == 'O') && ++true)
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
	free_color_floor(main->color_int);
	free_color_floor(main->floor_int);
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
		|| !attr_digitcheck(main->floor) || ft_strplen(main->floor) != 3
		|| ft_strplen(main->color) != 3 || !attr_digitcheck(main->color))
	{
		free_attr(main);
		return (0);
	}
	printf("Floor: %s\n",main->floor[0]);
	printf("Floor: %s\n",main->floor[1]);
	printf("Floor: %s\n",main->floor[2]);
	printf("Color: %s\n",main->color[0]);
	printf("Color: %s\n",main->color[1]);
	printf("Color: %s\n",main->color[2]);
	printf("East: %s\n",main->east_img);
	printf("West: %s\n",main->west_img);
	printf("South: %s\n",main->south_img);
	printf("North: %s\n",main->north_img);
	return (1);
}

int get_attr_count(t_cub *main,int x)
{
	static		int control;
	int i;

	i = 0;
	while(main->file[++x])
	{
		while((main->file[x][i] == ' ' || main->file[x][i] == '\t') && main->file[x][i] == '\0')
			i++;
		if(main->file[x][i] == 'F')
			control++;
		else if(main->file[x][i] == 'C' && main->file[x][i + 1] == ' ')
			control++;
		else if((main->file[x][i] == 'W' && main->file[x][i + 1] == 'E') && main->file[x][i + 2] == ' ')
			control++;
		else if((main->file[x][i] == 'E' && main->file[x][i + 1] == 'A') && main->file[x][i + 2] == ' ')
			control++;
		else if((main->file[x][i] == 'S' && main->file[x][i + 1] == 'O') && main->file[x][i + 2] == ' ')
			control++;
		else if((main->file[x][i] == 'N' && main->file[x][i + 1] == 'O') && main->file[x][i + 2] == ' ')
			control++;
	}
	return control;
}

void attr_get_integer(t_cub *main,int type)
{
	if(type == COLOR)
	{
		main->color_int = malloc(sizeof(int) * (3));
		if(ft_strplen(main->color) != 3)
			return ;
		main->color_int[0] = ft_atoi(main->color[0]);
		main->color_int[1] = ft_atoi(main->color[1]);
		main->color_int[2] = ft_atoi(main->color[2]);
	}
	else if(type == FLOOR)
	{
		main->floor_int = malloc(sizeof(int) * (3));
		if(ft_strplen(main->floor) != 3)
			return ;
		main->floor_int[0] = ft_atoi(main->floor[0]);
		main->floor_int[1] = ft_atoi(main->floor[1]);
		main->floor_int[2] = ft_atoi(main->floor[2]);
	}
}