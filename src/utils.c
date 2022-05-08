#include "cub3d.h"


int	len_2d_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	str_2d_clean(char **s, size_t l)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (i < l)
		{
			free (s[i]);
			i++;
		}
		free (s);
	}
}

void	exit_with_error(char *message, t_cub *cub)
{
	ft_putendl_fd(message, STDOUT_FILENO);
	clean_cub(cub);
	exit(EXIT_FAILURE);
}

void	clean_config(t_config *conf, t_cub *cub)
{
	if (conf)
	{
		if (conf->no_img)
			mlx_destroy_image(cub->lib_mlx->mlx, conf->no_img);
		if (conf->so_img)
			mlx_destroy_image(cub->lib_mlx->mlx, conf->so_img);
		if (conf->we_img)
			mlx_destroy_image(cub->lib_mlx->mlx, conf->we_img);
		if (conf->ea_img)
			mlx_destroy_image(cub->lib_mlx->mlx, conf->ea_img);
	}
	free(conf);
}

void	clean_cub(t_cub *cub)
{
	if (cub->map)
		str_2d_clean(cub->map, len_2d_str(cub->map));
	if (cub->pers)
		free(cub->pers);
	clean_config(cub->config, cub);
	if (cub->lib_mlx)
	{
		// free(cub->lib_mlx->mlx);
		// mlx_destroy_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
		free(cub->lib_mlx);
	}
	free(cub);
}
