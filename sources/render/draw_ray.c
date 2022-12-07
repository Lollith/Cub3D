// ne calcul pas la bonne taile du rayon=> l arretr moi meme au mur
// affichage dun rayon ds la bonne direction
void	draw_ray(t_img *img, t_all *all)
{
	double	x;
	double	y;
	// double	l;
		
		y = (all->pos.p_y + MINI_P / 2) * MINI_CUB;
		x = (all->pos.p_x + MINI_P / 2) * MINI_CUB;
		// img_pix(img, all->ray.step_x * (x + MINI_P), all->ray.step_y * (y+ MINI_P)+ all->map.mini_pos, 0xF00020);
		while (y < ((all->pos.p_y + MINI_P / 2 + all->ray.dist_y)* MINI_CUB)
			&& x < ((all->pos.p_x + MINI_P / 2 + all->ray.dist_x))* MINI_CUB)
		{
			img_pix(img,x + MINI_P, y + MINI_P + all->map.mini_pos, RED);
			// img_pix(img, all->ray.step_x * (x + MINI_P )  , all->ray.step_y * (y + MINI_P+ l)  + all->map.mini_pos, 0xFFFF00FF);
			x = x + (1/all->ray.r_dir_x);// ratio defini la direction de mon x en fct de ce ratio
			y = y + (1/all->ray.r_dir_y);
		}
}

	//ancienne version
	// l = 0;
	// while (l < 20) // l doit etre inf a taille de la map * minicub - pos du perso, x?
	// {
	// 	y = all->ray.step_y * (all->pos.p_y + MINI_P / 2) * MINI_CUB;
	// 	x = all->ray.step_x * (all->pos.p_x + MINI_P / 2) * MINI_CUB;
	// 	// img_pix(img, all->ray.step_x * (x + MINI_P), all->ray.step_y * (y+ MINI_P)+ all->map.mini_pos, 0xF00020);
	// 	while (y < ((all->pos.p_y + MINI_P / 2 + all->ray.dist_y) * MINI_CUB)
	// 		&& x < ((all->pos.p_x + MINI_P / 2 + all->ray.dist_x) * MINI_CUB))
	// 	{
	// 		img_pix(img, all->ray.step_x * (x + MINI_P), all->ray.step_y * (y + MINI_P) + all->map.mini_pos, RED);
	// 		// img_pix(img, all->ray.step_x * (x + MINI_P )  , all->ray.step_y * (y + MINI_P+ l)  + all->map.mini_pos, 0xFFFF00FF);
	// 		x++;
	// 		y++;
	// 	}
	// 	l++;
	// }
// 	// rayon dans lautre sens pour cone FOV
// 	l = 0;
// 	while (l < 10) // l doit etre inf a taille de la map * minicub - pos du perso, x?
// 	{
// 		y = all->ray.step_y * (all->pos.p_y + MINI_P / 2) * MINI_CUB;
// 		x = all->ray.step_x * (all->pos.p_x + MINI_P / 2 ) * MINI_CUB;
// 		// while (y < (all->pos.p_y * MINI_CUB + all->ray.sideDistY)
// 			// && x < (all->pos.p_x * MINI_CUB + all->ray.sideDistX))
// 		while (y < ((all->pos.p_y + MINI_P / 2 + all->ray.dist_y) * MINI_CUB)
// 			&& x < ((all->pos.p_x + MINI_P / 2 + all->ray.dist_x) * MINI_CUB))
// 		{
// 			img_pix(img, all->ray.step_x * (x + MINI_P), all->ray.step_y * (y + MINI_P /*+ l*/) + all->map.mini_pos, RED);
// 			x--;
// 			y++;
// 		}
// 		l++;
// 	}
// }

// draw avec ray dir ++ arreter le rayon  a la main// marche pas 
// void draw_ray(t_img *img, t_all *all)
// {
// 	double x;
// 	double y;
// 	// y = (all->pos.p_y + MINI_P / 2) * MINI_CUB;
// 	// x = all->pos.p_x * MINI_CUB + MINI_P / 2 * MINI_CUB;
// 	y = all->ray.step_y *(all->pos.p_y + MINI_P/2)* MINI_CUB;
//  	x = all->ray.step_x * (all->pos.p_x +  MINI_P/2 )* MINI_CUB;
// 	img_pix(img, all->ray.step_x* (x + MINI_P), all->ray.step_y * (y+ MINI_P), 0xF00020);
	
// 	while ( y < (all->pos.p_y * MINI_CUB + fabs(all->ray.r_dir_y) * MINI_CUB) && x < (all->pos.p_x * MINI_CUB+ fabs(all->ray.r_dir_x )* MINI_CUB))
// 	{
// 		img_pix(img,  all->ray.step_x * (x + MINI_P), all->ray.step_y * (y + MINI_P) , 0xFFFFFF00);
// 		x++;
// 		y++;
// 	}
// }
