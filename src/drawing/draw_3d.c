#include "../../includes/cub3d.h"

void draw_wool(int side, int drawStart, int drawEnd, int x, t_cub *cub, int lineHeight, t_texture *texture)
{
  int	r;
	int	g;
	int	b;

  int tex_x = (int)(cub->config->wall_x * (double)texture->width);
  if (side == 0 && cub->pers->dirX < 0) tex_x = texture->width - tex_x - 1;
  if (side == 1 && cub->pers->dirY > 0) tex_x = texture->width - tex_x - 1;
  double step = 1.0 * texture->height / lineHeight;
  double pos = (drawStart - HEIGHT / 2 + lineHeight / 2) * step;

  while (drawStart < drawEnd)
  {

    int tex_y = (int)pos & (texture->height - 1);
    pos += step;
    b = (unsigned char)texture->data_addr[tex_y * texture->line_length
			+ tex_x * texture->bits_per_pixel / 8];
		g = (unsigned char)texture->data_addr[tex_y * texture->line_length
			+ tex_x * texture->bits_per_pixel / 8 + 1];
		r = (unsigned char)texture->data_addr[tex_y * texture->line_length
			+ tex_x * texture->bits_per_pixel / 8 + 2];
    put_pixel(x, drawStart, cub->lib_mlx, create_rgb(r,g, b)); 
    drawStart++;
  }
}

void draw_floors(int drawEnd, t_cub *cub, int x)
{
  int i;

  i = 0;
	if (drawEnd < 0)
    drawEnd = HEIGHT;
	i = drawEnd + 1;
	while (i < HEIGHT)
	{
		put_pixel(x, i,  cub->lib_mlx, cub->config->c);
		put_pixel(x, HEIGHT - i - 1, cub->lib_mlx,  cub->config->f);
		i++;
	}
}
void char_put_pixel(int x, int y, t_texture *texture, int color)
{
	char	*dst;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = texture->data_addr + (y * texture->line_length + x * (texture->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
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
      {
         perpWallDist = (sideDistX - deltaDistX);
         all->config->wall_x = all->pers->y + perpWallDist * rayDirY;
      }
      else
      {
        perpWallDist =  (sideDistY - deltaDistY);
        all->config->wall_x = all->pers->x + perpWallDist * rayDirX;
      }
      all->config->wall_x -= floor(all->config->wall_x);
        
      
      int lineHeight = (int)(HEIGHT / perpWallDist);

      int drawStart = -lineHeight / 2 + HEIGHT / 2;
      if(drawStart < 0) drawStart = 0;
      int drawEnd = lineHeight / 2 + HEIGHT / 2;
      if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;


    if (side == 0 && rayDirX > 0)
		draw_wool(side, drawStart, drawEnd, x, all, lineHeight, all->config->so_texture);
	else if (side == 0 && rayDirX < 0)
		draw_wool(side, drawStart, drawEnd, x, all, lineHeight, all->config->no_texture);
	else if (side == 1 && rayDirY > 0)
		draw_wool(side, drawStart, drawEnd, x, all, lineHeight, all->config->ea_texture);
	else if (side == 1 && rayDirY < 0)
		draw_wool(side, drawStart, drawEnd, x, all, lineHeight, all->config->we_texture);
      draw_floors(drawEnd, all, x);
    }

}

void draw_3d(t_cub *cub)
{
    ft_bzero(cub->lib_mlx->data_addr, WIDTH * HEIGHT * (cub->lib_mlx->bits_per_pixel / 8));
    ft_cast_rays(cub);
    draw_minimap(cub);
    mlx_put_image_to_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, cub->lib_mlx->img, 0, 0);
}