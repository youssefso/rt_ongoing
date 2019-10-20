#include "rtv1.h"
/*int                ft_hyperboloid_inter(t_ray *ray, t_hyper *hyper)
{
	t_vec4    dist;
	double    dsq;
	double    abc[3];
	double    t[2];

	abc[0] = ray->dir.x * ray->dir.x + ray->dir.z * ray->dir.z -
		ray->dir.y * ray->dir.y;
	dist = ft_vec4_sub(ray->origin, hyper->center);
	abc[1] = 2 * (dist.x * ray->dir.x + dist.z * ray->dir.z -
			dist.y * ray->dir.y);
	abc[2] = (dist.x * dist.x + dist.z * dist.z - dist.y * dist.y) - hyper->k;
	dsq = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if (dsq < 0)
		return (0);
	dsq = sqrt(dsq);
	t[0] = (-abc[1] + dsq) / (2 * abc[0]);
	t[1] = (-abc[1] - dsq) / (2 * abc[0]);
	return (ft_check_distance(t, ray));
}*/

/*
   * * z^2 + k = x^2 + y^2;
*/

float	ray_hyperboloid(t_obj obj, const t_ray ray, float *distance, t_init *mlx)
{
	t_var v;
	float tmp;
	t_vect d;
	t_vect c;

	d = ray.dir;
	c = ray.pos;
	v.a = d.z * d.z - d.x * d.x - d.y * d.y;
	v.b =  2 * (c.z * d.z - c.x * d.x - c.y * d.y);
	v.c = c.z * c.z + obj.nor.x - c.x * c.x - c.y * c.y;
	v.d = v.b * v.b - 4 * v.a * v.c;
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
