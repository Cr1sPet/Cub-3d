#include "../../includes/cub3d.h"

//void	ceiling(t_cub *cub)
//{
//    while (draw->y < draw->drawstart)
//    {
//        cub->img->data[draw->y * WIDTH + draw->x] = cub->map->c_color;
//        draw->y++;
//    }
//}
//
//void	draw_game2(t_cub *data)
//{
//    data->pers->y = 0;
//    ceiling(data, draw);
//    draw->texx = (int)(draw->wallx * data->map->tex->height);
//    if ((draw->side == 0 && draw->cos > 0) || \
//		(draw->side == 1 && draw->sin < 0))
//        draw->texx = data->map->tex->width - draw->texx - 1;
//    draw->step = (double)data->map->tex->height / draw->lineheight;
//    draw->texpos = (draw->drawstart - \
//			WIN_HEIGHT / 2 + draw->lineheight / 2) * draw->step;
//    walls(data, data->map, draw);
//    flour(data, draw);
//}

void	draw_game(t_cub *cub)
{
    t_cub 	draw;

//    draw.angle_start = data->ply->angle + data->ply->fov / 2;
//    draw.angle_end = data->ply->angle - data->ply->fov / 2;
//    draw.angle_step = data->ply->fov / WIN_WIDTH;
//    draw.angle = draw.angle_start;
//    draw.x = 0;
//    while (draw.angle > draw.angle_end)
//    {
//        draw_step_side(data, &draw);
//        hit_wall(data, data->map, &draw, data->ply);
//        height_wall(data, &draw);
//        draw_game2(data, &draw);
//        draw.angle -= draw.angle_step;
//        draw.x++;
//    }
//    for (int i = 0; i < SCALE * SCALE; i++) {
//        for (int j = 0; j < SCALE * SCALE; j++) {
//            put_pixel(cub->pers->x + i, cub->pers->y + j, cub->lib_mlx, create_rgb(0, 0, 255));
//
//        }
//    }
}

void	ft_cast_rays(t_cub *all)
{
  // for(int y = 0; y < HEIGHT; y++)
  //   {
  //     // rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
  //     float rayDirX0 = all->pers->dirX - all->pers->planeX;
  //     float rayDirY0 = all->pers->dirY -  all->pers->planeY;
  //     float rayDirX1 = all->pers->dirX +  all->pers->planeX;
  //     float rayDirY1 = all->pers->dirY +  all->pers->planeY;

  //     // Current y position compared to the center of the screen (the horizon)
  //     int p = y - HEIGHT / 2;

  //     // Vertical position of the camera.
  //     float posZ = 0.5 * HEIGHT;

  //     // Horizontal distance from the camera to the floor for the current row.
  //     // 0.5 is the z position exactly in the middle between floor and ceiling.
  //     float rowDistance = posZ / p;

  //     // calculate the real world step vector we have to add for each x (parallel to camera plane)
  //     // adding step by step avoids multiplications with a weight in the inner loop
  //     float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / WIDTH;
  //     float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / WIDTH;

  //     // real world coordinates of the leftmost column. This will be updated as we step to the right.
  //     float floorX = all->pers->x + rowDistance * rayDirX0;
  //     float floorY = all->pers->y + rowDistance * rayDirY0;

  //     for(int x = 0; x < WIDTH; ++x)
  //     {
  //       // the cell coord is simply got from the integer parts of floorX and floorY
  //       int cellX = (int)(floorX);
  //       int cellY = (int)(floorY);

  //       // get the texture coordinate from the fractional part
  //       int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
  //       int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

  //       floorX += floorStepX;
  //       floorY += floorStepY;

  //       // choose texture and draw the pixel
  //       int floorTexture = 3;
  //       int ceilingTexture = 6;
  //       int color;

  //       // floor
  //       color = 0x00FF0000;
  //        put_pixel(x, y, all->lib_mlx, color); 
  //       //ceiling (symmetrical, at screenHeight - y - 1 instead of y)
  //     }
  //   }

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
        //jump to next map square, either in x-direction, or in y-direction
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
        if(all->map[mapX][mapY] && all->map[mapX][mapY] == '1') hit = 1;
      }
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist =  (sideDistY - deltaDistY);
      // printf("%f %f %d\n", sideDistX, deltaDistX, side);
      int lineHeight = (int)(HEIGHT / perpWallDist);
      // printf("%d %f\n", lineHeight, perpWallDist);
      int drawStart = -lineHeight / 2 + HEIGHT / 2;
      int drawEnd = lineHeight / 2 + HEIGHT / 2;
      if(drawStart < 0) drawStart = 0;
      if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

      //choose wall color
      int color;
      color = 0x990099;

      //give x and y sides different brightness
      if(side == 1) {color = color / 2;}
    while (drawStart < drawEnd)
    {
     put_pixel(x, drawStart, all->lib_mlx, color); 
     drawStart++;
    }
    	int	y;

	if (drawEnd < 0)
    drawEnd = HEIGHT;
	y = drawEnd + 1;
	while (y < HEIGHT)
	{
		put_pixel(x, y,  all->lib_mlx, 0x00FF0000);
		put_pixel(x, HEIGHT - y - 1, all->lib_mlx, 0x000000FF);
		y++;
	}
    }

}

void draw_3d(t_cub *cub)
{
    ft_bzero(cub->lib_mlx->data_addr, WIDTH * HEIGHT * (cub->lib_mlx->bits_per_pixel / 8));
    ft_cast_rays(cub);
    mlx_put_image_to_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, cub->lib_mlx->img, 0, 0);
}