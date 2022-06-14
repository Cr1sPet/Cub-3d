#include "../../includes/cub3d.h"

void draw_3d(t_cub *cub)
{
        t_pers_pos plr = *cub->pers;
        int color = create_rgb(233, 15, 255);
        while (cub->map[(int) plr.y / SCALE][(int) plr.x / SCALE] != '1')
        {
            plr.x += cos(plr.alpha);
            plr.y += sin(plr.alpha);
            put_pixel(plr.x,  plr.y, cub->lib_mlx, color);
        }
}