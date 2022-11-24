/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:44:44 by lollith           #+#    #+#             */
/*   Updated: 2022/11/24 14:10:08 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void verLine(t_img *img, int ray, int drawStart, int drawEnd, int color){
	int x = ray;
	int y = drawStart;
	// while (x < ray)
	{
		while (y < drawEnd)
		{
			img_pix(img, x, y, color);
			y++;
		}
		x++;
	}
}


void raycasting(t_all *all)
{
//--------------//tuto raycasting	
	double posX = all->pos.p_x + 0.2; // avance un peu mon perso sur la case
	double posY = all->pos.p_y + 0.2;
	double dirX = -1; //pour N // les coordonne sont selon un tableau ->y et x vers le bas
	double dirY = 0;
	double planeX = 0;
	double planeY = 0.60;//pour N // tuto = 0.66
	int x = 0;
	double lenght_plane = 600; // w ds tuto , car  fov = 60, tan(60/2) = oppose/adj
	double ratioX; // cameraX
	// double rayDirX; // suprimer la structure pour ca
	// double rayDirY;

	//calcul de la direction du rayon = vecteur dir + ratio du plan
	while (x < lenght_plane)
	{
		// ratioX = x / (lenght_plane);
		ratioX = 2 * x / (double)lenght_plane - 1;
		all->ray.rayDirX = dirX + planeX * ratioX;
		all->ray.rayDirY = dirY + planeY * ratioX;
	 //which box of the map we're in
      int mapX = (int)posX;
      int mapY = (int)posY;
	  int index = all->pos.index;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;
	  double deltaDistX;
	  double deltaDistY;

       //length of ray from one x or y-side to next x or y-side
	if (all->ray.rayDirX == 0) 
		deltaDistX = 1e30;
	else
		deltaDistX = fabs (1 / all->ray.rayDirX);
		
	if (all->ray.rayDirY == 0) 
		deltaDistY = 1e30;
	else
		deltaDistY = fabs (1 / all->ray.rayDirY);
	  
	  double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

 //calculate step and initial sideDist
      if (all->ray.rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (all->ray.rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }

	      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, either in x-direction, or in y-direction
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
        //Check if ray has hit a wall
		index = mapX * (all->map.x + 1) + mapY;
		if (all->map.line [index] == '1') 
			hit = 1;
      } 
	  all->ray.sideDistX = sideDistX;
	  all->ray.sideDistY = sideDistY;

//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

	int lineHeight;
	int h = 500; // taille ecran
	  //Calculate height of line to draw on screen
      	lineHeight = (int)(h / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + h / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + h/ 2;
      if(drawEnd >= h)drawEnd = h - 1;
	
	//  printf("%d\n", x);

	  //choose wall color
      int color = 0xFF0000;
    //   switch(all.map.line[index])
    //   {
    //     // case 1:  color = 0X00FF00;  break; //red
    //     // case 2:  color = 0xFFFF00;  break; //green
    //     // case 3:  color = 0xFF00FF;   break; //blue
    //     // case 4:  color = 0xFFFFFF;  break; //white
    //     default: color = 0xFF0000; break; //yellow
    //   }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      verLine(&all->img_minimap, x, drawStart, drawEnd, color);
		x++;
	}
	}