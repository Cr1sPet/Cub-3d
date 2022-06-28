/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spurple <spurple@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:26:45 by spurple           #+#    #+#             */
/*   Updated: 2022/06/28 19:44:46 by spurple          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_w(t_cub *cub)
{
	if (cub->map[(int)(cub->pers->x + cub->pers->dirX * sin(MOVESPEED))] \
	[(int)cub->pers->y] == '0')
		cub->pers->x += cub->pers->dirX * sin(MOVESPEED);
	if (cub->map[(int)cub->pers->x] \
	[(int)(cub->pers->y + cub->pers->dirY * sin(MOVESPEED))] == '0')
		cub->pers->y += cub->pers->dirY * sin(MOVESPEED);
}

void	move_s(t_cub *cub)
{
	if (cub->map[(int)(cub->pers->x - cub->pers->dirX * sin(MOVESPEED))] \
	[(int)cub->pers->y] == '0')
		cub->pers->x -= cub->pers->dirX * sin(MOVESPEED);
	if (cub->map[(int)cub->pers->x] \
	[(int)(cub->pers->y - cub->pers->dirY * sin(MOVESPEED))] == '0')
		cub->pers->y -= cub->pers->dirY * sin(MOVESPEED);
}

void	move_a(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->pers->dirX;
	old_plane_x = cub->pers->planeX;
	cub->pers->dirX = cub->pers->dirX * cos(-ROTATESPEED) \
	- cub->pers->dirY * sin(-ROTATESPEED);
	cub->pers->dirY = old_dir_x * sin(-ROTATESPEED) \
	+ cub->pers->dirY * cos(-ROTATESPEED);
	cub->pers->planeX = cub->pers->planeX * cos(-ROTATESPEED) \
	- cub->pers->planeY * sin(-ROTATESPEED);
	cub->pers->planeY = old_plane_x * sin(-ROTATESPEED) \
	+ cub->pers->planeY * cos(-ROTATESPEED);
}

void	move_d(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->pers->dirX;
	old_plane_x = cub->pers->planeX;
	cub->pers->dirX = cub->pers->dirX * cos(ROTATESPEED) \
	- cub->pers->dirY * sin(ROTATESPEED);
	cub->pers->dirY = old_dir_x * sin(ROTATESPEED) \
	+ cub->pers->dirY * cos(ROTATESPEED);
	cub->pers->planeX = cub->pers->planeX * cos(ROTATESPEED) \
	- cub->pers->planeY * sin(ROTATESPEED);
	cub->pers->planeY = old_plane_x * sin(ROTATESPEED) \
	+ cub->pers->planeY * cos(ROTATESPEED);
}

void	move_mouse(t_cub *cub, double z)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->pers->dirX;
	old_plane_x = cub->pers->planeX;
	cub->pers->dirX = cub->pers->dirX * cos(z) \
	- cub->pers->dirY * sin(z);
	cub->pers->dirY = old_dir_x * sin(z) \
	+ cub->pers->dirY * cos(z);
	cub->pers->planeX = cub->pers->planeX * cos(z) \
	- cub->pers->planeY * sin(z);
	cub->pers->planeY = old_plane_x * sin(z) \
	+ cub->pers->planeY * cos(z);
}
