/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/05/29 09:05:26 by syl              ###   ########.fr       */
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
	int		t; // 0 si c est un vecteur, 1 si c est un point. 
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
	float	difuse; // a voir pour bonus...
	float	specular; // a boir pour bonus...
	float	diam;
	float	height;
	t_coord	*v_axe; 
	int		type;
	bool	closed_up; // pour cylindres si fermes ou pas
	bool	closed_down; // pareil
	//
	float	*m_transl; // matrice de translation
	float	*m_rot; // matrice rotation
	float	*m_scale; // matrice scaling
	float	*m_transf; // matrice transformation
	float	*m_inv; // matrice inverse
	t_coord	*v_axe_r;
	t_coord	*from;
	t_coord	*v_sph_camera;
	float	radius;
}	t_obj;

typedef struct s_light
{
	t_coord		*p_coord;
	float		ratio;
	t_color		*color; // a initialiser a blanc pour la partie obligatoire. Revoir ce calcul pour les lumieres colorees. 
}	t_light;

// A garder
typedef struct s_camera
{
	t_coord		*p_coord;
	t_coord		*v_axe;
	float		fov;
	t_coord		*p_zero; // vraiment utile??
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

// la structure a ete deplacee au dernier moment par le mate. Je sais pas ce qui est utilise mnt...
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

//POUR NOUVELLE DATA STRUCT
typedef struct s_scene
{
	int		nb_sphere;
	int		nb_plan;
	int		nb_cylinder;
	int		nb_lights;
	int		wnd_height;
	int		wnd_width;
	t_camera	*cam; // camera ok
	t_image		*ima; // 
	t_obj		***obj; // tous les objets. allocation et free fonctionne. 
	t_light		***lux;
	bool	bonus_mode;
//	int background_color;
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
	//ray main
	//ray 
	//ray next pour recursivite et ce sera a changer dans clean shuttle. 
	t_coord		*r_origin_m; //ray modifie par matrice a recalculer pour chaque objet
	t_coord		*r_dir_m;
	// tout ca modifie avec calcul intersection
//	float		t1;// distance de l intersection NECASSAIRE?
//	float		t2; // distance de l intersection 2 NECESSAIRE?
	//closest obj
	int			t_count; // nombre d intersection. Pas vraiment utilise sauf pour le caps des cylindres
	float		closestt;
	int			obj_a;//copie dans pix
	int			obj_b;
	t_coord		*r_dir_closest_obj;
	t_coord		*r_origin_closest_obj;

	t_coord		*v_sph_camera;// a supprimer?
	t_coord		*origin_zero;
	/////// DEUXIEME PARTIE
	 // coord (0,0,0) ON PEUT COORS OBJ [0][0] besoin dans intersect sphere
	t_coord	*object_normal; // in prepare comp. 
	t_coord	*p_touch;// in prepare comp. 
	t_coord	*v_eye;// in prepare comp. 
	t_coord	*v_norm_parral;// in prepare comp.
	float	*transp_inv; // in raytracer. 
	t_coord	*p_space; // in prepare comps. 
	float	*obj_inv;
//	bool	inside;
	t_coord	*v_light_to_point;
	float	distance_light_p_touch;
	t_coord	*v_sphere_to_point;
	t_coord	*v_point_to_light; // reuse for ray reflexion??
	t_coord	*reflect_dir;
	t_coord	*scalar;
	t_coord	*view_dir;
	//bonus
	t_coord *r_ray_relf_origin;// pas encore utilise
	t_coord *r_ray_relf_dir;// pas encore utilise
	t_coord	*r_next_ray_origin;
	t_coord *r_next_ray_dir;
	bool		is_avaible; //or mutex???
} t_mem;

//dans bonus regarder si objet modifie. 
typedef struct s_pix
{
	// elements propres a chaque pixel pour ses calculs. 
	t_coord		*p_viewport;// a voir plus tard pour simplifier pour calculer le ray. utilise 1 fois
	t_coord		*p_viewport_world; // a voir plus tard pour simplifier pour calculer le ray. utilise 1 fois
	t_coord		*r_origin; // RAY! =) renommer ray_pix_origin
	t_coord		*r_dir; // RAY! =) renommer ray_pix_dir
	t_color		*color; //  =)
	// a faire une copie apres avoir trouve closest obj
	int			obj_a;//rename type 
	int			obj_b;//rename obj num
	//avaible or done for threads....
}	t_pix;


#endif