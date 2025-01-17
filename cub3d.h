#ifndef CUB3D_H
#define CUB3D_H

#define NO 0
#define	SO 1
#define	WE 2
#define	EA 3

#define FLOOR 4
#define COLOR 5
#define EMPTY 126

#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include "libft/libft.h"
#include "fcntl.h"

typedef struct s_cub{
	char	**file;
	char	*file_path;
	char	**map;
	char	**floor;
	char	**color;
	char	*north_img;
	char	*west_img;
	char	*south_img;
	char	*east_img;
	int		*floor_int;
	int		*color_int;
	int		map_size;
	int		map_start;
}				t_cub;

typedef struct s_tmp{
	char	*floor;
	char	*color;
}				t_tmp;

typedef struct s_point{
	int	x;
	int	y;
}				t_point;

void start_parse(t_cub *main,int i,int j);
int file_size(t_cub *main, int i);
int get_file(t_cub *main,int i);
int start_cub(char **av);
int ft_strplen(char **str);
void	f_fill(char **tab, t_point map_size, int y, int x);
char **ft_strddup(char **str,int x);

int	ft_strcmp(const char *s1, const char *s2);
int ft_exist(char *str,char a);
void get_attr(t_cub *main,char *str);
void get_loc_attr(t_cub *main,int x,int y);
int ft_map_attr_finder(char *str,char *tb_found,int i,int j);
int fill_control(char *str,char a,int i);
int get_map(t_cub *main,int i);
void start_parse(t_cub *main,int i,int j);
void make_empty(char *str);
void get_attr_floor_color(t_cub *main,char *str, char b);
int attr_digitcheck(char **str);
void attr_get_integer(t_cub *main,int type);
int get_attr_count(t_cub *main,int x);
int start_cub(char **av);
int ft_alpha_check(char *str);



#endif