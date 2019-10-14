#include "rtv1.h"

float	light_ray_sphere(const t_obj obj, const t_ray ray)
{
	t_var v; // containt float variable to hold some shit below;
	t_vect x;
	float tmp;

	x = ft_vec_sub(ray.pos, obj.pos);
	v.a = ft_vec_dot(ray.dir, ray.dir);
	v.b  = 2 * ft_vec_dot(ray.dir, x);
	v.c = ft_vec_dot(x, x) - (obj.rad * obj.rad);
	v.d = (v.b * v.b) - (4 * v.a * v.c);
	if (v.d < 0)
		return 0;
	v.t1 = (-v.b - sqrtf(v.d)) / (2 * v.a);
	v.t2 = (-v.b + sqrtf(v.d)) / (2 * v.a);
	tmp = ft_fmin_positive(v.t1, v.t2);// this fuction return min value or 0 if no positive number is given;
	if (tmp < ray.dir_mod && tmp > 0)
		return 1;
	return 0;
}
