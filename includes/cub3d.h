#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
#include <time.h>
# include "../libft/libft.h"


# define MALLOC_FAILURE "Error\nmalloc() returned NULL"

# define WIDTH 1200
# define HEIGHT 800
# define SCALE 5
# define CHARACTER_SIZE 5
# define MOVESPEED 0.1
# define MOUSESPEED 0.05
# define ROTATESPEED 0.1

typedef struct s_texture
{
	int			width;
	int			height;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct s_config
{
	t_texture	*no_texture;
	t_texture	*so_texture;
	t_texture	*we_texture;
	t_texture	*ea_texture;
	int		c;
	int		f;
	int		map_length;
	double wall_x;
}				t_config;

typedef struct s_pers_pos
{
	double		x;
	double		y;
	char	side;
	double	dirX;
	double	dirY;
	double planeX;
	double planeY;
}				t_pers_pos;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct s_key
{
	int		w;
	int		s;
	int		a;
	int		d;
}				t_key;

typedef struct s_cub
{
	int			x;
	int			prev_x;
	double 		prev_z;
	char		**map;
	int			map_len;
	t_pers_pos	*pers;
	t_config	*config;
	t_mlx		*lib_mlx;
	t_key		*key;
}				t_cub;

t_cub	*parsing(int argc, char **argv);

int		len_2d_str(char **str);
void	str_2d_clean(char **s, size_t l);
// void	ft_cast_ray(t_cub *map);
void	ft_cast_rays(t_cub *map);
void	clear_str_arr(char	**arr);
void	clear_int_arr(int **arr, int len);
size_t	count_words(char const *str, char c);

void	clean_cub(t_cub *cub);
void	clean_config(t_config *conf, t_cub *cub);
void	exit_with_error(char *message, t_cub *cub);

//draw
void    draw_3d(t_cub *cub);
void draw_minimap(t_cub *cub);
int	create_rgb(int r, int g, int b);
void put_pixel(int x, int y, t_mlx *lib_mlx, int color);
// void draw_3d(t_cub *cub);

//move
int key_press(int keycode, t_cub *cub);
int key_release(int keycode, t_cub *cub);

void move(t_cub *cub);
int	ft_exit(t_cub *cub);
#endif