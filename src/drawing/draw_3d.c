#include "cub3d.h"

void	ft_cast_rays(t_cub *cub)
{
	t_pers_pos	ray = *cub->pers;// задаем координаты и направление луча равные координатам игрока
	float start = ray.alpha - 90; // начало веера лучей
    float end = ray.alpha + 90; // край веера лучей

  while (cub->start <= cub->end)
	{
		ray.x = cub->pers->x; // каждый раз возвращаемся в точку начала
		ray.y = cub->pers->y; 
        while (cub->map[(int) ray.y / SCALE][(int) ray.x / SCALE] != '1')
		{
			ray.x += cos(cub->start);
			ray.y += sin(cub->start);
			mlx_pixel_put(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, ray.x, ray.y, 0x990099);
		}
		cub->start += 90 / 3;
	}
}

void draw_3d(t_cub *cub)
{
    double planeX = 0, planeY = 0.66;
	// ft_bzero(cub->lib_mlx->data_addr, WIDTH * HEIGHT * (cub->lib_mlx->bits_per_pixel / 8));
    ft_cast_rays(cub);
	// mlx_put_image_to_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, cub->lib_mlx->img, 0, 0);
}