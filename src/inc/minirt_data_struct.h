/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/06/02 13:41:59 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_DATA_STRUCT_H
# define MINIRT_DATA_STRUCT_H

//coordonnes pour vecteurs et points
typedef struct s_coord
{
	float	x;
	float	y;
	float	z;
	int		t; // 0 si c est un vecteur, 1 si c est un point
}	t_coord;

//couleurs
typedef struct s_color
{
	float	r; //valeurs entre 0 et 1
	float	g; //valeurs entre 0 et 1
	float	b; //valeurs entre 0 et 1
	int		rgb; //valeur une seule int pour afficher sur l image. Calcule a la fin. 
}	t_color;

////////// SCENE //////////
// object[0][0]->color = backgroud color
// object[1][0] spheres
// object[2][0] plans
// object[3][0] cylinder
typedef struct s_obj
{
	t_coord	*p_coord; 
	t_color	*color;
	float	diam;
	float	height;
	t_coord	*v_axe;
	int		type;
	float	*m_transl; // matrice de translation
	float	*m_rot; // matrice rotation
	float	*m_scale; // matrice scaling
	float	*m_transf; // matrice transformation
	float	*m_inv; // matrice inverse
	t_coord	*v_axe_r;
	t_coord	*from;
	t_coord	*v_sph_camera;
	float	radius; //UTILISER DIAM?
	//	bool	closed_up; // pour cylindres si fermes ou pas bonus
//	bool	closed_down; // pareil
	//BONUS
	float mirror;
	float	difuse; // a voir pour bonus... mettre en local_
	float	specular; // a boir pour bonus... mettre en local??
}	t_obj;

//PARFAIT =)
typedef struct s_light
{
	t_coord		*p_coord;
	float		ratio;
	t_color		*color;
}	t_light;

//PARFAIT =)
// Pourrait etre simplifie mais c est complique pour pas grand chose. Et problemes de norme. 
typedef struct s_camera
{
	t_coord		*p_coord;
	t_coord		*v_axe;
	float		fov;
	t_coord		*v_up; // vecteurs pour calculer l orientation de la cam
	t_coord		*v_left; // vecteurs pour calculer l orientation de la cam
	t_coord		*v_true_up; // vecteurs pour calculer l orientation de la cam
	float		*m_orient; // matrice orientation. Important si on veut pouvoir bouger la camera
	float		*m_transl; // matrice translation pour deplacer
	float		*m_transf; // matrice transformation
	float		*m_inverse; // matrice inverse a utiliser pour les calculs des rays de chaque pixel . 
	float		half_height; /// utilise dans init viewport xy
	float		half_width; // utilise dans init viewport xy
	float		pixel_size; //taille des pixels pour calculer les points sur le viewport et les rays
}	t_camera;

// QU EST CE QUI EST VRAIMENT UTILISE?
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	void	*mlx_win;
}	t_image;

//PARFAIT =)
typedef struct s_scene
{
	int		nb_sphere;
	int		nb_plan;
	int		nb_cylinder;
	int		nb_lights;
	int		wnd_height;
	int		wnd_width;
	t_camera	*cam;
	t_image		*ima;
	t_obj		***obj;
	t_light		***lux;
	bool	bonus_mode;
} t_scene;

//Nouvelle data structure
typedef struct s_intertt
{
	float	t1;
	float	t2;
	int		t_count;
	float	closestt;
} t_intertt;

//POUR NOUVELLE DATA STRUCT
typedef struct s_mem
{
	t_coord		*r_base_origin; // ce sera p touch apres dans recursivite. 
	t_coord		*r_base_dir;
	t_coord		*r_origin_m; //ray modifie par matrice a recalculer pour chaque objet
	t_coord		*r_dir_m;
	// POUR CALCULS INTERSECTIONS
	int			t_count; // nombre d intersection. Pas vraiment utilise sauf pour le caps des cylindres
	float		closestt;//IMPORTANT
	int			obj_a;//IMPORTANT
	int			obj_b;// IMPORTANT
	t_coord		*r_dir_closest_obj; //IMPORTANT
	t_coord		*r_origin_closest_obj; //IMPORTANT
	//POUR CALCUL PIXLES
	t_coord		*p_viewport;// A mettre en local PAS OUBLIER z = -1!!!
	t_coord		*p_viewport_world; //pareil
	/////////////
	t_coord		*v_sph_camera;// a supprimer? a cause norminette
	t_coord		*origin_zero;//a supprimer? a cause norminette
	/////// POUR CALCULS OMBRES / LUMIERES
	t_coord	*p_touch;// IMPORTANT
	t_coord	*v_norm_parral;// IMPORTANT
	float	*transp_inv; // local mais difficile a faire en local
	t_coord	*p_space; // LOCAL
	float	*obj_inv; //MODIFIER??
	t_coord	*v_light_to_point; //IMPORTANT
	float	distance_light_p_touch; //IMPORTANT
	t_coord	*v_point_to_light; // reuse for ray reflexion??
	t_coord	*reflect_dir;//LOCAL
	t_coord	*scalar; //LOCAL mais un peu complique a changer
	t_coord	*view_dir;//LOCAL
	//bonus
	//QQCH SI RECURSIVITE OU NOMBRE RECURSIVITE
	bool		is_avaible; //or mutex???
} t_mem;

//dans bonus regarder si objet modifie. 
typedef struct s_pix
{
	t_color		*color; //  =)
	int			obj_a;//rename type 
	int			obj_b;//rename obj num
}	t_pix;

#endif