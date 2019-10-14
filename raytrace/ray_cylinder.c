#include "rtv1.h"

static float	ft_sq(float a)
{
	return (a * a);
}
float	ray_cylinder_close(t_obj obj, const t_ray ray, float *distance, t_init *mlx)
{
	t_var v;
	float a; // hold dot product
	float c; // hold dot product
	float tmp;
	t_vect x;

	x = ft_vec_sub(ray.pos, obj.pos);
	a = ft_vec_dot(ray.dir, obj.dir);
	c = ft_vec_dot(x, obj.dir);
	v.a = ft_vec_dot(ray.dir, ray.dir) - ft_sq(a);
	v.b = 2 * (ft_vec_dot(ray.dir, x) - (a * c));
	v.c = ft_vec_dot(x, x) - ft_sq(c) - ft_sq(obj.rad);
	v.d = (v.b * v.b) - (4 * v.a * v.c);
	if (v.d < 0)
		return 0;
	v.t1 = (-v.b - sqrtf(v.d)) / (2 * v.a);
	v.t2 = (-v.b + sqrtf(v.d)) / (2 * v.a);
	tmp = ft_fmin_positive(v.t1, v.t2);
	// this fuction return min value or 0 if no positive number is given;
	if (tmp < *distance && tmp > 0)
	{
		*distance = tmp;
		return 1;
	}
	return 0;
}
float	ray_cylinder(t_obj obj, const t_ray ray, float *distance, t_init *mlx)
{
	t_var v;
	float a; // hold dot product
	float c; // hold dot product
	float tmp;
	t_vect x;

	x = ft_vec_sub(ray.pos, obj.pos);
	a = ft_vec_dot(ray.dir, obj.dir);
	c = ft_vec_dot(x, obj.dir);
	v.a = ft_vec_dot(ray.dir, ray.dir) - ft_sq(a);
	v.b = 2 * (ft_vec_dot(ray.dir, x) - (a * c));
	v.c = ft_vec_dot(x, x) - ft_sq(c) - ft_sq(obj.rad);
	v.d = (v.b * v.b) - (4 * v.a * v.c);
	if (v.d < 0)
		return 0;
	v.t1 = (-v.b - sqrtf(v.d)) / (2 * v.a);
	v.t2 = (-v.b + sqrtf(v.d)) / (2 * v.a);
	tmp = ft_fmin_positive(v.t1, v.t2);
	// this fuction return min value or 0 if no positive number is given;
	if (tmp < *distance && tmp > 0)
	{
		mlx->m = ft_vec_dot(ray.dir, obj.dir) * tmp + ft_vec_dot(x, obj.dir);
		*distance = tmp;
		return 1;
	}
	return 0;
}
