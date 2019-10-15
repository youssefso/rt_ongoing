#include "rtv1.h"

float	ray_paraboloid(t_obj obj, const t_ray ray, float *distance, t_init *mlx)
{
	t_var	v;
	t_vect	x;
	float tmp;
	float k;

	k = obj.R;
	x = ft_vec_sub(ray.pos, obj.pos);
	v.a = ft_vec_dot(ray.dir,ray.dir) - pow(ft_vec_dot(ray.dir, obj.dir), 2);
	v.b = 2 * (ft_vec_dot(ray.dir, x) - ft_vec_dot(ray.dir, obj.dir) * (ft_vec_dot(x, obj.dir) + 2 * k));
	v.c = ft_vec_dot(x, x) - ft_vec_dot(x, obj.dir) * (ft_vec_dot(x, obj.dir) - 4 * k);
	v.d = v.b * v.b - (4 * v.a * v.c);
	if (v.d < 0)
		return 0;
	v.t1 = (-v.b - sqrtf(v.d)) / (2 * v.a);
	v.t2 = (-v.b + sqrtf(v.d)) / (2 * v.a);
	tmp = ft_fmin_positive(v.t1, v.t2);// this fuction return min value or 0 if no positive number is given;
	if (tmp < *distance && tmp > 0)
	{
		mlx->m = ft_vec_dot(ray.dir, obj.dir) * tmp + ft_vec_dot(x, obj.dir);
		*distance = tmp;
		return 1;
	}
	return 0;
}
