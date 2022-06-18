#include "cub3d.h"


typedef struct s_point
{
	double x;
	double y;
}				t_point;


void put_pixel(int x, int y, t_mlx *lib_mlx, int color)
{
	char	*dst;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = lib_mlx->data_addr + (y * lib_mlx->line_length + x * (lib_mlx->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

float	get_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	get_abs(float num)
{
	if (num >= 0)
		return (num);
	else
		return (-num);
}

void	draw_line(t_point point, t_point point1, t_mlx *lib_mlx)
{
	float	max;
	float	x_step;
	float	y_step;
	int		color = create_rgb(0, 0, 255);

	x_step = (point1.x - point.x);
	y_step = (point1.y - point.y);
	max = get_max (get_abs(x_step), get_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(point.x - point1.x) || (int)(point.y - point1.y))
	{
        put_pixel((int) point.x, (int) point.y, lib_mlx, color);
		point.x += x_step;
		point.y += y_step;
	}
}

void	ft_cast_ray(t_cub *cub, int color)
{
//    t_pers_pos plr = *cub->pers;
//
//    while (cub->map[(int) plr.y / SCALE][(int) plr.x / SCALE] != '1')
//    {
//        plr.x += cos(plr.alpha);
//        plr.y += sin(plr.alpha);
//        mlx_pixel_put(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, plr.x, plr.y, 0x990099);
//    }
//    printf("%d  x\n %d y\n %f alpha \n", plr.x, plr.y, plr.alpha);
	t_point	point1;
	t_point	point2;
    double x = cub->pers->x;
    double y = cub->pers->y;
    point1.x = x * SCALE;
    point1.y = y * SCALE;
    while (cub->map[(int) point2.x / SCALE][(int) point2.y / SCALE] != '1')
    {
//        x += cos(cub->pers->alpha);
//        y += sin(cub->pers->alpha);
        point2.x = (x) * SCALE;
        point2.y = (y) * SCALE;
        draw_line(point1, point2, cub->lib_mlx);
    }
}


void draw_square2(t_cub *cub, int x, int y, int color, int scale) {
	for (int i = 0; i < scale; i++) {
		for (int j = 0; j < scale; j++) {
            put_pixel(x + i, y + j, cub->lib_mlx, color);
	}
}
}

void draw_square(t_cub *cub, int x, int y, char ch)
{
	int	color;
	int scale;
	
	if (cub->pers->x == x && cub->pers->y == y)
	{
		color = create_rgb(0, 0, 255);
		scale = CHARACTER_SIZE;
	}
	else if ('1' == ch) {
		color = create_rgb(255, 0, 0);
		scale = SCALE;
	}
	else
		return;
	x *= SCALE;
	y *= SCALE;
	draw_square2(cub, x, y, color, scale);
}

void draw_2d(t_cub *cub)
{
	char **map = cub->map;
	int map_length = len_2d_str(map);
	
	int	i;
	int	j;

	i = 0;
	while (i < map_length)
	{
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			draw_square(cub, j, i, map[i][j]); 
//			ft_cast_ray(cub, create_rgb(0, 0, 255));
			j++;
		}
		i++;
	}
}

void draw(t_cub *cub)
{
    ft_bzero(cub->lib_mlx->data_addr, WIDTH * HEIGHT * (cub->lib_mlx->bits_per_pixel / 8));
//    mlx_clear_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
	draw_2d(cub);
//    draw_3d(cub);
	mlx_put_image_to_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, cub->lib_mlx->img, 0, 0);
}