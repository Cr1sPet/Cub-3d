#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		ok_color;
}	t_point;

typedef struct s_map_info
{
	double		x;
	double		y;
	double		start;
	double		end;
	double		dir;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**parsed_map;
}				t_map_info;

int		parsing(char *arg);
char	**make_map(char *arg);
void	ft_cast_ray(t_map_info *map);
void	ft_cast_rays(t_map_info *map);
void	clear_str_arr(char	**arr);
void	clear_int_arr(int **arr, int len);
char	*get_next_line(int fd);
size_t	count_words(char const *str, char c);
void	draw (t_map_info *map);
t_point	get_point (float x, float y, t_map_info *map);

#endif