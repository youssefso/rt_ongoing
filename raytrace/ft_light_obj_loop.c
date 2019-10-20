#include "rtv1.h"

void	ft_light_obj_loop(t_obj *obj, int obj_id, t_ray ray, float *f) // loop on all object with ray (interesction point to light 
{
	float (*ft_p[8])(const t_obj, const t_ray) = {light_ray_sphere, light_ray_cone,light_ray_cylinder, light_ray_plane, light_ray_torus, light_ray_ellipsoid \
	, light_ray_paraboloid, light_ray_hyperboloid};

	while (obj != NULL)
	{
		if (obj->id != obj_id)
		{
			if (ft_p[obj->type](*obj, ray))
				*f = DARK;
		}
		obj = obj->next;
	}
}
