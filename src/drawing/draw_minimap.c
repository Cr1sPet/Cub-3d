#include "cub3d.h"

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
	
	if ((int)cub->pers->x == x && (int)cub->pers->y == y)
	{
		color = create_rgb(0, 0, 255);
		scale = SCALE;
	}
	else if ('1' == ch) {
		color = create_rgb(255, 0, 0);
		scale = SCALE;
	}
	else
	{
		color = create_rgb(105, 105, 105);
		scale = SCALE;
	}
	x *= SCALE;
	y *= SCALE;
	draw_square2(cub, y, x, color, scale);
}

void draw_minimap(t_cub *cub)
{
	char **map = cub->map;
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			draw_square(cub, i, j, map[i][j]);
			j++;
		}
		i++;
	}
}
