#include "../includes/cub3d.h"

//<<<<<<< HEAD

//=======
//int	deal_key (int keycode, t_cub *cub)
//{
//	printf ("%d\n", keycode);
//	if (119 == keycode)
//	{
//		// if (cub->pers->x >= SCALE)
//		// {
//			cub->pers->y -= 1;
//			draw(cub);
//		// }
//	}
//	if (115 == keycode)
//	{
//		// if (cub->pers->x >= SCALE)
//		// {
//			cub->pers->y += 1;
//			draw(cub);
//		// }
//	}
//	if (97 == keycode)
//	{
//		cub->pers->x -= 1;
//		draw(cub);
//	}
//	if (100 == keycode)
//	{
//		// if (cub->pers->x <= HEIGHT - SCALE)
//		// {
//			cub->pers->x += 1;
//			draw(cub);
//		// }
//	}
//	else if (65307 == keycode)
//	{
//		mlx_destroy_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
//		exit(EXIT_SUCCESS);
//	}
//	return (0);
//}
//>>>>>>> parsing

int	key_hook(int keycode)
{
    if (keycode == 53)
        exit(0);
    return (1);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = parsing(argc, argv);
    draw(cub);
    mlx_hook(cub->lib_mlx->mlx_win, 2, 1L << 0, key_hook, &cub->lib_mlx);
    mlx_loop( cub->lib_mlx);
    clean_cub(cub);
//=======
//	printf("%d, %d\n", cub->pers->x, cub->pers->y);
//	print_map(cub->map);
//	draw(cub);
//	mlx_key_hook (cub->lib_mlx->mlx_win, deal_key, cub);
//	mlx_loop(cub->lib_mlx->mlx);

//>>>>>>> parsing
	return (0);
}
