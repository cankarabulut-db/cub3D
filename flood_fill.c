#include "cub3d.h"

void	f_fill(char **tab, t_point map_size, int y, int x)
{
	if (y < 0 || x < 0)
		return ;
	if (y >= map_size.y || x >= map_size.x)
		return ;
	if (tab[y][x] == '*' || tab[y][x] == '1')
		return ;
	tab[y][x] = '*';
	f_fill(tab, map_size, y - 1, x);
	f_fill(tab, map_size, y + 1, x);
	f_fill(tab, map_size, y, x - 1);
	f_fill(tab, map_size, y, x + 1);
}