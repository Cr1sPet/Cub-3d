#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include "../libft/libft.h"

# define MALLOC_FAILURE "Error\nmalloc() returned NULL"

# define WIDTH 1920
# define HEIGHT 1080
# define SCALE 15
# define FORWARD 1
# define BACKWARD 0
# define CHARACTER_SIZE 5

typedef struct s_config
{
	int		width;
	int		height;
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	int		c;
	int		f;
}				t_config;

typedef struct s_pers_pos
{
	int		x;
	int		y;
	char	side;
	double	alpha;
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

typedef struct s_cub
{
	char		**map;
	int			map_len;
	t_pers_pos	*pers;
	t_config	*config;
	t_mlx		*lib_mlx;
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
void draw(t_cub *cub);
int	create_rgb(int r, int g, int b);
void draw_3d(t_cub *cub);
void put_pixel(int x, int y, t_mlx *lib_mlx, int color);

#endif