#include "rtparse.h"
#include "rtv1.h"

int closest_obj(t_config p, t_init mlx, int x, int y)
{
	const t_obj *obj;
	t_ray ray;
    int obj_id;
	t_vect col;
	float distance = INFINIT;
	float (*pf[5])(t_obj, const t_ray, float *, t_init *) = {ray_sphere, ray_cone_close, ray_cylinder_close, ray_plane, ray_torus};

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

int     mouse_press(int key, int x, int y, t_init *mlx)
{
    int id;

    id = closest_obj(mlx->p, *mlx, x , y);
    if (id >= 0)
        mlx->selected_obj = get_obj_bye_id(id, mlx->p.obj);
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
	mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "RT");
	mlx.img_str = (unsigned char *)mlx_get_data_addr(mlx.img, &bp, &s_l, &endian);
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
		printf("here\n");
		mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	}
	return 0;
}

int main(int ac, char **av)
{
	t_config p;
	t_init	mlx;

	p = ft_parse_file(av[1]);
	mlx.p = p;
	mlx = ft_mlx();
	mlx.p = p;
	ft_rt_init(p, mlx);
	mlx_mouse_hook(mlx.win, mouse_press, &mlx);
	mlx_hook(mlx.win, 2, 1, k_press, &mlx);
	mlx_put_image_to_window(mlx.init, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.init);
	return 0;
}
