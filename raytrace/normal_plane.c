#include "rtv1.h"

t_vect	normal_plane(const t_obj obj, const t_vect hit_point, t_init mlx)
{
	t_vect	normal;
	t_vect	v;
	float f;

	v = ft_vec_sub(mlx.p.scene.cam_pos, obj.pos);
	ft_vec_normalize(&v);
	normal = obj.nor; // [to do] oriante normal to light
	f = ft_vec_dot(v, normal);
	if (f < 0)
		normal = ft_vec_multr(normal, -1);
	return (normal);
}
