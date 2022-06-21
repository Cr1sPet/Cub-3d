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

void	print_map(char **map, int k, int q)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
        j = 0;
        while (map[i][j])
        {
            if (k == i && q == j)
            {
                     ft_putchar_fd('P', 1);
            }
            else {
                ft_putchar_fd(map[i][j], 1);
            }
           
           j++;
        }
		ft_putchar_fd('\n', 1);
		i++;
	}
}
int	ft_exit(void)
{
    exit(0);
}

int	key_hook (int keycode, t_cub *cub)
{
    printf("%d\n", keycode);
    double moveSpeed = 0.1; //the constant value is in squares/second
    if (13 == keycode)
    {
        if(cub->map[(int)(cub->pers->x + cub->pers->dirX * moveSpeed)][(int)cub->pers->y]  == '0')
        {
           cub->pers->x += cub->pers->dirX * moveSpeed;
        }
        if (cub->map[(int)cub->pers->x][(int)(cub->pers->y + cub->pers->dirY * moveSpeed)]  == '0')
        {
            cub->pers->y += cub->pers->dirY * moveSpeed;
        }  
    }
    if (1 == keycode)
    {
        if(cub->map[(int)(cub->pers->x - cub->pers->dirX * moveSpeed)][(int)cub->pers->y]  == '0')
        {
            cub->pers->x -= cub->pers->dirX * moveSpeed;
        } 
        if (cub->map[(int)cub->pers->x][(int)(cub->pers->y - cub->pers->dirY * moveSpeed)] == '0')
        {
            cub->pers->y -= cub->pers->dirY * moveSpeed;
        }  
    }
    if (0 == keycode || 123 == keycode)
    {
        double oldDirX = cub->pers->dirX;
        cub->pers->dirX = cub->pers->dirX * cos(-0.035) - cub->pers->dirY * sin(-0.035);
        cub->pers->dirY = oldDirX * sin(-0.035) + cub->pers->dirY * cos(-0.035);
        double oldPlaneX =  cub->pers->planeX;
        cub->pers->planeX =  cub->pers->planeX * cos(-0.035) -  cub->pers->planeY * sin(-0.035);
        cub->pers->planeY = oldPlaneX * sin(-0.035) + cub->pers->planeY * cos(-0.035);
    }
    if (2 == keycode || 124 == keycode)
    {
        double oldDirX = cub->pers->dirX;
        cub->pers->dirX = cub->pers->dirX * cos(0.035) - cub->pers->dirY * sin(0.035);
        cub->pers->dirY = oldDirX * sin(0.035) + cub->pers->dirY * cos(0.035);
        double oldPlaneX =  cub->pers->planeX;
        cub->pers->planeX =  cub->pers->planeX * cos(0.035) -  cub->pers->planeY * sin(0.035);
        cub->pers->planeY = oldPlaneX * sin(0.035) + cub->pers->planeY * cos(0.035);
    }
    else if (53 == keycode)
    {
        mlx_destroy_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
        exit(EXIT_SUCCESS);
    }
       print_map(cub->map,  (int)cub->pers->x, (int)cub->pers->y);
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
    mlx_hook(cub->lib_mlx->mlx_win, 2, 1L << 0, key_hook, cub);
	// mlx_key_hook (cub->lib_mlx->mlx_win, key_hook, cub);
    mlx_loop_hook(cub->lib_mlx->mlx, &render, (void *) cub);
    // draw_3d(cub);
	mlx_loop(cub->lib_mlx->mlx);
	// clean_cub(cub);
	return (0);
}
