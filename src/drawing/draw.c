#include "cub3d.h"

void put_pixel(int x, int y, t_mlx *lib_mlx, int color)
{
	int		i;
	char	*dst;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = lib_mlx->data_addr + (y * lib_mlx->line_length + x * (lib_mlx->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void draw_square(t_cub *cub, int x, int y, char ch)
{
	int	color;
    int ok = 1;
	if (cub->pers->x == x && cub->pers->y == y) {
        color = create_rgb(0, 0, 255);
        ok = 0;
    }
	else if ('1' == ch) {
        color = create_rgb(255, 0, 0);
        ok = 0;
    }
	x *= SCALE;
	y *= SCALE;
    if (ok == 0 ) {
        for (int i = 0; i < SCALE; i++) {
            for (int j = 0; j < SCALE; j++) {
                put_pixel(x + i, y + j, cub->lib_mlx, color);
            }
        }
    }

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
			j++;
		}
		i++;
	}
}




void draw(t_cub *cub)
{
	ft_bzero(cub->lib_mlx->data_addr, WIDTH * HEIGHT * (cub->lib_mlx->bits_per_pixel / 8));
	draw_2d(cub);
	mlx_put_image_to_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, cub->lib_mlx->img, 0, 0);
}