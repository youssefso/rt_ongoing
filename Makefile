NAME= rt
R_SRC= normal_hyperboloid.c light_ray_hyperboloid.c ray_hyperboloid.c normal_paraboloid.c ray_paraboloid.c light_ray_paraboloid.c normal_ellipsoid.c light_ray_ellipsoid.c matrix_operation.c ray_ellipsoid.c rotations.c light_ray_torus.c light_ray_cylinder.c light_ray_plane.c normal_torus.c quartic.c cubic.c quadric.c test_quadric.c ray_torus.c normal_plane.c normal_cylinder.c normal_cone.c light_ray_sphere.c light_ray_cone.c ft_light_obj_loop.c normal_sphere.c ray_cylinder.c ft_light.c ray_plane.c ray_cone.c ft_fmin_positive.c init.c bake_ray.c ft_light_pixel.c ray_sphere.c send_ray.c vec_operation.c
SRC= main.c
R_OBJ= $(R_SRC:.c=.o)
OBJ= $(SRC:.c=.o)
INC= -I ./includes
LIBS= libft/libft.a
P_LIBS= parse/parse.a
OBJDIR:= obj
SRCDIR:= ./raytrace
OBJECT:= $(addprefix $(OBJDIR)/, $(R_OBJ))
MLX = -framework appkit -framework opengl -lmlx
all: $(NAME)

$(NAME): $(OBJECT) $(OBJ) $(P_LIBS) $(LIBS)
	gcc -o $(NAME) $(OBJ) $(OBJECT) $(LIBS) $(MLX) $(P_LIBS)

%.o: %.c
	gcc -c $< $(INC)

$(P_LIBS):
	make -C parse

$(LIBS):
	make -C libft
	
$(OBJECT): $(OBJDIR)/%.o: $(SRCDIR)/%.c
	gcc $(INC) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJECT)
	make clean -C libft
	make clean -C parse

fclean: clean
	rm -rf $(NAME) $(LIBS) $(P_LIBS)

re: fclean all
