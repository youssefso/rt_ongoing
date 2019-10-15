#include "rtv1.h"
#include "libft.h"

static t_vect	ft_hit_point(t_ray ray, float distance)
{
	return (ft_vec_sum(ft_vec_multr(ray.dir, distance), ray.pos));
}

void	send_ray(t_config p, t_init mlx)
{
	const t_obj *obj;
	t_ray ray;
	t_obj clone_obj;
	t_vect col;
	float distance = INFINIT;
	float (*pf[7])(t_obj, const t_ray, float *, t_init *) = {ray_sphere, ray_cone, ray_cylinder, ray_plane, ray_torus, ray_ellipsoid, ray_paraboloid};
	float a = 0;

	ray.dir = p.baked_ray;
	ft_vec_normalize(&(ray.dir));
	ray.pos = p.scene.cam_pos;
	obj = p.obj; // obj now containe all objects
	while (obj != NULL)
	{
		if (pf[obj->type](*obj, ray, &distance, &mlx))
		{
			a = 1;
			clone_obj = *obj;
		}
		obj = obj->next;
	}
	//if (clone_obj.type == paraboloid && distance != INFINIT)
	//	ft_light_pixel(mlx, clone_obj.col);
	if (distance != INFINIT)
 	{
		ft_light(clone_obj, p, ft_hit_point(ray, distance), mlx);
	}
}
