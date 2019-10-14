#include "rtv1.h"

static float	ft_max(float a, float b)
{
	return ((a > b)? a: b);
}

static float	ft_min(float a, float b)
{
	return ((a < b)? a: b);
}

float	ft_fmin_positive(const float a, const float b)
{
	float c;

	c = ft_min(a, b);
	if (c < 0)
		c = ft_max(a, b);
	if (c < 0)
		return (0);
	return (c);
}
