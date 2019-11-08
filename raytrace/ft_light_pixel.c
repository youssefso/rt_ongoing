#include "rtv1.h"

void	ft_light_pixel(t_init *mlx, t_vect col)
{
	int i;
	int cl;
	if (mlx->x < 0 || mlx->y < 0 || mlx->y > HEIGHT || mlx->x > WIDTH)
		return ;
	i = (mlx->x * 4) + (mlx->y * WIDTH * 4);
//	cl = (int)col.x % 255;
//	cl += 255 * ((int)col.y % 255);
//	cl += 255 * 255 * ((int)col.z % 255);
//	cl += pow(255, 3) * 0;*/
//	cl = 0xFF0000;
	mlx->img_str[i] = '\0' + col.x;
	mlx->img_str[i + 1] = '\0' + col.y;
	mlx->img_str[i + 2] = '\0' + col.z;
}
