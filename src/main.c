#include "cub3d.h"
#include "parsing.h"
 


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

int	ft_exit(t_cub *cub)
{
    mlx_destroy_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
    clean_cub(cub);    
    exit(0);
}

int	render(t_cub *param)
{
	draw_3d(param);
    move(param);
    print_map(param->map, param->pers->x, param->pers->y);
	return (0);
}

int mouse_hook(int x, int y, t_cub *cub)
{
    double z = (double)x;
    if (abs(x - cub->prev_x) > 10)
    {
        if (x - cub->prev_x > 0)
            z = -1 * MOUSESPEED;
        else
            z = MOUSESPEED;
        double oldDirX = cub->pers->dirX;
        cub->pers->dirX = cub->pers->dirX * cos(z) - cub->pers->dirY * sin(z);
        cub->pers->dirY = oldDirX * sin(z) + cub->pers->dirY * cos(z);
        double oldPlaneX =  cub->pers->planeX;
        cub->pers->planeX =  cub->pers->planeX * cos(z) -  cub->pers->planeY * sin(z);
        cub->pers->planeY = oldPlaneX * sin(z) + cub->pers->planeY * cos(z);
        cub->prev_z = z;
    }
    else if (x == cub->prev_x)
    {
        double oldDirX = cub->pers->dirX;
        cub->pers->dirX = cub->pers->dirX * cos(cub->prev_z) - cub->pers->dirY * sin( cub->prev_z);
        cub->pers->dirY = oldDirX * sin(cub->prev_z) + cub->pers->dirY * cos( cub->prev_z);
        double oldPlaneX =  cub->pers->planeX;
        cub->pers->planeX =  cub->pers->planeX * cos( cub->prev_z) -  cub->pers->planeY * sin( cub->prev_z);
        cub->pers->planeY = oldPlaneX * sin( cub->prev_z) + cub->pers->planeY * cos( cub->prev_z);
    }
    cub->prev_x = x;
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = parsing(argc, argv);
    cub->x = 0;
    mlx_hook(cub->lib_mlx->mlx_win, 17, 0, ft_exit, cub);
    mlx_hook(cub->lib_mlx->mlx_win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->lib_mlx->mlx_win, 3, 1L << 1, key_release, cub);
	mlx_hook(cub->lib_mlx->mlx_win, 6, 0, mouse_hook, cub);
    mlx_mouse_hide();
    mlx_loop_hook(cub->lib_mlx->mlx, &render, (void *) cub);
	mlx_loop(cub->lib_mlx->mlx);
	clean_cub(cub);
	return (0);
}
