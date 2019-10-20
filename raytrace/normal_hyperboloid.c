#include "rtv1.h"

t_vect	normal_hyperboloid(const t_obj obj, const t_vect hit_point, t_init mlx)
{
	t_vect	normal;
	float	m;

	normal.x = 2 * hit_point.x;
	normal.y = 2 * hit_point.y;
   	normal.z = -2 * hit_point.z; 
	ft_vec_normalize(&normal);
	return (normal);
}
