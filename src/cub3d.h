#ifndef CUB3D_H
#define CUB3D_H

#define NO 0
#define	SO 1
#define	WE 2
#define	EA 3
#define PARSE_WALL '*'

#define FLOOR 4
#define COLOR 5
#define EMPTY 1

#include "../get_next_line/get_next_line.h"
#include <stdio.h>
#include "../libft/libft.h"
#include "fcntl.h"

typedef struct s_cub{
	char	**file;
	char	*file_path;
	char	**map;
	char	**multiple_map;
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
	int		char_x;
	int		char_y;
	char	perspective;
}				t_cub;

typedef struct s_tmp{
	char	*floor;
	char	*color;
}				t_tmp;

int side_by_side_check(t_cub *main);
char **surrounded_map(t_cub *main);
int check_multimap(char **map);
void string_filler(char *str,char *map,int longest);
void fill_string(char *wall_map,int longest);
int extension_checker(char *str);
int walkability_check(t_cub *main,int x,int y);
int ft_check(char **sur, int y,int x);
void start_parse(t_cub *main,int i,int j);
int player_loc_check(char a);
int map_size(t_cub *main, int i);
void free_color_floor(int *color_floor);
int get_file(t_cub *main,int i);
int start_cub(char **av);
int ft_strplen(char **str);
char **ft_strddup(char **str,int x);
int	free_double_ptr(char **str);
void flood_fill(char **map, int x, int y);
void free_attr(t_cub *main);
int find_the_player_loc(t_cub *main,char **str);
int	ft_strcmp(const char *s1, const char *s2);
int ft_exist(char *str,char a);
void get_attr(t_cub *main,char *str);
int get_loc_attr(t_cub *main,int x,int y);
int ft_map_attr_finder(char *str,char *tb_found,int i,int j);
int check_if_seperated(t_cub *main,int i);
int find_the_longest(char **str);
int fill_control(char *str,char a,int i);
void error_write_nfree(char *str);
void s_init(t_cub *main);
int get_map(t_cub *main,int i);
void start_parse(t_cub *main,int i,int j);
void make_empty(char *str);
void get_attr_floor_color(t_cub *main,char *str, char b);
int content_control(t_cub *main,int x,int y,int flag);
int attr_digitcheck(char **str);
void attr_get_integer(t_cub *main,int type);
int get_attr_count(t_cub *main,int x);
int start_cub(char **av);
int ft_alpha_check(char *str);



#endif