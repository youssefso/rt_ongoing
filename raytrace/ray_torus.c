#include "rtv1.h"

float	f_q(float a)
{
	return (a * a * a * a);
}
float	f_d(float a)
{
	return (a * a);
}
float	f_t(float a)
{
	return (a * a * a);
}

float	t_vect_mul(const t_vect v1, const t_vect v2)
{
	float a;

	a = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return a;
}

/*
   * * 
   * *
   * *  first torus function "ray_torus" . make torus without direction vector
   * *
   * *
   * *
float	ray_torus(t_obj obj, const t_ray ray, float *distance, t_init *mlx)
{
	double sum_d;
	double e;
	double f;
	double four_a;
	double s[4];
	double c[5];

	sum_d = f_d(ray.dir.x) + f_d(ray.dir.y) + f_d(ray.dir.z);
	e = f_d(ray.pos.x) + f_d(ray.pos.y) + f_d(ray.pos.z) - f_d(obj.R) - f_d(obj.r);
	f = t_vect_mul(ray.pos, ray.dir);
	four_a = 4 * f_d(obj.R);
	c[0] = e * e - four_a * (obj.r * obj.r - f_d(ray.pos.y));
	c[1] = 4 * f * e + 2 * four_a * ray.pos.y * ray.dir.y;
	c[2] = 2 * sum_d * e + 4 * f * f + four_a * ray.dir.y * ray.dir.y;
	c[3] = 4 * sum_d * f;
	c[4] = sum_d * sum_d;
	if (ft_solve_quartic(c, s))
	{
		*distance = 1;
		return 1;
	}
	return 0;
}
*/

/*
   * *
   * * torus with vector // need documentation
   * *
*/

float	ray_torus(t_obj obj, const t_ray ray, float *distance, t_init *mlx)
{
	t_vect x;
	double m, n, o, p;
	double c[5];
	double s[4];
	int i = 0, a = 0;
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
			if (s[i] > 0 && s[i] < *distance)
			{
				a = 1;
				*distance = s[i];
			}
			i++;
		}
		if (a == 1)
			return 1;
	}
	return 0;
}
