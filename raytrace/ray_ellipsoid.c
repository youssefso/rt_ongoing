#include "rtv1.h"
float	ray_ellipsoid(t_obj obj, const t_ray ray, float *distance, t_init *mlx)
{
	t_var	v;
	t_vect	v1;
	t_vect	p1;
	t_matrix	m;
	float	tmp;

	m.r1 = (t_vect){1 / obj.nor.x, 0, 0};
	m.r2 = (t_vect){0, 1 / obj.nor.y, 0};
	m.r3 = (t_vect){0, 0, 1 / obj.nor.z};

	v1 = ft_matrix_mult(m, ray.dir);
	p1 = ft_vec_sub(ft_matrix_mult(m, ray.pos), ft_matrix_mult(m, obj.pos));
	v.a = ft_vec_dot(v1, v1);
	v.b = 2 * ft_vec_dot(p1, v1);
	v.c = ft_vec_dot(p1, p1) - 1;
	v.d = (v.b * v.b) - (4 * v.a * v.c);
	if (v.d < 0)
		return 0;
	v.t1 = (-v.b - sqrtf(v.d)) / (2 * v.a);
	v.t2 = (-v.b + sqrtf(v.d)) / (2 * v.a);
	tmp = ft_fmin_positive(v.t1, v.t2);
	if (tmp < *distance && tmp > 0)
	{
		*distance = tmp;
		return 1;
	}
	return 0;
}
/*
   * * ellipsoid with direction
*/
/*
float	ray_ellipsoid(t_obj obj, const t_ray ray, float *distance, t_init *mlx)
{
	float a1;
	float a2;
	t_var v;
	t_vect x;

	x = ft_vec_sub(ray.pos, obj.pos);
	a1 = 2 * obj.R * ft_vec_dot(ray.dir, obj.dir);
	a2 = obj.r * obj.r + 2 * obj.R * ft_vec_dot(x, obj.dir) - obj.R;
	v.a = 4 * obj.r * obj.r * ft_vec_dot(ray.dir, ray.dir) - a1 * a1;
	v.b = 2 * (4 * obj.r * obj.r * ft_vec_dot(ray.dir, x) - a1 * a2);
	v.c = 4 * obj.r * obj.r * ft_vec_dot(x, x) - a2 * a2;
	v.d = (v.b * v.b) - (4 * v.a * v.c);
	if (v.d < 0)
		return 0;
	v.t1 = (-v.b - sqrtf(v.d)) / (2 * v.a);
	v.t2 = (-v.b + sqrtf(v.d)) / (2 * v.a);
	tmp = ft_fmin_positive(v.t1, v.t2);
	if (tmp < *distance && tmp > 0)
	{
		*distance = tmp;
		return 1;
	}
	return 0;
}
*/
