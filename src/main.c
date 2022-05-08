#include "cub3d.h"
#include "parsing.h"

// int	deal_key (int keycode, t_map_info *map)
// {
// 	printf ("%d\n", keycode);
// 	if (119 == keycode)
// 	{
// 		draw(map);
// 	}	
// 	if (115 == keycode)
// 	{
// 		ft_cast_ray(map);
// 	}	
// 	if (113 == keycode)
// 	{
// 		ft_cast_rays(map);
// 	}	
// 	else if (65307 == keycode)
// 	{
// 		mlx_destroy_window(map->mlx, map->mlx_win);
// 		exit(EXIT_SUCCESS);
// 	}
// 	return (0);
// }

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_cub	*cub;

	cub = parsing(argc, argv);
	print_map(cub->map);
	clean_cub(cub);
	return (0);
}
