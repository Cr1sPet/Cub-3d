#include "cub3d.h"
#include "parsing.h"

int	deal_key (int keycode, t_map_info *map)
{
	printf ("%d\n", keycode);
	if (119 == keycode)
	{
		draw(map);
	}	
	if (115 == keycode)
	{
		ft_cast_ray(map);
	}	
	if (113 == keycode)
	{
		ft_cast_rays(map);
	}	
	else if (65307 == keycode)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}


void	init_map (t_map_info *map)
{
	map->mlx = mlx_init ();
	map->mlx_win = mlx_new_window (map->mlx, 1920, 1080, "Cub-3d");
	map->img = mlx_new_image(map->mlx, 1920, 1080);
	map->data_addr = mlx_get_data_addr(map->img, &(map->bits_per_pixel),&(map->line_length), &(map->endian));
}

int	main(int argc, char **argv)
{
	t_map_info	*map;
	parsing(argc, argv, map);
	// t_map_info	map;

	// map.parsed_map = make_map(argv[1]);
	// init_map (&map);
	// draw (&map);
	// mlx_key_hook (map.mlx_win, deal_key, &map);
	// mlx_loop(map.mlx);
	return (0);
}
