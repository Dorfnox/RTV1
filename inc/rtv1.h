/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:11:51 by bpierce           #+#    #+#             */
/*   Updated: 2018/01/25 18:35:36 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "rtv1_macros.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pthread.h>

# define W 800
# define H 600

typedef struct			s_grid
{
	int					start_x;
	int					end_x;
	int					start_y;
	int					end_y;
}						t_grid;

typedef struct			s_xy
{
	double				x;
	double				y;
}						t_xy;

typedef struct			s_xyz
{
	double				x;
	double				y;
	double				z;
}						t_xyz;

typedef struct			s_colour
{
	unsigned int		r;
	unsigned int		g;
	unsigned int		b;
}						t_colour;

typedef struct			s_image
{
	void				*img;
	int					*pix;
	int					bpp;
	int					endian;
	int					w;
	int					h;
}						t_image;

typedef struct			s_rotate_math
{
	int					x;
	int					y;
	double				x_coor;
	double				y_coor;
	double				z_coor;
	double				cos;
	double				sin;
	t_xyz				camera;
}						t_rotate_math;

typedef struct			s_sphere_intersect
{
	t_xyz				dist;
	double				b;
	double				d;
	double				t0;
	double				t1;
	double				*t;
	double				sqroot;
}						t_sphere_intersect;

typedef struct			s_cylinder_intersect
{
	double				a;
	double				b;
	double				c;
	double				dot;
	t_xyz				a_temp;
	t_xyz				b_temp;
	t_xyz				delta_p;
	t_xyz				tmp;
}						t_cylinder_intersect;

typedef struct			s_cone_intersect
{
	double				a;
	double				b;
	double				c;
	double				a_temp;
	double				b_temp;
	double				cos2;
}						t_cone_intersect;

typedef struct			s_obj
{
	unsigned int		type:3;
	t_xyz				pos;
	t_xyz				rot;
	t_colour			colour;
	int					colour_hex;
	int					size;
	int					brghtnss;
	int					shine;
	int					radius;
	int					width;
	int					height;
	double				albedo;
	double				(*intersect)(struct s_obj *, t_xyz *, t_xyz *);
	t_xyz				(*normal)(struct s_obj *, t_xyz *);
	t_xyz				plane_normal;
	t_xyz				vector;
	double				angle;
	struct s_obj		*next;
}						t_obj;

typedef struct			s_light
{
	t_xyz				pos;
	t_colour			colour;
	double				intensity;
	unsigned int		falloff:2;
	struct s_light		*next;
}						t_light;

typedef struct			s_light_ray
{
	t_light				*l;
	t_xyz				v;
	t_colour			c;
}						t_light_ray;

typedef struct			s_trig
{
	unsigned int		editor_panel:1;
	unsigned int		display_info_panel:1;
	unsigned int		rotate_object_pos_x:1;
	unsigned int		rotate_object_neg_x:1;
	unsigned int		rotate_object_pos_y:1;
	unsigned int		rotate_object_neg_y:1;
	unsigned int		rotate_object_pos_z:1;
	unsigned int		rotate_object_neg_z:1;
	unsigned int		translate_object_pos_x:1;
	unsigned int		translate_object_neg_x:1;
	unsigned int		translate_object_pos_y:1;
	unsigned int		translate_object_neg_y:1;
	unsigned int		translate_object_pos_z:1;
	unsigned int		translate_object_neg_z:1;
	unsigned int		rotate_camera_pos_x:1;
	unsigned int		rotate_camera_neg_x:1;
	unsigned int		rotate_camera_pos_y:1;
	unsigned int		rotate_camera_neg_y:1;
	unsigned int		rotate_camera_pos_z:1;
	unsigned int		rotate_camera_neg_z:1;
	unsigned int		translate_camera_pos_x:1;
	unsigned int		translate_camera_neg_x:1;
	unsigned int		translate_camera_pos_y:1;
	unsigned int		translate_camera_neg_y:1;
	unsigned int		translate_camera_pos_z:1;
	unsigned int		translate_camera_neg_z:1;
}						t_trig;

typedef struct			s_info_panel
{
	struct s_image		*topleft;
	struct s_image		*topright;
	struct s_image		*bot;
}						t_info_panel;

typedef struct			s_settings
{
	t_xyz				camera;
	t_xyz				*normalized_vector_ray;
	int					num_objs;
	struct s_obj		*shortcut_to_object_currently_being_edited;
	double				translate_speed;
	double				rotate_speed;
	int					max_ray_depth;
	double				max_draw_dist;
	double				shadow_bias;
	double				fov;
	double				aspect_ratio;
	int					num_of_threads;
	void				*(*raytrace_func)(void *);
}						t_settings;

typedef struct			s_rt
{
	void				*mlx;
	void				*win;
	void				(**kp)(struct s_rt *);
	void				(**kr)(struct s_rt *);
	struct s_obj		*obj;
	struct s_light		*light;
	struct s_trig		*trig;
	struct s_image		*img;
	struct s_info_panel	*info_panel;
	struct s_settings	*settings;
}						t_rt;

typedef struct			s_thready
{
	t_grid				g;
	t_rt				*rt;
}						t_thready;

/*
** ┌───────────────────────────────────────────────────────────────────────────┐
** │ On initialization functions                                               │
** └───────────────────────────────────────────────────────────────────────────┘
*/

t_rt					*initialize_rt(void *mlx, char *f);
int						set_triple_values(t_xyz *xyz, t_colour *c, char *line);
t_obj					*new_obj(void);
t_obj					*get_obj_list(char *file);
t_light					*new_light(void);
t_light					*get_light_list(char *file);
t_settings				*new_settings(void);
t_settings				*get_settings(t_rt *rt, char *file);
t_info_panel			*get_info_panels(t_rt *rt);
t_image					*new_image(t_rt *rt, int width, int height);
void					fill_image_with_colour(t_image *i, int c);
void					protect_array(t_rt *rt);
void					set_key_presses(void (**kp)(t_rt *));
void					set_key_releases(void (**kr)(t_rt *));
void					set_arrays(t_rt *rt);

/*
** ┌───────────────────────────────────────────────────────────────────────────┐
** │ Program Runtime Environment                                               │
** └───────────────────────────────────────────────────────────────────────────┘
*/
void					draw_stuff(t_rt *rt);

t_xyz					vector(double x, double y, double z);
t_xyz					vector_diff(t_xyz *a, t_xyz *b);
double					vector_dist(t_xyz *v);
double					dot_product(t_xyz *a, t_xyz *b);
void					normalize_vector(t_xyz *v);

t_xyz					vector_add(t_xyz *a, t_xyz *b, double b_mult_constant);
t_xyz					vector_subtract(t_xyz *a, t_xyz *b,
						double b_mult_constant);
void					flip_vector(t_xyz *v);
t_xyz					pos_on_object(double distance, t_xyz *view_vector);
t_xyz					convert_hitpos_to_worldspace(t_xyz *p,
						t_xyz *camera_pos);

t_xy					solve_quadratic(double a, double b, double c);
double					solve_pythagoras(t_xyz *start, t_xyz *finish);

void					normalize_and_set_light_colour(t_light *l,
						t_xyz *l_v, t_colour *c, double *l_dist);
void					add_light_contribution(t_colour *new_c,
						t_colour *light_c, t_colour *obj_c, double ratio);

double					sphere_intersect(t_obj *o, t_xyz *ro, t_xyz *rv);
double					plane_intersect(t_obj *o, t_xyz *ro, t_xyz *rv);
double					cylinder_intersect(t_obj *o, t_xyz *ro, t_xyz *rv);
double					cone_intersect(t_obj *o, t_xyz *ro, t_xyz *rv);
t_xyz					sphere_normal(t_obj *o, t_xyz *hitpos);
t_xyz					plane_normal(t_obj *o, t_xyz *hitpos);
t_xyz					cylinder_normal(t_obj *o, t_xyz *hitpos);
t_xyz					cone_normal(t_obj *o, t_xyz *hitpos);
void					set_sphere_reqs(t_obj *o);
void					set_plane_reqs(t_obj *o);
void					set_cylinder_reqs(t_obj *o);
void					set_cone_reqs(t_obj *o);

void					*raytrace(void *container);
void					*raytrace_light(void *container);

void					display_info_panel(t_rt *rt);

/*
** Rotate things
*/
void					rotate_vector_x(t_xyz *n_vector, double radians);
void					rotate_vector_y(t_xyz *n_vector, double radians);
void					rotate_vector_z(t_xyz *n_vector, double radians);
void					rotate_camera_x(t_xyz *nva, t_xyz *camera_pos,
						double radians);
void					rotate_camera_y(t_xyz *nva, t_xyz *camera_pos,
						double radians);
void					rotate_camera_z(t_xyz *nva, t_xyz *camera_pos,
						double radians);

/*
** ┌───────────────────────────────────────────────────────────────────────────┐
** │ On exit functions                                                         │
** └───────────────────────────────────────────────────────────────────────────┘
*/
int						free_stuff(t_rt *rt);

/*
** ┌───────────────────────────────────────────────────────────────────────────┐
** │ Hook functions                                                            │
** └───────────────────────────────────────────────────────────────────────────┘
*/

int						key_press(int keycode, t_rt *rt);
int						key_release(int keycode, t_rt *rt);
int						mouse_press(int button, int x, int y, t_rt *rt);
int						mouse_release(int button, int x, int y, t_rt *rt);
int						mouse_move(int x, int y, t_rt *rt);
int						expose_i_guess(t_rt *rt);
int						forever_loop(t_rt *rt);
int						exit_window(t_rt *rt);

void					exit_window_kp(t_rt *rt);
void					shift_keys(t_rt *rt);
void					unshift_keys(t_rt *rt);

void					trig_display_info_panel(t_rt *rt);
void					increase_rotation_speed(t_rt *rt);
void					decrease_rotation_speed(t_rt *rt);
void					increase_translation_speed(t_rt *rt);
void					decrease_translation_speed(t_rt *rt);

/*
** Choose Raytrace & Lighting Model
*/
void					trig_raytrace(t_rt *rt);
void					trig_raytrace_light(t_rt *rt);

void					trig_no_falloff_light(t_rt *rt);
void					trig_linear_falloff_light(t_rt *rt);
void					trig_square_falloff_light(t_rt *rt);
void					trig_no_light(t_rt *rt);

/*
** Rotate Objects
*/
void					trig_rotate_object_pos_x(t_rt *rt);
void					untrig_rotate_object_pos_x(t_rt *rt);
void					trig_rotate_object_neg_x(t_rt *rt);
void					untrig_rotate_object_neg_x(t_rt *rt);

void					trig_rotate_object_pos_y(t_rt *rt);
void					untrig_rotate_object_pos_y(t_rt *rt);
void					trig_rotate_object_neg_y(t_rt *rt);
void					untrig_rotate_object_neg_y(t_rt *rt);

void					trig_rotate_object_pos_z(t_rt *rt);
void					untrig_rotate_object_pos_z(t_rt *rt);
void					trig_rotate_object_neg_z(t_rt *rt);
void					untrig_rotate_object_neg_z(t_rt *rt);

/*
** Translate Objects
*/
void					trig_translate_object_pos_x(t_rt *rt);
void					trig_translate_object_neg_x(t_rt *rt);
void					untrig_translate_object_pos_x(t_rt *rt);
void					untrig_translate_object_neg_x(t_rt *rt);

void					trig_translate_object_pos_y(t_rt *rt);
void					trig_translate_object_neg_y(t_rt *rt);
void					untrig_translate_object_pos_y(t_rt *rt);
void					untrig_translate_object_neg_y(t_rt *rt);

void					trig_translate_object_pos_z(t_rt *rt);
void					trig_translate_object_neg_z(t_rt *rt);
void					untrig_translate_object_pos_z(t_rt *rt);
void					untrig_translate_object_neg_z(t_rt *rt);

/*
** Rotate Camera
*/
void					trig_rotate_camera_pos_x(t_rt *rt);
void					untrig_rotate_camera_pos_x(t_rt *rt);
void					trig_rotate_camera_neg_x(t_rt *rt);
void					untrig_rotate_camera_neg_x(t_rt *rt);

void					trig_rotate_camera_pos_y(t_rt *rt);
void					untrig_rotate_camera_pos_y(t_rt *rt);
void					trig_rotate_camera_neg_y(t_rt *rt);
void					untrig_rotate_camera_neg_y(t_rt *rt);

void					trig_rotate_camera_pos_z(t_rt *rt);
void					untrig_rotate_camera_pos_z(t_rt *rt);
void					trig_rotate_camera_neg_z(t_rt *rt);
void					untrig_rotate_camera_neg_z(t_rt *rt);

/*
** Translate Camera
*/
void					trig_translate_camera_pos_x(t_rt *rt);
void					untrig_translate_camera_pos_x(t_rt *rt);
void					trig_translate_camera_neg_x(t_rt *rt);
void					untrig_translate_camera_neg_x(t_rt *rt);

void					trig_translate_camera_pos_y(t_rt *rt);
void					untrig_translate_camera_pos_y(t_rt *rt);
void					trig_translate_camera_neg_y(t_rt *rt);
void					untrig_translate_camera_neg_y(t_rt *rt);

void					trig_translate_camera_pos_z(t_rt *rt);
void					untrig_translate_camera_pos_z(t_rt *rt);
void					trig_translate_camera_neg_z(t_rt *rt);
void					untrig_translate_camera_neg_z(t_rt *rt);

#endif
