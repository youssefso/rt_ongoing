#include "rtv1.h"

static float	ft_sq(float a)
{
	return (a * a);
}
float	ft_vec_modul(t_vect	v)
{
	float	a;

	a = ft_sq(v.x) + ft_sq(v.y) + ft_sq(v.z);
	a = sqrtf(a);
	return a;
}
void	ft_vec_normalize(t_vect *v1)
{
	t_vect	v;
	float	a;

	a = ft_vec_modul(*v1);
	v.x = v1->x / a;
	v.y = v1->y / a;
	v.z = v1->z / a;
	*v1 = v;
}

t_vect	ft_vec_sum(const t_vect v1, const t_vect v2)
{
	t_vect v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return (v);
}

t_vect	ft_vec_multr(const t_vect v1, float a)
{
	t_vect v;
	
	v.x = v1.x * a;
	v.y = v1.y * a;
	v.z = v1.z * a;
	return (v);
}

float	ft_vec_dot(const t_vect v1, const t_vect v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vect	ft_vec_sub(const t_vect v1, const t_vect v2)
{
	t_vect	v;

	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return (v);
}
