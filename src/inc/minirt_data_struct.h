/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/10/09 16:16:23 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_STRUCT_H
# define MINIRT_DATA_STRUCT_H

//coordonnes pour vecteurs et points
// 0 si c est un vecteur, 1 si c est un point
typedef struct s_coord
{
	float			x;
	float			y;
	float			z;
	int				t;
}	t_coord;

//couleurs valeurs entre 0 et 1
//rgb en int
typedef struct s_color
{
	float			r;
	float			g;
	float			b;
	int				rgb;
}	t_color;

////////// SCENE //////////
// object[0][0]->color = backgroud color
// object[1][0] spheres
// object[2][0] plans
// object[3][0] cylinder
typedef struct s_pattern
{
	float			scale;
	int				type;
}	t_pattern;

typedef struct s_light
{
	t_coord			*p_coord;
	float			ratio;
	t_color			*color;
}	t_light;

typedef struct s_camera
{
	t_coord			*p_coord;
	t_coord			*v_axe;
	float			fov;
	t_coord			*v_up;
	t_coord			*v_left;
	t_coord			*v_true_up;
	float			*m_orient;
	float			*m_transl;
	float			*m_transf;
	float			*m_inverse;
	float			half_height;
	float			half_width;
	float			pixel_size;
}	t_camera;

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*ima_cmd;
	char			*addr_ima_cmd;
	int				bits_per_pixel_cmd;
	int				line_length_cmd;
	int				endian_cmd;
	void			*ima_blk;
	char			*addr_ima_blk;
	int				bits_per_pixel_blk;
	int				line_length_blk;
	int				endian_blk;
	void			*mlx_ptr;
	void			*mlx_win;
	int				w;
	int				h;
}	t_image;

typedef struct s_obj
{
	t_coord			*p_coord;
	t_color			*color;
	t_color			color2;
	float			diam;
	float			height;
	t_coord			*v_axe;
	int				type;
	float			*m_transl;
	float			*m_rot;
	float			*m_scale;
	float			*m_transf;
	float			*m_inv;
	t_coord			*v_axe_r;
	t_coord			*from;
	t_coord			*v_sph_camera;
	float			radius;
	float			mirror;
	float			difuse;
	float			specular;
	float			transparence;
	float			indice_refract;
	int				number;
	t_coord			*tr_p1;
	t_coord			*tr_p2;
	t_coord			*tr_p3;
	t_coord			*tr_e1;
	t_coord			*tr_e2;
	t_coord			*normal;
	t_pattern		pattern;
	t_image			bump;
	bool			hastexture;
}	t_obj;

typedef struct s_pix
{
	t_color			*color;
	int				obj_a;
	int				obj_b;
}	t_pix;

typedef struct s_intertt
{
	float			t1;
	float			t2;
	int				t_count;
	float			closestt;
}	t_intertt;

//memory_shuttle
typedef struct s_mem
{
	t_coord			*r_base_origin;
	t_coord			*r_base_dir;
	t_coord			*r_origin_m;
	t_coord			*r_dir_m;
	int				t_count;
	float			closestt;
	int				obj_a;
	int				obj_b;
	t_coord			*r_dir_closest_obj;
	t_coord			*r_origin_closest_obj;
	t_coord			*p_viewport;
	t_coord			*p_viewport_world;
	t_coord			*v_sph_camera;
	t_coord			*origin_zero;
	t_coord			*p_touch;
	t_coord			*v_norm_parral;
	float			*transp_inv;
	t_coord			*p_space;
	float			*obj_inv;
	t_coord			*v_light_to_point;
	t_coord			*p_light_to_point;
	float			distance_light_p_touch;
	t_coord			*v_point_to_light;
	t_coord			*reflect_dir;
	t_coord			*scalar;
	t_coord			*view_dir;
	bool			is_avaible;

	//pour multi threading
	int				pix_x;
	int				pix_y;
	int				recursivity_level;
	float			prev_refraction;

	float			percent_shadow;
	t_color			*color_shadow;
	float			percent_new_shadow;
}	t_mem;

typedef struct s_scene
{
	int				nb_sphere;
	int				nb_plan;
	int				nb_cylinder;
	int				nb_cone;
	int				nb_triangle;
	int				nb_lights;
	float			wnd_height;
	float			wnd_width;
	t_camera		*cam;
	t_image			*ima;
	t_obj			***obj;
	t_light			***lux;
	t_mem			*mem_shuttle;
	t_pix			***pix;
	bool			bonus_mode;
	bool			preview;
	int				x;
	int				y;
	int				draw_mode;
	int				draw_type;
	int				axe_draw;
	float			size_modif;
	float			size_modif_neg;
	float			after_virgule;

	pthread_mutex_t	mutex_x;
	pthread_mutex_t	mutex_y;
}	t_scene;

// pour savoir s' il ya des doublons de camera et de ambient light
typedef struct s_doublons
{
	int				ambient;
	int				camera;
}	t_doublons;

//rename
typedef struct s_glob
{
	t_pix			***pix;
	t_scene			*scene;
	t_mem			*mem_shuttle;
	int				id;
}	t_glob;

#endif
