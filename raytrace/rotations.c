#include "rtv1.h"
void	ft_pvect(char *str, t_vect v)
{
	printf("%s %f %f %f\n", str, v.x, v.y, v.z);
}
t_vect	ft_rot_x(t_vect v, double a)
{
	t_vect v1;

	v1.x = v.x;
	v1.y = cos(a) * v.y - sin(a) * v.z;
	v1.z = sin(a) * v.y + cos(a) * v.z;
	return v1;
}
t_vect	ft_rot_y(t_vect v, double a)
{
	t_vect v1;

	v1.x = v.x * cos(a) + sin(a) * v.z;
	v1.y = v.y;
	v1.z = -sin(a) * v.x + cos(a) * v.z;
	return v1;
}
t_vect	ft_rot_z(t_vect v, double a)
{
	t_vect v1;

	v1.x = v.x * cos(a) - sin(a) * v.y;
	v1.y = sin(a) * v.x + cos(a) * v.y;
	v1.z = v.z;
	return v1;
}

double	ft_rad(double a)
{
	return (a * M_PI / 180);
}
t_vect	ft_rot(t_vect v,  t_vect rot)
{
	t_vect v1;

	//ft_pvect("v: ", v);
	v1 = ft_rot_x(v, ft_rad(rot.x));
	v1 = ft_rot_y(v1, ft_rad(rot.y));
	v1 = ft_rot_z(v1, ft_rad(rot.z));
	return v1;
}

t_ray	ft_rot_obj(t_obj obj, t_ray ray)
{
	t_vect dir;
	t_vect pos;

	pos = ft_vec_sub(ray.pos, obj.pos);
	pos = ft_rot(pos, ft_vec_multr(obj.rot, -1));
	pos = ft_vec_sum(pos, obj.pos);
	dir = ft_rot(ray.dir, ft_vec_multr(obj.rot, -1));
	ray.pos = pos;
	ray.dir = dir;
	return ray;
}
