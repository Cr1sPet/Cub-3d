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
    t_pers_pos 	ray = *all->pers; // задаем координаты и направление луча равные координатам игрока
    int start_pos = all->start + 60 / 2;
    all->end = 300;
    while (start_pos <= all->end)
    {
        ray.dirX = (double)all->pers->x; // каждый раз возвращаемся в точку начала
        ray.dirY = (double)all->pers->y;
        while (all->map[(int)(ray.dirY / SCALE)][(int)(ray.dirX / SCALE)] != '1')
        {
            ray.dirX += cos((double) all->pers->alpha);
            ray.dirY += cos((double) all->pers->alpha);
////            mlx_pixel_put(all->lib_mlx->mlx, all->lib_mlx->mlx_win, ray.x, ray.y, 0x990099);
//            put_pixel(ray.dirX, ray.dirY, all->lib_mlx, 0x990099);
//            for (int i = 0; i < 20; i++) {
//                for (int j = 0; j < 20; j++) {
//            put_pixel(ray.dirX + i, ray.dirY + j, all->lib_mlx, create_rgb(0, 0, 255));
//
//        }
    }
        }
        start_pos++;
    }
}

void draw_3d(t_cub *cub)
{
    ft_bzero(cub->lib_mlx->data_addr, WIDTH * HEIGHT * (cub->lib_mlx->bits_per_pixel / 8));
    ft_cast_rays(cub);

    mlx_put_image_to_window(cub->lib_mlx->mlx, cub->lib_mlx->mlx_win, cub->lib_mlx->img, 0, 0);
}