/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:44:44 by lollith           #+#    #+#             */
/*   Updated: 2022/11/29 18:10:36 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void verLine(t_img *img, int x, int draw_start, int draw_end, int color)
{
  int y = draw_start;
  {
    while (y < draw_end)
    {
      img_pix(img, x, y, color);
      y++;
    }
  }
}
// fov = 60 , tan(60/2)=  oppose/adj
//lenght_plane = W_WiDTH
//ratioX = cameraX
void raycasting(t_all *all)
{
  int x = 0;
  double ratioX;

  // calcul de la direction du rayon = vecteur dir + ratio du plan
  while (x < W_WIDTH)
  {
    ratioX = 2 * x / (double)W_WIDTH - 1;
    all->ray.r_dir_x = all->ray.orient_x + all->ray.plane_x * ratioX;
    all->ray.r_dir_y = all->ray.orient_y + all->ray.plane_y * ratioX;

  // pos + 0.2 avance un peu mon perso sur la case
  double posX = all->pos.p_x + -1.2; 
  double posY = all->pos.p_y + 0.2;
    
    //  which box of the map we're in
    int mapX = (int)posX;
    int mapY = (int)posY;
    int index = all->pos.index;

    // length of ray from current position to next x or y-side
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;

    // length of ray from one x or y-side to next x or y-side
    if (all->ray.r_dir_x == 0)
      deltaDistX = 1e30;
    else
      deltaDistX = fabs(1 / all->ray.r_dir_x);

    if (all->ray.r_dir_y == 0)
      deltaDistY = 1e30;
    else
      deltaDistY = fabs(1 / all->ray.r_dir_y);

    double perpWallDist;

    // what direction to step in x or y-direction (either +1 or -1)
    int stepX;
    int stepY;

    int hit = 0; // was there a wall hit?
    int side;    // was a NS or a EW wall hit?

    // calculate step and initial sideDist
    if (all->ray.r_dir_x < 0)
    {
      stepX = -1;
      sideDistX = (posX - mapX) * deltaDistX;
    }
    else
    {
      stepX = 1;
      sideDistX = (mapX + 1.0 - posX) * deltaDistX;
    }
    if (all->ray.r_dir_y < 0)
    {
      stepY = -1;
      sideDistY = (posY - mapY) * deltaDistY;
    }
    else
    {
      stepY = 1;
      sideDistY = (mapY + 1.0 - posY) * deltaDistY;
    }

    // perform DDA
    while (hit == 0)
    {
      // jump to next map square, either in x-direction, or in y-direction
      if (sideDistX < sideDistY)
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
      // Check if ray has hit a wall
      index = mapY * (all->map.x) + mapX;
      if (all->map.line[index] == '1')
        hit = 1;
    }
    all->ray.sideDistX = sideDistX;
    all->ray.sideDistY = sideDistY;
    all->ray.step_x = stepX;
    all->ray.step_y = stepY;
    // Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
    if (side == 0)
      perpWallDist = (sideDistX - deltaDistX);
    else
      perpWallDist = (sideDistY - deltaDistY);

    int lineHeight;
    int h = 500; // taille ecran
                 // Calculate height of line to draw on screen
    lineHeight = (int)(h / perpWallDist);

    // calculate lowest and highest pixel to fill in current stripe
    int draw_start = -lineHeight / 2 + h / 2;
    if (draw_start < 0)
      draw_start = 0;
    int draw_end = lineHeight / 2 + h / 2;
    if (draw_end >= h)
      draw_end = h - 1;

    int color = 0xFF0000;

    // give x and y sides different brightness
    if (side == 1)
    {
      color = color / 2;
    }

    // draw the pixels of the stripe as a vertical line
    verLine(&all->img_minimap, x, draw_start, draw_end, color);
    x++;
  }
}