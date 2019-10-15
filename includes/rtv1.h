/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:32:17 by nhamid            #+#    #+#             */
/*   Updated: 2019/10/15 18:06:26 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# define BUF_SIZE 100
# define HEIGHT 600
# define WIDTH 600
# define MAP_SIZE 1
# define INFINIT 1e4

# define DARK 0.15f
# include "libft.h"

typedef struct	s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

typedef struct	s_ray
{
	t_vect	dir;
	t_vect	pos;
	float	dir_mod;
}				t_ray;

enum {sphere = 0, cone, cylinder, plane, torus, ellipsoid, paraboloid};
enum {trs = 1, rt, dir, col, pos, nor};
enum {spote = 0, directionnel, area};
typedef struct	s_cam
{
	t_vect	ray;
	t_vect	pos;
	float	x;
	float	y;
	t_vect	hit_col;
}				t_cam;

typedef struct	s_var
{
	float a;
	float b;
	float c;
	float d;
	float e;
	float t1;
	float t2;
}				t_var;

typedef struct	s_obj
{
	int				id;
	int				type;
	t_vect			pos;
	t_vect			trs;
	t_vect			rot;
	t_vect			col;
	t_vect			dir;
	float			rad;
	float			dif;
	t_vect			nor;
	float			m;
	float			hit_dist;
	float			r;
	float			R;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_sce
{
	t_vect			cam_pos;
	t_vect			cam_rot;
	t_vect			cam_trs;
	t_vect			light_pos;
	t_vect			light_dir;
	int				light_type;
	t_vect			light_ang;
	float			power;
}				t_sce;

typedef struct	s_val
{
	float	dis;
	t_obj	obj;
	t_vect	col;
	float	m;
}				t_val;

typedef struct	s_config
{
	t_sce scene;
	t_obj *obj;
	t_vect	baked_ray;
}				t_config;

typedef struct	s_matrix
{
	t_vect	r1;
	t_vect	r2;
	t_vect	r3;
}				t_matrix;

typedef struct	s_init
{
	void			*mlx;
	void			*win;
	void			*init;
	void			*img;
	unsigned char	*img_str;
	int				x; // delete me <> for debug
	int				y; // delete me <> for debug
	t_vect			light_pos;
	t_sce			*sce;
	t_obj			*obj;
	t_obj			*selected_obj;
	t_config		p;
	float			m;
}				t_init;

t_vect			normal_paraboloid(const t_obj obj, const t_vect hit_point, t_init mlx);
float			light_ray_paraboloid(t_obj obj, const t_ray ry);
float			ray_paraboloid(t_obj obj, const t_ray ray, float *distance, t_init *mlx);
t_vect			normal_ellipsoid(const t_obj obj, const t_vect hit_point, t_init mlx);
float			light_ray_ellipsoid(t_obj obj, const t_ray ry);
t_vect			ft_matrix_mult(t_matrix m, t_vect v);
void			ft_pvect(char *str, t_vect v);
float			ray_ellipsoid(t_obj obj, const t_ray ray, float *distance, t_init *mlx);
float			ray_cylinder_close(t_obj obj, const t_ray ray, float *distance, t_init *mlx);
float			ray_cone_close(t_obj obj, const t_ray ray, float *distance, t_init *mlx);
t_ray			ft_rot_obj(t_obj obj, t_ray ray);
t_vect			ft_rot_x(t_vect v, double a);
t_vect			ft_rot_y(t_vect v, double a);
t_vect			ft_rot_z(t_vect v, double a);
t_vect			ft_rot(t_vect v,  t_vect rot);
float			light_ray_torus(t_obj obj, const t_ray ray);
float			light_ray_cylinder(t_obj obj, const t_ray ray);
float			light_ray_plane(t_obj obj, const t_ray ray);
t_vect			normal_torus(const t_obj obj, const t_vect hit_point, t_init mlx);
int				SolveQuartic(double w[5], double s[4]);
int				ft_solve_quadric(double c[3], double s[2]);
int				ft_solve_cubic(double w[4], double s[3]);
int				ft_solve_quartic(double w[5], double s[4]);
float			ray_torus(t_obj obj, const t_ray ray, float *distance, t_init *mlx);
t_vect			normal_plane(const t_obj obj, const t_vect hit_point, t_init mlx);
t_vect			normal_cylinder(const t_obj obj, const t_vect hit_point, t_init mlx);
float			light_ray_sphere(const t_obj obj, const t_ray ray);
float			light_ray_cone(const t_obj obj, const t_ray ray);
void			ft_light_obj_loop(t_obj *obj, int obj_id, t_ray ray, float *f);
float			ft_vec_modul(t_vect	v);
t_vect			normal_sphere(const t_obj obj, const t_vect hit_point, t_init mlx);
t_vect			normal_cone(const t_obj obj, const t_vect hit_point, t_init mlx);
float			ray_cylinder(t_obj obj, const t_ray ray, float *distance, t_init *mlx);
float			ray_plane(t_obj obj, const t_ray ray, float *distance, t_init *mlx);
float			ft_fmin_positive(const float a, const float b);
void			ft_light_pixel(t_init mlx, t_vect col);
void			ft_vec_normalize(t_vect *v1);
float			ft_vec_dot(const t_vect v1, const t_vect v2);
t_vect			ft_vec_sub(const t_vect v1, const t_vect v2);
t_vect			ft_vec_sum(const t_vect v1, const t_vect v2);
t_vect			ft_vec_multr(const t_vect v1, float a);
void			ft_light(t_obj obj, t_config p, t_vect hit_point, t_init init);
float			ray_sphere(t_obj obj, const t_ray ray, float *distance, t_init *mlx);
float			ray_cone(t_obj obj, const t_ray ray, float *distance, t_init *mlx);
void			ft_rt_init(t_config data, t_init m_lx);
void			send_ray(t_config p, t_init mlx);
t_vect			bake_ray(int x, int y, t_sce scene);
int				get_next_line(const int fd, char **line);

#endif
