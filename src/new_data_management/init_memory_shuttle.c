/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory_shuttle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:38:27 by syl               #+#    #+#             */
/*   Updated: 2025/05/26 14:12:09 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_mem	*init_memory_shuttle(void)
{
	t_mem *mem_shuttle;

	mem_shuttle = NULL;
	mem_shuttle = malloc(sizeof(t_mem));
	if (!mem_shuttle)
		return (NULL);
	memory_shuttle_values_null(mem_shuttle);
	if (init_shuttle_values(mem_shuttle) == false)
	{
		printf("problem with memory shuttle \n");
		free_memory_shuttle(mem_shuttle);
		mem_shuttle = NULL;
		return (NULL);
	}
	return (mem_shuttle);
}

void	memory_shuttle_values_null(t_mem *memory_shuttle)
{
	//coord
	memory_shuttle->r_origin_m = NULL;
	memory_shuttle->r_dir_m = NULL;
	memory_shuttle->v_sph_camera = NULL;
	memory_shuttle->t1 = 0.0;
	memory_shuttle->t2 = 0.0;
	memory_shuttle->t_count = 0.0;
	memory_shuttle->closestt = INT_MAX;
	memory_shuttle->obj_a = NONE;
	memory_shuttle->obj_b = 0;
	memory_shuttle->origin_zero = NULL;
}

bool init_shuttle_values(t_mem *memory_shuttle)
{
	memory_shuttle->r_origin_m = create_point(0, 0, 0);
	if (!memory_shuttle->r_origin_m)
		return (false);
	memory_shuttle->r_dir_m = create_vector(0, 0, 0);
	if (!memory_shuttle->r_dir_m)
		return (false);
	memory_shuttle->v_sph_camera = create_vector(0, 0, 0);
	if (!memory_shuttle->v_sph_camera)
		return (false);
	memory_shuttle->origin_zero = create_point(0, 0, 0);
	if (!memory_shuttle->origin_zero)
		return (false);
	return (true);
}

void	free_memory_shuttle(t_mem *memory_shuttle)
{
	if (memory_shuttle->r_origin_m)
	{
		free(memory_shuttle->r_origin_m);
		memory_shuttle->r_origin_m = NULL;
	}
	if (memory_shuttle->r_dir_m)
	{
		free(memory_shuttle->r_dir_m);
		memory_shuttle->r_dir_m = NULL;
	}
	if (memory_shuttle->v_sph_camera)
	{
		free(memory_shuttle->v_sph_camera);
		memory_shuttle->v_sph_camera = NULL;
	}
	if (memory_shuttle->origin_zero)
	{
		free(memory_shuttle->origin_zero);
		memory_shuttle->origin_zero = NULL;
	}	
}
/*
typedef struct s_mem
{
	t_coord		*r_origin_m; //ray modifie par matrice a recalculer pour chaque objet
	t_coord		*r_dir_m;
	

	// tout ca modifie avec calcul intersection
	// distance et obj type pourrait etre dans pix. 
	float		t1;// distance de l intersection 
	float		t2; // distance de l intersection 2
	int			t_count; // nombre d intersection. Pas vraiment utilise sauf pour le caps des cylindres
	float		closestt;
	
	int			obj_a;
	int			obj_b;

	t_coord		*v_sph_camera;

	/////// DEUXIEME PARTIE
	t_coord *r_ray_relf_origin;// pas encore utilise
	t_coord *r_ray_relf_dir;// pas encore utilise
	t_coord	*r_next_ray_origin;
	t_coord *r_next_ray_dir;
	// pour calcul lumiere
	// A VOIR DANS UN DEUXIEME TEMPS CE QU ON PEUT SIMPLIFIER
	t_coord	*origin_zero; // coord (0,0,0) ON PEUT COORS OBJ [0][0] besoin dans intersect sphere
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
	//bonus
	bool		is_avaible; //or mutex???
} t_mem;*/
