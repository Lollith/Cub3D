/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:44:44 by lollith           #+#    #+#             */
/*   Updated: 2022/11/30 18:37:03 by agouet           ###   ########.fr       */
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
// orient_ : N S E W 
void  ray_direction(t_all * all, int *pt_x)
{
  double  ratioX;
  int     x;
  
  x = *pt_x;
  ratioX = 2 * (x) / (double) W_WIDTH - 1;
  all->ray.r_dir_x = all->ray.orient_x + all->ray.plane_x * ratioX;
  all->ray.r_dir_y = all->ray.orient_y + all->ray.plane_y * ratioX;
  pt_x = &x;
}

void  ray_size_in_square(t_all *all)
{
    if (all->ray.r_dir_x == 0)
      all->ray.delta_dist_x = 1e30;
    else
      all->ray.delta_dist_x = fabs(1 / all->ray.r_dir_x);
    if (all->ray.r_dir_y == 0)
      all->ray.delta_dist_y = 1e30;
    else
      all->ray.delta_dist_y = fabs(1 / all->ray.r_dir_y);    
}

    //mapX  which box of the map we're in =>cast la pos
    // calculate step and initial sideDist = dist_
    // what direction to step in x or y-direction (either +0 or -1)
     // pos + -1.2 avance un peu mon perso sur la case
void dda_init(t_all *all, int *map_x, int *map_y) 
  {
    // posX = all->pos.p_x + 0.2;  check si minimap ok avec linitialisation
    // posY = all->pos.p_y + 0.2;
  *map_x = (int)all->pos.p_x;
  *map_y = (int)all->pos.p_y;
    if (all->ray.r_dir_x < 0)
    {
      all->ray.step_x = -1;
      all->ray.dist_x = (all->pos.p_x - *map_x) * (all->ray.delta_dist_x);
    }
    else
    {
      all->ray.step_x = 1;
      all->ray.dist_x = ((*map_x) + 1.0 - all->pos.p_x) * (all->ray.delta_dist_x);
    }
    if (all->ray.r_dir_y < 0)
    {
      all->ray.step_y = -1;
      all->ray.dist_y = (all->pos.p_y - (*map_y)) * (all->ray.delta_dist_y);
    }
    else
    {
      all->ray.step_y = 1;
      all->ray.dist_y = ((*map_y) + 1.0 - all->pos.p_y) * (all->ray.delta_dist_y);
    }
  }

// hit was there a wall hit?
// side was a NS or a EW wall hit?
// jump to next map square, either in x-direction, or in y-direction
void  digital_differential_analysis(t_all *all, int *map_x, int *map_y, int *side)
{
  int hit;
  int index;
  hit = 0;
    while (hit == 0)
    {
      if (all->ray.dist_x < all->ray.dist_y)
      {
        all->ray.dist_x += all->ray.delta_dist_x;
        (*map_x) += all->ray.step_x;
        (*side) = 0;
      }
      else
      {
        all->ray.dist_y += all->ray.delta_dist_y;
        (*map_y) += all->ray.step_y;
        *side = 1;
      }
      // Check if ray has hit a wall
  index = (*map_y) * (all->map.x) + (*map_x);
      if (all->map.line[index] == '1')
        hit = 1;
    }
}
  
// fov = 60 , tan(60/2)=  oppose/adj
//lenght_plane = W_WiDTH
//ratioX = cameraX
void raycasting(t_all *all)
{
  int     x;
  int   map_x=0;
  int   map_y=0;
  int side = 0;
  // calcul de la direction du rayon = vecteur dir + ratio du plan
  x = 0;
  while (x < W_WIDTH)
  {  
    ray_direction(all, &x);
    ray_size_in_square(all);
    dda_init(all, &map_x, &map_y);
    digital_differential_analysis(all, &map_x, &map_y, &side);
    
    // Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
    double perpWallDist;
    if (side == 0)
      perpWallDist = (all->ray.dist_x - all->ray.delta_dist_x);
    else
      perpWallDist = (all->ray.dist_y - all->ray.delta_dist_y);

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

    int color = BLUE;

    // give x and y sides different brightness
    if (side == 1)
      color = color / 2;

    // draw the pixels of the stripe as a vertical line
    verLine(&all->img_minimap, x, draw_start, draw_end, color);
    x++;
  }
}