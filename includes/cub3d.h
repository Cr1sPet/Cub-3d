#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
#include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include "../libft/libft.h"

# define MALLOC_FAILURE "Error\nmalloc() returned NULL"

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
	double		x;
	double		y;
	double		start;
	double		end;
	double		dir;
	char		**map;
	t_pers_pos	*pers;
	t_config	*config;
	t_mlx		*lib_mlx;
}				t_cub;

t_cub	*parsing(int argc, char **argv);

int		len_2d_str(char **str);
void	str_2d_clean(char **s, size_t l);
void	ft_cast_ray(t_cub *map);
void	ft_cast_rays(t_cub *map);
void	clear_str_arr(char	**arr);
void	clear_int_arr(int **arr, int len);
size_t	count_words(char const *str, char c);
void	draw (t_cub *map);

void	clean_cub(t_cub *cub);
void	clean_config(t_config *conf);
void	exit_with_error(char *message, t_cub *cub);

#endif