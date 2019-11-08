#include "rtv1.h"

void	ft_fix_plane(t_config p)
{
	t_obj *obj;
	t_vect c;
	float a;

	obj = p.obj;
	while (obj != NULL)
	{
		if (obj->type == plane)
		{
			c = ft_vec_sub(obj->pos, p.scene.light_pos);
			ft_vec_normalize(&c);
			a = ft_vec_dot(c, obj->nor);
			if (a > 0)
			{
				obj->nor = ft_vec_multr(obj->nor, -1);
			}
		}
		obj = obj->next;
	}
}


void	ft_rot_objects(t_obj *obj)
{
	t_obj *o;

	o = obj;
	while (o)
	{
		if (o->type == cylinder || o->type == cone || o->type == torus || o->type == paraboloid)
		{
			o->dir = ft_rot(o->dir, o->rot);
		}
		else if (o->type == plane)
			o->nor = ft_rot(o->nor, o->rot);
		o = o->next;
	}
}
void	ft_rt_init(t_config p, t_init mlx)
{
	int x;
	int y;
	unsigned char *tmp;

	ft_fix_plane(p);
	ft_rot_objects(p.obj);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx.x = x; // delete me <> for debug
			mlx.y = y; // delete me <> for debug
			p.baked_ray = bake_ray(x, y, p.scene);
			send_ray(p, mlx); // light pixel in this function
			x++;
		}
		y++;
	}
	tmp = mlx.img_str;
	mlx.img_str = mlx.img_str3;
	mlx.img_str3 = mlx.img_str;
	y = 0;
	p.scene.cam_pos.x += 14;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx.x = x; // delete me <> for debug
			mlx.y = y; // delete me <> for debug
			p.baked_ray = bake_ray(x, y, p.scene);
			send_ray(p, mlx); // light pixel in this function
			x++;
		}
		y++;
	}
	tmp = mlx.img_str;
	mlx.img_str = mlx.img_str2;
	mlx.img_str2 = mlx.img_str;
	p.scene.cam_pos.x -= 28;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx.x = x; // delete me <> for debug
			mlx.y = y; // delete me <> for debug
			p.baked_ray = bake_ray(x, y, p.scene);
			send_ray(p, mlx); // light pixel in this function
			x++;
		}
		y++;
	}
}
