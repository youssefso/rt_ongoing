#include "rtv1.h"

void	ft_light_pixel(t_init mlx, t_vect col)
{
	int i;
	if (mlx.x < 0 || mlx.y < 0 || mlx.y > HEIGHT || mlx.x > WIDTH)
		return ;
	i = (mlx.x * 4) + (mlx.y * WIDTH * 4);
	mlx.img_str[i] = (unsigned char)col.x;
	mlx.img_str[i + 1] = (unsigned char)col.y;
	mlx.img_str[i + 2] = (unsigned char)col.z;
}
