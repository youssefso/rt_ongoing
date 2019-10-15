#include "rtv1.h"

t_vect	ft_matrix_mult(t_matrix m, t_vect v)
{
	t_vect	v1;

	v1.x = m.r1.x * v.x + m.r1.y * v.y + m.r1.z * v.z;
	v1.y = m.r2.x * v.x + m.r2.y * v.y + m.r2.z * v.z;
	v1.z = m.r3.x * v.x + m.r3.y * v.y + m.r3.z * v.z;

	return (v1);
}
