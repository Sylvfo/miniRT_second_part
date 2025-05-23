/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_data_struct.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:15:05 by syl               #+#    #+#             */
/*   Updated: 2025/05/23 22:13:02 by syl              ###   ########.fr       */
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

//A EFFACER
// fait par mate pour le parsing. 
// pas utilise dans le code apres. Mais pk pas pour parcourir les objets
typedef struct num_obj
{
	int		sphere;
	int		plan;
	int		cylinder;
	int		light;
}	t_num_obj;

////////// SCENE //////////
// object[0][0]->color = backgroud color
// object[1][0] spheres
// object[2][0] plans
// object[3][0] cylinder
typedef struct s_obj
{
	t_coord	*p_coord; 
	t_color	*color;
	float	difuse;
	float	specular;
	float	diam;
	float	height;
	t_coord	*v_axe; 
	int		type;
	bool	closed_up; // pour cylindres si fermes ou pas
	bool	closed_down; // pareil
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

typedef struct s_camera
{
	t_coord		*p_coord;
	t_coord		*v_axe;
	float		fov;
	t_coord		*p_zero;
	t_coord		*v_up; // vecteurs pour calculer l orientation de la cam
	t_coord		*v_left; // vecteurs pour calculer l orientation de la cam
	t_coord		*v_true_up; // vecteurs pour calculer l orientation de la cam
	float		*m_orient; // matrice orientation. Important si on veut pouvoir bouger la camera
	float		*m_transl; // matrice translation pour deplacer
	float		*m_transf; // matrice transformation
	float		*m_inverse; // matrice inverse a utiliser pour les calculs des rays de chaque pixel . 
	float		view_width; // A RETIRER
	float		view_height;// A RETIRER
	float		canva_height; // A RETIRER
	float		canva_width; // A RETIRER
	float		half_height; /// A RETIRER
	float		half_width; // A RETIRER
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

typedef struct s_hits
{
	float		t1;// distance de l intersection 
	float		t2; // distance de l intersection 2
	int			t_count; // nombre d intersection. Pas vraiment utilise sauf pour le caps des cylindres
	t_coord		*r_origin;// ray de chaque pixel modifier avec les matrices de transformation pour chaque objet
	t_coord		*r_dir; // ray de chaque pixel modifier avec les matrices de transformation pour chaque objet
	int			type;//type d objet intersecte
}	t_hits;

// ca c est toutes les donnees reprises des hits et preparees pour les calcules de la lumieres. 
// ct complique de juste link les choses entre elles donc ya pas mal de copies.
// si on fait la reflexion, il faudra garder en memoire plusieurs objets pour faire les calculs de memoire
// pour l instant il y a en a un seul par pixel
typedef struct s_comps
{
	t_coord	*r_origin; //ray de l objet le plus proche modifie par les matrices. 
	t_coord	*r_dir; //ray de l objet le plus proche modifie par les matrices. 
	float	closestt; // distance de l objet le plus proche
	int		t_count; // nombre d objets intersect. pas tellement utile pour l instant a part pour les caps des cylindres
	int		type; // type d objet croise
	t_obj	*obj; // pointeur sur objet croise. 
	t_color	*obj_color; // couleur de l objet
	t_coord	*origin_zero; // coord (0,0,0) 
	t_coord	*object_normal; // tout le reste besoin pour les calculs de la lumiere. 
	float	*transp_inv;
	t_coord	*p_space;
	float	*obj_inv;
	t_coord	*p_touch;
	t_coord	*v_eye;
	t_coord	*v_norm_parral;
	bool	inside;
	t_coord	*v_light_to_point;
	float	distance_light_p_touch;
	t_coord	*v_sphere_to_point;
	t_coord	*v_point_to_light;
	t_coord	*reflect_dir;
	t_coord	*scalar;
	t_coord	*view_dir;
	float	height;
}	t_comps;

//POUR NOUVELLE DATA STRUCT
typedef struct s_scene
{
	int		nb_sphere;
	int		nb_plan;
	int		nb_cylinder;
	int		nb_lights;
	int		wnd_height;
	int		wnd_width;
	t_camera	*cam; // camera
	t_image		*ima; // 
	t_obj		***obj; // tous les objets. allocation et free fonctionne. 
	t_light		***lux;
	bool	bonus_mode;
} t_scene;

typedef struct s_pix
{
	// pointeurs sur data en commun
	t_camera	*cam; // // A RETIRER
	t_image		*ima; // A RETIRER
	t_obj		***obj; // A RETIRER
	t_light		***lux; // A RETIRER
	// elements propres a chaque pixel pour ses calculs. 
	t_coord		*p_viewport;// pour calculer le ray. utilise 1 fois
	t_coord		*p_viewport_world; // pour calculer le ray. utilise 1 fois
	t_coord		*r_origin; // RAY!
	t_coord		*r_dir; // RAY!
	t_color		*color; // utilise 1 fois avec la light a la fin. mais enregiste avant avec closest obj
	t_hits		***hits; // resultat de tous les 
	t_comps		*comps;
	// obj adresse with x and y or pointer on object??
}	t_pix;


//// A RETIRER
//fait par mate au dernier moment. 
typedef struct s_program_context
{
	t_pix		***pix;
	t_num_obj	*num_obj;
	int			width;
	int			height;
	t_image		*ima;
	void		*mlx_ptr;
	void		*mlx_win;
}	t_program_context;

#endif