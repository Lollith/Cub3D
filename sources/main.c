/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:50:48 by agouet            #+#    #+#             */
/*   Updated: 2022/11/23 19:39:43 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void verLine(t_img *img, int nb_ray, int drawStart, int drawEnd, int color){
	int x = nb_ray;
	int y = drawStart;
	while (x < W_WIDTH)
	{
		while (y < drawEnd)
		{
			img_pix(img, x, y, color);
			y++;
		}
		x++;
	}
}

int main(int ac, char **av)
{
	t_all all;

	if (check_args(ac, av) != 0)
		return (1);
	if (ft_init(av[1]) == 1)
		return (1);
	//--------------------------------initialisation----------------------------
	init_square_map(av, &all.map); // to be deleted later?
	create_window(&all.win);

	// get map will be all.map.map = get_map(av) struct map to be deleted in main after that
	// init_all(av, &all);
	// all.window = data; //to be deleted because this stage has to be done in all init

	//--------------------------------fonctions---------------------------------
	// creation img minimap
	img_creation(&all);
	read_pos_ini(&all);
	// commandes
	ft_key_loop_hook(&all);
	//  render
	mlx_loop_hook(all.win.pt_mlx, &render, &all); // boucle sur mes images

	//--------------//tuto raycasting	
	double posX = all.pos.p_x + 0.1; // avance un peu mon perso sur la case
	double posY = all.pos.p_y + 0.1;
	double dirX = -1; //pour N // les coordonne sont selon un tableau ->y et x vers le bas
	double dirY = 0;
	double planeX = 0;
	double planeY = 0.60;//pour N // tuto = 0.66
	// double time = 0;
	// double oldtime = 0;
	int x = 0;
	double lenght_plane = 0.6; // w ds tuto , car  fov = 60, tan(60/2) = oppose/adj
	double ratioX; // cameraX
	double rayDirX;
	double rayDirY;

	//calcul de la direction du rayon = vecteur dir + ratio du plan
	while (x < lenght_plane)
	{
		// ratioX = x / (lenght_plane);
		ratioX = 2 * x / (lenght_plane) - 1;
		rayDirX = dirX + planeX * ratioX;
		rayDirY = dirY + planeY * ratioX;
		x++;
	}
	 //which box of the map we're in
      int mapX = (int)posX;
      int mapY = (int)posY;
	  int index = all.pos.index;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;
	  double deltaDistX;
	  double deltaDistY;

       //length of ray from one x or y-side to next x or y-side
    //   double deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
    //   double deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);
	if (rayDirX == 0) 
		deltaDistX = 1e30;
	else
		deltaDistX = fabs (1 / rayDirX);
		
	if (rayDirY == 0) 
		deltaDistY = 1e30;
	else
		deltaDistY = fabs (1 / rayDirY);
	  
	  double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

 //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if (rayDirY < 0)
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
        if (all.map.line [index] > 0) 
			hit = 1;
      } 
//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
      if(side == 0) perpWallDist = (sideDistX - deltaDistX);
      else          perpWallDist = (sideDistY - deltaDistY);

	int lineHeight;
	  //Calculate height of line to draw on screen
      	lineHeight = (int)(W_HEIGHT / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + W_HEIGHT / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + W_HEIGHT / 2;
      if(drawEnd >= W_HEIGHT)drawEnd = W_HEIGHT - 1;
	
	  //choose wall color
      int color;
      switch(all.map.line[index])
      {
        // case 1:  color = 0X00FF00;  break; //red
        // case 2:  color = 0xFFFF00;  break; //green
        // case 3:  color = 0xFF00FF;   break; //blue
        // case 4:  color = 0xFFFFFF;  break; //white
        default: color = 0xFF0000; break; //yellow
      }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}

      //draw the pixels of the stripe as a vertical line
      verLine(&all.img_minimap, x, drawStart, drawEnd, color);
	// mlx_put_image_to_window(all.win.pt_mlx, all.win.pt_win,
							// all.img_minimap.mlx_img, 0, 0); // affiche l image
	//-----------------ends---------------------------------------
	printf("%d\n", drawEnd);
	mlx_loop(all.win.pt_mlx);
	the_end(&all);
	//---------------------------above to be deleted later----------------------------
	return (0);
}
