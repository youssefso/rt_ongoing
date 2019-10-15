#include "rtv1.h"
/*
   * * normal for fix torus
*/
t_vect	normal_ellipsoid(const t_obj obj, const t_vect hit_point, t_init mlx)
{
	t_vect normal;

	normal.x = 2 * hit_point.x / (obj.nor.x * obj.nor.x);
	normal.y = 2 * hit_point.y / (obj.nor.y * obj.nor.y);
	normal.z = 2 * hit_point.z / (obj.nor.z * obj.nor.z);
	ft_vec_normalize(&normal);
	return (normal);
}
/*
t_vect	normal_ellipsoid(const t_obj obj, const t_vect hit_point, t_init mlx)
{
	t_vect c;
	t_vect r;
	t_vect normal;

	c = ft_vec_sum(obj.pos, ft_vec_multr(obj.dir, obj.R / 2));
	r = ft_vec_sub(hit_point, c);
	normal = 
}
*/
