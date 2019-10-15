#include "rtv1.h"

t_vect	normal_paraboloid(const t_obj obj, const t_vect hit_point, t_init mlx)
{
	t_vect normal;

	normal = ft_vec_sub(ft_vec_sub(hit_point, obj.pos), ft_vec_multr(obj.dir, mlx.m + obj.R));
	ft_vec_normalize(&normal);
	return (normal);
}
