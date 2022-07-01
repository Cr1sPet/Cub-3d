/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:20:53 by spurple           #+#    #+#             */
/*   Updated: 2022/06/28 21:40:34 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	(void) cub;
	if (conf)
	{
		if (conf->no_texture)
		{
			free(conf->no_texture->path);
			// mlx_destroy_image(cub->lib_mlx->mlx, conf->no_texture->img);
			free(conf->no_texture);
		}
		if (conf->so_texture)
		{
			free(conf->so_texture->path);
			// mlx_destroy_image(cub->lib_mlx->mlx, conf->so_texture->img);
			free(conf->so_texture);
		}
		if (conf->we_texture)
		{
			free(conf->we_texture->path);
			// mlx_destroy_image(cub->lib_mlx->mlx, conf->we_texture->img);
			free(conf->we_texture);
		}
		if (conf->ea_texture)
		{
			free(conf->ea_texture->path);
			// mlx_destroy_image(cub->lib_mlx->mlx, conf->ea_texture->img);
			free(conf->ea_texture);
		}
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
		if (cub->lib_mlx->mlx && cub->lib_mlx->mlx_win)
		{
			mlx_destroy_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win);
		}
		free(cub->lib_mlx);
	}
	if (cub->dda)
		free(cub->dda);
	if (cub->key)
		free(cub->key);
	free(cub);
}
