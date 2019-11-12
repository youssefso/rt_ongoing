#include "rtparse.h"
#include "rtv1.h"

int closest_obj(t_config p, t_init mlx, int x, int y)
{
	const t_obj *obj;
	t_ray ray;
    int obj_id;
	t_vect col;
	float distance = INFINIT;
	float (*pf[7])(t_obj, const t_ray, float *, t_init *) = {ray_sphere, ray_cone_close, ray_cylinder_close, ray_plane, ray_torus, ray_ellipsoid, ray_paraboloid};

	ray.dir = bake_ray(x, y, p.scene);
	ray.pos = p.scene.cam_pos;
	obj = p.obj; // obj now containe all objects
	while (obj != NULL)
	{
		if (pf[obj->type](*obj, ray, &distance, &mlx))
			obj_id = obj->id;
		obj = obj->next;
	}
	if (distance != INFINIT)
        return obj_id;
    return -1;
}

t_obj   *get_obj_bye_id(int id, t_obj *o)
{
    t_obj *obj;

    obj = o;
    while (obj != NULL)
    {
        if (obj->id == id)
            return obj;
        obj = obj->next;
    }
    return NULL;
}
void	ft_fill(t_init *mlx, int k)
{
	int i = 0;
	int j = 0;
	t_vect v;

	while (j < HEIGHT)
	{
		mlx->y = j;
		i = 0;
		while (i < WIDTH)
		{
			mlx->x = i;
			if (k > WIDTH / 2)
			{
				v.x = 255;
				v.y = 0;
				v.z = 0;
			}
			else {
				v.x = 0;
				v.y = 255;
				v.z = 0;
			}
				ft_light_pixel(mlx, v);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}

int     mouse_press(int key, int x, int y, t_init *mlx)
{
    int id;

	ft_fill(mlx, x);
   // id = closest_obj(mlx->p, *mlx, x , y);
 //   if (id >= 0)
  //      mlx->selected_obj = get_obj_bye_id(id, mlx->p.obj);
    return 0;
}

t_init	ft_mlx()
{
	int bp;
	int s_l;
	int endian;
	t_init mlx;

	mlx.init = mlx_init();
	mlx.img = mlx_new_image(mlx.init, WIDTH, HEIGHT);
	mlx.img2 = mlx_new_image(mlx.init, WIDTH, HEIGHT);
	mlx.img3 = mlx_new_image(mlx.init, WIDTH, HEIGHT);
	mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "RT");
//	mlx.win1 = mlx_new_window(mlx.init, WIDTH, HEIGHT, "RT");
//	mlx.win2 = mlx_new_window(mlx.init, WIDTH, HEIGHT, "RT");
//	mlx.win3 = mlx_new_window(mlx.init, WIDTH, HEIGHT, "RT");
	mlx.img_str = (unsigned char *)mlx_get_data_addr(mlx.img, &bp, &s_l, &endian);
	mlx.img_str2 = (unsigned char *)mlx_get_data_addr(mlx.img2, &bp, &s_l, &endian);
	mlx.img_str3 = (unsigned char *)mlx_get_data_addr(mlx.img3, &bp, &s_l, &endian);
	mlx.selected_obj = NULL;
	return (mlx);
}
void	ft_reset_objects(t_obj *o)
{
	t_obj *obj;

	obj = o;
	while (obj)
	{
		obj->rot.x = 0;
		obj->rot.y = 0;
		obj->rot.z = 0;
		obj = obj->next;
	}
}
int	k_press(int key, t_init *mlx)
{
	printf("key: %d\n", key);

	if (mlx->selected_obj)
	{
		printf("here\n");
		ft_reset_objects(mlx->p.obj);
		printf("here\n");
		if (key == 126)
			mlx->selected_obj->rot.x += 10;
		if (key == 125)
			mlx->selected_obj->rot.x -= 10;
		if (key == 123)
			mlx->selected_obj->rot.y += 10;
		if (key == 124)
			mlx->selected_obj->rot.y -= 10;
		if (key == 40)
			mlx->selected_obj->rot.z += 10;
		if (key == 38)
			mlx->selected_obj->rot.z -= 10;
		ft_bzero(mlx->img_str, WIDTH * HEIGHT * 4);
		ft_rt_init(mlx->p, *mlx);
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	}
	return 0;
}
#define cap(x) (x > 255)? 255:x

void	ft_filter(t_init *mlx)
{
	unsigned char *blue;
	unsigned char *img;
	unsigned char *green;
	unsigned char *tmp;
	int i = 0;

	img = mlx->img_str3;
	blue = mlx->img_str2;
	green = mlx->img_str;
	while (i < WIDTH * HEIGHT * 4)
	{
		if (i % 4 == 1)
			img[i] = cap((img[i - 1] + img[i + 1]) / 4 + img[i]);
		else if (i % 4 == 2)
			blue[i] = cap((blue[i - 1] + blue[i - 2]) / 4 + blue[i]);
		i++;
	}
	i = 0;
	while (i < WIDTH * HEIGHT * 4)
	{
		if (i % 4 == 1)
			green[i] = img[i];
		else if (i % 4 == 2)
			green[i] = blue[i];
		i++;
	}
	mlx->img_str = img;
}

int main(int ac, char **av)
{
	t_config p;
	t_init	mlx;

	p = ft_parse_file(av[1]);
	mlx.p = p;
	mlx = ft_mlx();
	ft_rt_init(p, mlx);
	ft_filter(&mlx);
	mlx_mouse_hook(mlx.win, mouse_press, &mlx);
	mlx_hook(mlx.win, 2, 1, k_press, &mlx);
	mlx_put_image_to_window(mlx.init, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.init);
	return 0;
}
