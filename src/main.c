#include "../includes/cub3d.h"

//void	print_map(char **map)
//{
//	int	i;
//	int	j;
//
//	i = 0;
//	while (map[i])
//	{
//		ft_putstr_fd(map[i], 1);
//		ft_putchar_fd('\n', 1);
//		i++;
//	}
//}

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
    cub->lib_mlx = mlx_init();
    cub->lib_mlx->mlx_win = mlx_new_window( cub->lib_mlx, cub->config->width, cub->config->height, "Cub 3D");
    int y = 0;
    int x;
    while (cub->map[++y])
    {
        x = 0;
        while (cub->map[y][++x])
        {
            int j = 0;
            int k;
            while (++j < 10)
            {
                k = 0;
                while(++k < 10)
                {
                    mlx_pixel_put(cub->lib_mlx, cub->lib_mlx->mlx_win, j * y, k * x, 0x990099);
                }
            }
        }
    }
    mlx_hook(cub->lib_mlx->mlx_win, 2, 1L << 0, key_hook, &cub->lib_mlx);
    mlx_loop( cub->lib_mlx);
	return (0);
}
