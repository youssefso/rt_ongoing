#include "rtv1.h"

t_vect	bake_ray(int x, int y, t_sce sce)
{
	t_vect baked_ray;

	//cast to float cause the result will be int if don't do so;
	baked_ray.x = x / (float)WIDTH - 0.5;
	baked_ray.y = y / (float)HEIGHT - 0.5;
	baked_ray.z = 1;
	ft_vec_normalize(&baked_ray);
	baked_ray = ft_rot(baked_ray, sce.cam_rot);
	return (baked_ray);
}
