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
	return (1);
}

int	ft_exit(void)
{
    exit(0);
}

int	key_hook (int keycode, t_cub *cub)
{
    printf ("%d\n", keycode);
    if (13 == keycode)
    {
//        if (check_step_y(cub->pers, FORWARD, cub))
//        {
            cub->pers->y -= 1;
//        }
    }
    if (1 == keycode)
    {
//        if (check_step_y(cub->pers, BACKWARD, cub))
//        {
            cub->pers->y += 1;
//        }
    }
    if (0 == keycode)
    {
//        if (check_step_x(cub->pers, BACKWARD, cub))
//        {
            cub->pers->x -= 1;
//        }
    }
    if (2 == keycode)
    {
//        if (check_step_x(cub->pers, FORWARD, cub))
//        {
            cub->pers->x += 1;
//        }
    }
    if (123 == keycode)
    {
        cub->pers->alpha -= 0.4;
    }
    if (124 == keycode)
    {
        cub->pers->alpha += 0.4;
    }
    else if (53 == keycode)
    {
        mlx_destroy_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
        exit(EXIT_SUCCESS);
    }
    return (0);
}

// int	key_hook (int keycode, t_cub *cub)
// {
//     printf ("%d\n", keycode);
//     if (119 == keycode)
//     {
// //        if (check_step_y(cub->pers, FORWARD, cub))
// //        {
//             cub->pers->y -= 1;
// //        }
//     }
//     if (115 == keycode)
//     {
// //        if (check_step_y(cub->pers, BACKWARD, cub))
// //        {
//             cub->pers->y += 1;
// //        }
//     }
//     if (97 == keycode)
//     {
// //        if (check_step_x(cub->pers, BACKWARD, cub))
// //        {
//             cub->pers->x -= 1;
// //        }
//     }
//     if (100 == keycode)
//     {
// //        if (check_step_x(cub->pers, FORWARD, cub))
// //        {
//             cub->pers->x += 1;
// //        }
//     }
//     if (65361 == keycode)
//     {
//         cub->pers->alpha -= 0.4;
//     }
//     if (65363 == keycode)
//     {
//         cub->pers->alpha += 0.4;
//     }
//     else if (65307 == keycode)
//     {
//         mlx_destroy_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
//         exit(EXIT_SUCCESS);
//     }
//     return (0);
// }

// void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		ft_putstr_fd(map[i], 1);
// 		ft_putchar_fd('\n', 1);
// 		i++;
// 	}
// }

int	render(void *param)
{
	draw_3d(param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = parsing(argc, argv);
    mlx_hook(cub->lib_mlx->mlx_win, 17, 0, ft_exit, &cub);
	mlx_key_hook (cub->lib_mlx->mlx_win, key_hook, cub);
    mlx_loop_hook(cub->lib_mlx->mlx, &render, (void *) cub);
	mlx_loop(cub->lib_mlx->mlx);
	// clean_cub(cub);
	return (0);
}
