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

void	ft_cast_rays(t_cub *all)
{
//     t_pers_pos 	ray = *all->pers; // задаем координаты и направление луча равные координатам игрока
//     int start_pos = all->start + 60 / 2;
//     all->end = 300;
//     while (start_pos <= all->end)
//     {
//         ray.dirX = (double)all->pers->x; // каждый раз возвращаемся в точку начала
//         ray.dirY = (double)all->pers->y;
//         while (all->map[(int)(ray.dirY / SCALE)][(int)(ray.dirX / SCALE)] != '1')
//         {
//             ray.dirX += cos((double) all->pers->alpha);
//             ray.dirY += cos((double) all->pers->alpha);
// ////            mlx_pixel_put(all->lib_mlx->mlx, all->lib_mlx->mlx_win, ray.x, ray.y, 0x990099);
//         //    put_pixel(ray.dirX, ray.dirY, all->lib_mlx, 0x990099);
//            for (int i = 0; i < 20; i++) {
//                for (int j = 0; j < 20; j++) {
//            put_pixel(ray.dirX + i, ray.dirY + j, all->lib_mlx, create_rgb(0, 0, 255));

//        }
//     }
//         }
//          start_pos++;
        
// }
 
float fPlayerX = 1.0f; // Координата игрока по оси X
float fPlayerY = 1.0f; // Координата игрока по оси Y
float fPlayerA = 0.0f; // Направление игрока
 
int nMapHeight = 16; // Высота игрового поля
int nMapWidth = 16;  // Ширина игрового поля
 
float fFOV = 3.14159 / 3; // Угол обзора (поле видимости)
float fDepth = 30.0f;     // Максимальная дистанция обзора
char map[] = "111111111111111110000000000000011000000000000001100000000000000110000000000000011000000000000001100000000000000110000000000000011000000000000001100000000000000110000000000000011000000000000001100000000N000001100000000000000110000000000000011111111111111111";
for (int x = 0; x < WIDTH; x++) // Проходим по всем X
{
    float fRayAngle = (all->pers->x- fFOV/2.0f) + ((float)x / (float)WIDTH) * fFOV; // Направление луча
    // Находим расстояние до стенки в направлении fRayAngle 
 
    float fDistanceToWall = 0.0f; // Расстояние до препятствия в направлении fRayAngle
    int bHitWall = 0; // Достигнул ли луч стенку
 
    float fEyeX = sinf(fRayAngle); // Координаты единичного вектора fRayAngle
    float fEyeY = cosf(fRayAngle);
 
    while (bHitWall == 0 && fDistanceToWall < fDepth) // Пока не столкнулись со стеной
    {                                           // Или не вышли за радиус видимости
        fDistanceToWall += 0.1f;
 
        int nTestX = (int)(all->pers->x+ fEyeX*fDistanceToWall); // Точка на игровом поле
        int nTestY = (int)(all->pers->y+ fEyeY*fDistanceToWall); // в которую попал луч
 
        if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
        { // Если мы вышли за зону
            bHitWall = 1;
            fDistanceToWall = fDepth;
        }
        else if (map[nTestY*nMapWidth + nTestX] == '1')
        {
            // printf("asdasdasdasdfrewfsafer\n");
             bHitWall = 1;
        }
           
           int nCeiling = (float)(HEIGHT/2.0) - HEIGHT / ((float)fDistanceToWall);
		int nFloor = HEIGHT - nCeiling;
        //    printf("%s <----\n", all->map[nTestY*nMapWidth + nTestX]);
        if (bHitWall == 0) {
    for (int y = 0; y < HEIGHT; y++) // При заданном X проходим по всем Y
    {
        // В этом цикле рисуется вертикальная полоска
   
        		if(y <= nCeiling)
					 put_pixel(x, y, all->lib_mlx, create_rgb(0, 0, 0));
				else if(y > nCeiling && y <= nFloor)
					     put_pixel(x, y, all->lib_mlx, create_rgb(0, 0, 255));
				else // Floor
				{				
					// Shade floor based on distance
					// float b = 1.0f - (((float)y -nScreenHeight/2.0f) / ((float)nScreenHeight / 2.0f));
					// if (b < 0.25)		nShade = create_rgb(0, 255, 255));
					// else if (b < 0.5)	nShade = create_rgb(0, 123, 255));
					// else if (b < 0.75)	nShade = create_rgb(23, 123, 255));
					// else if (b < 0.9)	nShade = create_rgb(0, y, 255));
					// else				nShade = create_rgb(0, y, 255));
					     put_pixel(x, y, all->lib_mlx,  create_rgb(23, 123, 255));
                         
				}
    }
        }

    // print_map(all->map);
    // fPlayerA -= (1.5f) * fElapsedTime;
}
}
}

void draw_3d(t_cub *cub)
{
    ft_bzero(cub->lib_mlx->data_addr, WIDTH * HEIGHT * (cub->lib_mlx->bits_per_pixel / 8));
    ft_cast_rays(cub);
    mlx_put_image_to_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, cub->lib_mlx->img, 0, 0);
}