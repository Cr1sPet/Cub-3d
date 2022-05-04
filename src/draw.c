#include "cub3d.h"

void put_pixel(int x, int y, t_map_info *map)
{
	int		i;
	char	*dst;
	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		dst = map->data_addr + (y * map->line_length + x * (map->bits_per_pixel / 8));
		*(unsigned int*)dst = 0x00FF0000;
	}
}


void	ft_cast_rays(t_map_info *map)
{
	map->start = 0.52 - 0.3;
	map->end = 0.52 + 0.3;

	ft_bzero(map->data_addr, 1920 * 1080 * (map->bits_per_pixel / 8));
	int SCALE = 3;
	int	x_start = 10;
	int	y_start = 100;

  	while (map->start <= map->end)
	{
		map->x = x_start;
		map->y = y_start;

		while (map->parsed_map[(int)(map->y / SCALE)][(int)(map->x / SCALE)] != '1')
		{
			map->x += cos(map->start);
			map->y += sin(map->start);
			put_pixel(map->x, map->y, map);

		}
		map->start += 0.6 / 10;
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 0, 0);

}

void	ft_cast_ray(t_map_info *map)
{
	int SCALE = 3;

	map->x = 50;
	map->y = 100;
	map->dir = 0.52;

	ft_bzero(map->data_addr, 1920 * 1080 * (map->bits_per_pixel / 8));

	while (map->parsed_map[(int)(map->y / SCALE)][(int)(map->x / SCALE)] != '1')
	{
		map->x += cos(map->dir);
		map->y += sin(map->dir);
		put_pixel(map->x, map->y, map);
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 0, 0);

}

void	draw (t_map_info *map)
{
	int	x;
	int	y;

	y = 0;
	static int hu = 10;
	ft_bzero(map->data_addr, 1920 * 1080 * (map->bits_per_pixel / 8));

	for (int i = 0; i < 1920; i++) {
		put_pixel(i, hu + 100, map);
	}
	hu += 50;
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, 0, 0);
}
