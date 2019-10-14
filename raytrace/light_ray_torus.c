#include "rtv1.h"

static	float	f_d(float a)
{
	return a * a;
}
float	light_ray_torus(t_obj obj, const t_ray ray)
{
	t_vect x;
	double m, n, o, p;
	double c[5];
	double s[4];
	int i = 0;
	int k;

	x = ft_vec_sub(ray.pos, obj.pos);
	m = 1 - f_d(ft_vec_dot(obj.dir, ray.dir));
	n = 2 * (ft_vec_dot(x, ray.dir) - ft_vec_dot(obj.dir, x) * ft_vec_dot(obj.dir, ray.dir));
	o = ft_vec_dot(x, x) - f_d(ft_vec_dot(obj.dir, x));
	p = ft_vec_dot(x, x) + obj.R * obj.R - obj.r * obj.r;
	c[4] = 1;
	c[3] = 4 * ft_vec_dot(x, ray.dir);
	c[2] = 2 * p + c[3] * c[3] * 0.25 - 4 * m * obj.R * obj.R;
	c[1] = c[3] * p - 4 * n * obj.R * obj.R;
	c[0] = p * p - 4 * obj.R * obj.R * o;
	if ((k = ft_solve_quartic(c, s)))
	{
		while (i < k)
		{
			if (s[i] > 0 && s[i] < ray.dir_mod)
				return 1;
			i++;
		}
	}
	return 0;
}
