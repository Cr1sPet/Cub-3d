#include "../../includes/cub3d.h"


void draw_floors(int drawEnd, t_cub *cub, int x)
{
  int i;

  i = 0;
	if (drawEnd < 0)
    drawEnd = HEIGHT;
	i = drawEnd + 1;
	while (i < HEIGHT)
	{
		put_pixel(x, i,  cub->lib_mlx, 0x00FF0000);
		put_pixel(x, HEIGHT - i - 1, cub->lib_mlx, 0x000000FF);
		i++;
	}
}

void	ft_cast_rays(t_cub *all)
{
  for (int x = 0; x < WIDTH; x++)
   {
      double cameraX = 2 * x / (double)WIDTH - 1;;
      double rayDirX = all->pers->dirX + all->pers->planeX * cameraX;
      double rayDirY = all->pers->dirY + all->pers->planeY * cameraX;
      int mapX = (int)all->pers->x;
      int mapY = (int)all->pers->y;
      double sideDistX;
      double sideDistY;

      double deltaDistX = fabs(1 / rayDirX);
      double deltaDistY = fabs(1 / rayDirY);
      double perpWallDist;

      int stepX;
      int stepY;
      int hit = 0;
      int side;
       if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (all->pers->x - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - all->pers->x) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (all->pers->y - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - all->pers->y) * deltaDistY;
      }
      while(hit == 0)
      {
        if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        if(all->map[mapX][mapY] != '0') hit = 1;
      }
      if(side == 0)
        perpWallDist = (sideDistX - deltaDistX);
      else
        perpWallDist =  (sideDistY - deltaDistY);
      
      int lineHeight = (int)(HEIGHT / perpWallDist);

      int drawStart = -lineHeight / 2 + HEIGHT / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + HEIGHT / 2;
      if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

      int color;
      color = 0x990099;
      if(side == 1) {color = color / 2;}
      while (drawStart < drawEnd)
      {
        put_pixel(x, drawStart, all->lib_mlx, color); 
        drawStart++;
      }
    draw_floors(drawEnd, all, x);
    }

}

void draw_3d(t_cub *cub)
{
    ft_bzero(cub->lib_mlx->data_addr, WIDTH * HEIGHT * (cub->lib_mlx->bits_per_pixel / 8));
    ft_cast_rays(cub);
    mlx_put_image_to_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, cub->lib_mlx->img, 0, 0);
}