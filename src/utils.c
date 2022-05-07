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

void	clean_config(t_config *conf)
{
	if (conf)
	{
		// if (conf->no)
		// 	free(conf->no);
		// if (conf->so)
		// 	free(conf->so);
		// if (conf->we)
		// 	free(conf->we);
		// if (conf->ea)
		// 	free(conf->ea);
	}
	free(conf);
}

void	clean_cub(t_cub *cub)
{
	if (cub->map)
		str_2d_clean(cub->map, len_2d_str(cub->map));
	if (cub->pers)
		free(cub->pers);
	clean_config(cub->config);
	if (cub->lib_mlx)
	{
		// mlx_destroy_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
		free(cub->lib_mlx);
	}
	free(cub);
}
