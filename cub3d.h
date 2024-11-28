#ifndef CUB3D_H
#define CUB3D_H

#define NO 0
#define	SO 1
#define	WE 2
#define	EA 3

#define FLOOR 4
#define COLOR 5

#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"
#include "fcntl.h"

typedef struct s_cub{
	char	**file;
	char	*file_path;
	char	**floor;
	char	**color;
	char	*north_img;
	char	*west_img;
	char	*south_img;
	char	*east_img;
	int		*floor_int;
	int		*color_int;
	int		map_size;
}				t_cub;

typedef struct s_tmp{
	char	*floor;
	char	*color;
}				t_tmp;

void start_parse(t_cub *main,int i,int j);
int file_size(t_cub *main, int i);
int get_file(t_cub *main,int i);
int start_cub(char **av);

int	ft_strcmp(const char *s1, const char *s2);
int ft_exist(char *str,char a);



#endif