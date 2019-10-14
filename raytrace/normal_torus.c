#include "rtv1.h"

t_vect	normal_torus(const t_obj obj, const t_vect hit_point, t_init mlx)
{
	float k;
	t_vect a;
	float m;
	t_vect normal;

	k = ft_vec_dot(ft_vec_sub(hit_point, obj.pos), obj.dir);
	a = ft_vec_sub(hit_point, ft_vec_multr(obj.dir, k));
	m = sqrtf(obj.r * obj.r - k * k);
	normal = ft_vec_multr(ft_vec_sub(obj.pos, a), m);
	normal = ft_vec_multr(normal, 1 / (obj.R + m));
	normal = ft_vec_sub(ft_vec_sub(hit_point, a), normal);
	ft_vec_normalize(&normal);
	return (normal);
}
