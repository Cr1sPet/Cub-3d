#include "cub3d.h"
#include "parsing.h"




int	check_step_x(t_pers_pos *perse, int sign, t_cub *cub)
{
	int x = perse->x;
	int y = perse->y;

	if (sign && cub->map[y][x + 1] != '1')
		return (1);
	if (!sign && cub->map[y][x - 1] != '1')
		return (1);
	return (0);
}


int	check_step_y(t_pers_pos *perse, int sign, t_cub *cub)
{
	int x = perse->x;
	int y = perse->y;

	if (sign && cub->map[y - 1][x] != '1')
		return (1);
	if (!sign && cub->map[y + 1][x] != '1')
		return (1);
	return (0);
}

int	key_hook (int keycode, t_cub *cub)
{
	printf ("%d\n", keycode);
	if (13 == keycode)
	{
		if (check_step_y(cub->pers, FORWARD, cub))
		{
			cub->pers->y -= 1;
			draw(cub);
		}
	}
	if (1 == keycode)
	{
		if (check_step_y(cub->pers, BACKWARD, cub))
		{
			cub->pers->y += 1;
			draw(cub);
		}
	}
	if (0 == keycode)
	{
		if (check_step_x(cub->pers, BACKWARD, cub))
		{
			cub->pers->x -= 1;
			draw(cub);
		}
	}
	if (2 == keycode)
	{
		if (check_step_x(cub->pers, FORWARD, cub))
		{
			cub->pers->x += 1;
			draw(cub);
		}
	}
	if (123 == keycode)
	{
		cub->pers->alpha -= 0.4;
		draw(cub);
	}
	if (124 == keycode)
	{
		cub->pers->alpha += 0.4;
		draw(cub);
	}
	else if (53 == keycode)
	{
		mlx_destroy_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = parsing(argc, argv);
    draw(cub);
    draw_3d(cub);
    mlx_key_hook (cub->lib_mlx->mlx_win, key_hook, cub);
    mlx_loop( cub->lib_mlx);
//    clean_cub(cub);
//=======
//	printf("%d, %d\n", cub->pers->x, cub->pers->y);
//	print_map(cub->map);
//	draw(cub);
//	mlx_key_hook (cub->lib_mlx->mlx_win, deal_key, cub);
//	mlx_loop(cub->lib_mlx->mlx);

//>>>>>>> parsing
	return (0);
}
