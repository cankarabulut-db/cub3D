#include "../cub3d.h"

void free_color_floor(int *color_floor)
{
	if(color_floor)
		free(color_floor);
	color_floor = NULL;
}