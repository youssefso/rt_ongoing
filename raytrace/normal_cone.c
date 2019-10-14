#include "rtv1.h"

t_vect	normal_cone(const t_obj obj, const t_vect hit_point, t_init mlx)
{
	t_vect	normal;
	float	m;

	normal = ft_vec_sub(ft_vec_sub(hit_point, obj.pos), ft_vec_multr(obj.dir, mlx.m * (1 + (obj.dif * obj.dif))));// hit_dist = 1 * k * k where k = tang of half ang of cone
	ft_vec_normalize(&normal);
	return (normal);
}
