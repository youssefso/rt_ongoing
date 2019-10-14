#include "rtv1.h"

float	light_ray_plane(t_obj obj, const t_ray ray)
{
	float a;
	float b;
	float t;
	t_vect x;

	a = ft_vec_dot(ray.dir, obj.nor); // if a < 0 normal should be -normal
	if (a == 0)
		return (0);
	x = ft_vec_sub(ray.pos, obj.pos);
	b = ft_vec_dot(x, obj.nor);
	t = -b / a;
	if (t < 0.01f)
		return (0);
	if (t < ray.dir_mod && t > 0)
		return 1;
	return (0);
}
