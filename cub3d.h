#ifndef CUB3D_H
#define CUB3D_H

#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"
#include "fcntl.h"

typedef struct s_cub{
	char	**map;
	char	*file_path;
	int		map_size;
}				t_cub;

void start_parse(t_cub *main,int i,int j);
int file_size(t_cub *main, int i);
int get_file(t_cub *main,int i);
int start_cub(char **av);


#endif