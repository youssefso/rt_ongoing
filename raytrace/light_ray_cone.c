#include "rtv1.h"

static float	ft_sq(float a)
{
	return (a * a);
}

float	light_ray_cone(const t_obj obj, const t_ray ray)
{
	t_var	v;
	t_vect	x;
	float tmp;
	float k;

	k = 1 + ft_sq(obj.dif);
	x = ft_vec_sub(ray.pos, obj.pos);
	v.a = ft_vec_dot(ray.dir,ray.dir) - (k * ft_sq(ft_vec_dot(ray.dir, obj.dir)));
	v.b = 2 * (ft_vec_dot(ray.dir, x) - (k * ft_vec_dot(ray.dir, obj.dir) * ft_vec_dot(x, obj.dir)));
	v.c = ft_vec_dot(x, x) - (k * ft_sq(ft_vec_dot(x, obj.dir)));
	v.d = v.b * v.b - (4 * v.a * v.c);
	if (v.d < 0)
		return 0;
	v.t1 = (-v.b - sqrtf(v.d)) / (2 * v.a);
	v.t2 = (-v.b + sqrtf(v.d)) / (2 * v.a);
	tmp = ft_fmin_positive(v.t1, v.t2);
	// this fuction return min value or 0 if no positive number is given;
	if (tmp < ray.dir_mod && tmp > 0)
		return 1;
	return 0;
}
