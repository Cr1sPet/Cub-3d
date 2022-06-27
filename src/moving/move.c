#include "../../includes/cub3d.h"

int key_press(int keycode, t_cub *cub)
{
    if (keycode == 13)
        cub->key->w = 1;
    if (keycode == 1)
        cub->key->s = 1;
    if (keycode == 0 || keycode == 123)
        cub->key->d = 1;
    if (keycode == 2 || keycode == 124)
        cub->key->a = 1;
    if (keycode == 53)
        ft_exit(cub);
    
    return (0);
}

int key_release(int keycode, t_cub *cub)
{
    if (keycode == 13)
        cub->key->w = 0;
    if (keycode == 1)
        cub->key->s = 0;
    if (keycode == 0 || keycode == 123)
        cub->key->d = 0;
    if (keycode == 2 || keycode == 124)
        cub->key->a = 0;
    return (0);
}

void move(t_cub *cub)
{
    if (cub->key->w == 1)
    {
        if(cub->map[(int)(cub->pers->x + cub->pers->dirX * MOVESPEED)][(int)cub->pers->y]  == '0')
        {
           cub->pers->x += cub->pers->dirX * MOVESPEED;
        }
        if (cub->map[(int)cub->pers->x][(int)(cub->pers->y + cub->pers->dirY * MOVESPEED)]  == '0')
        {
            cub->pers->y += cub->pers->dirY * MOVESPEED;
        }  
    }
    if (cub->key->s == 1)
    {
        if(cub->map[(int)(cub->pers->x - cub->pers->dirX * MOVESPEED)][(int)cub->pers->y]  == '0')
        {
            cub->pers->x -= cub->pers->dirX * MOVESPEED;
        } 
        if (cub->map[(int)cub->pers->x][(int)(cub->pers->y - cub->pers->dirY * MOVESPEED)] == '0')
        {
            cub->pers->y -= cub->pers->dirY * MOVESPEED;
        }  
    }
    if (cub->key->a == 1)
    {
        double oldDirX = cub->pers->dirX;
        cub->pers->dirX = cub->pers->dirX * cos(-ROTATESPEED) - cub->pers->dirY * sin(-ROTATESPEED);
        cub->pers->dirY = oldDirX * sin(-ROTATESPEED) + cub->pers->dirY * cos(-ROTATESPEED);
        double oldPlaneX =  cub->pers->planeX;
        cub->pers->planeX =  cub->pers->planeX * cos(-ROTATESPEED) -  cub->pers->planeY * sin(-ROTATESPEED);
        cub->pers->planeY = oldPlaneX * sin(-ROTATESPEED) + cub->pers->planeY * cos(-ROTATESPEED);
    }
    if (cub->key->d == 1)
    {
        double oldDirX = cub->pers->dirX;
        cub->pers->dirX = cub->pers->dirX * cos(ROTATESPEED) - cub->pers->dirY * sin(ROTATESPEED);
        cub->pers->dirY = oldDirX * sin(ROTATESPEED) + cub->pers->dirY * cos(ROTATESPEED);
        double oldPlaneX =  cub->pers->planeX;
        cub->pers->planeX =  cub->pers->planeX * cos(ROTATESPEED) -  cub->pers->planeY * sin(ROTATESPEED);
        cub->pers->planeY = oldPlaneX * sin(ROTATESPEED) + cub->pers->planeY * cos(ROTATESPEED);
    }
}