#include "rtv1.h"
// make ray with origin >hit_point< and dir >vec from hit_point to light<

float	ft_light_spot(t_obj obj, t_config p, t_vect hit_point, t_ray *ray, t_init mlx)
{
	t_sce scene = p.scene;
	t_vect	normal;
	t_vect	light_hit_vec;// vector from hit point to light point
	t_vect	(*pf[8])(const t_obj, const t_vect, t_init) = {normal_sphere, normal_cone, normal_cylinder, normal_plane, normal_torus, normal_ellipsoid, normal_paraboloid,\
	normal_hyperboloid};
	float	f; // from [0,1] => [0,100](%) of the color;
	
	normal = pf[obj.type](obj, hit_point, mlx);
	light_hit_vec = ft_vec_sub(scene.light_pos, hit_point);
	ray->dir_mod = ft_vec_modul(light_hit_vec);
	ft_vec_normalize(&light_hit_vec);
	ray->dir = light_hit_vec;
	ray->pos = hit_point;
	ft_vec_normalize(&normal);
	f = ft_vec_dot(light_hit_vec, normal);
	if (f < DARK)
		f = DARK;
	return (f);
}

void	ft_light(t_obj obj, t_config p, t_vect hit_point, t_init init)
{
	t_ray	ray; // a ray to send from intersect point to light // and check if it hits an object or not;
	float f;

	if (p.scene.light_type == 0)
	{
		f = ft_light_spot(obj, p, hit_point, &ray, init);
		ft_light_obj_loop(p.obj, obj.id, ray, &f);
	}
	ft_light_pixel(&init, ft_vec_multr(obj.col, f));
}
