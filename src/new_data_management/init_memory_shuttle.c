/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory_shuttle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:38:27 by syl               #+#    #+#             */
/*   Updated: 2025/05/28 10:09:44 by syl              ###   ########.fr       */
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
//	memory_shuttle->t1 = 0.0;
//	memory_shuttle->t2 = 0.0;
	memory_shuttle->t_count = 0.0;
	memory_shuttle->closestt = INT_MAX;
	memory_shuttle->obj_a = NONE;
	memory_shuttle->obj_b = 0;
	memory_shuttle->origin_zero = NULL;
///part 2
	memory_shuttle->object_normal = NULL;
	memory_shuttle->p_space = NULL;
	memory_shuttle->p_touch = NULL;
	memory_shuttle->p_space = NULL;
	memory_shuttle->v_eye = NULL;
	memory_shuttle->v_norm_parral = NULL;
	memory_shuttle->v_light_to_point = NULL;
	memory_shuttle->v_sphere_to_point = NULL;
	memory_shuttle->v_point_to_light = NULL; 
	memory_shuttle->reflect_dir = NULL;
	memory_shuttle->scalar = NULL;
	memory_shuttle->view_dir = NULL;
	//matrix
	memory_shuttle->obj_inv = NULL;
	memory_shuttle->transp_inv = NULL;
}

bool init_shuttle_values(t_mem *memory_shuttle)
{
	memory_shuttle->r_origin_m = create_point(0, 0, 0);
	if (!memory_shuttle->r_origin_m)
		return (false);
	memory_shuttle->r_dir_m = create_vector(0, 0, 0);
	if (!memory_shuttle->r_dir_m)
		return (false);
	memory_shuttle->r_dir_closest_obj = create_vector(0, 0, 0);
	if (!memory_shuttle->r_dir_closest_obj)
		return (false);
	memory_shuttle->r_origin_closest_obj = create_point(0, 0, 0);
	if (!memory_shuttle->r_origin_closest_obj)
		return (false);
	memory_shuttle->v_sph_camera = create_vector(0, 0, 0);
	if (!memory_shuttle->v_sph_camera)
		return (false);
	memory_shuttle->origin_zero = create_point(0, 0, 0);
	if (!memory_shuttle->origin_zero)
		return (false);
	memory_shuttle->object_normal = create_vector(0, 0, 0);
	if (!memory_shuttle->object_normal)
		return (false);
	memory_shuttle->p_space = create_point(0, 0, 0);
	if (!memory_shuttle->p_space)
		return (false);
	memory_shuttle->p_touch = create_point(0, 0, 0);
	if (!memory_shuttle->p_touch)
		return (false);
	memory_shuttle->v_eye = create_vector(0, 0, 0);
	if (!memory_shuttle->v_eye)
		return (false);
	memory_shuttle->v_norm_parral = create_vector(0, 0, 0);
	if (!memory_shuttle->v_norm_parral)
		return (false);
	memory_shuttle->v_light_to_point = create_vector(0, 0, 0);
	if (!memory_shuttle->v_light_to_point)
		return (false);
	memory_shuttle->v_sphere_to_point = create_vector(0, 0, 0);
	if (!memory_shuttle->v_sphere_to_point)
		return (false);
	memory_shuttle->v_point_to_light = create_vector(0, 0, 0);
	if (!memory_shuttle->v_point_to_light)
		return (false);
	memory_shuttle->reflect_dir = create_vector(0, 0, 0);
	if (!memory_shuttle->reflect_dir)
		return (false);
	memory_shuttle->scalar = create_vector(0, 0, 0);
	if (!memory_shuttle->scalar)
		return (false);
	memory_shuttle->view_dir = create_vector(0, 0, 0);
	if (!memory_shuttle->view_dir)
		return (false);
	memory_shuttle->obj_inv = create_indentity_matrix_44();
	if (!memory_shuttle->obj_inv)
		return (false);
	memory_shuttle->transp_inv = create_indentity_matrix_44();
	if (!memory_shuttle->transp_inv)
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
/*	if (memory_shuttle->r_dir_closest_obj)
	{
		free(memory_shuttle->r_dir_closest_obj);
		memory_shuttle->r_dir_closest_obj = NULL;
	}*/
	if (memory_shuttle->r_origin_closest_obj)
	{
		free(memory_shuttle->r_origin_closest_obj);
		memory_shuttle->r_origin_closest_obj = NULL;
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
	if (memory_shuttle->object_normal)
	{
		free(memory_shuttle->object_normal);
		memory_shuttle->object_normal = NULL;
	}
	if (memory_shuttle->p_space)
	{
		free(memory_shuttle->p_space);
		memory_shuttle->p_space = NULL;
	}
	if (memory_shuttle->p_touch)
	{
		free(memory_shuttle->p_touch);
		memory_shuttle->p_touch = NULL;
	}
		if (memory_shuttle->v_eye)
	{
		free(memory_shuttle->v_eye);
		memory_shuttle->v_eye = NULL;
	}
	if (memory_shuttle->v_norm_parral)
	{
		free(memory_shuttle->v_norm_parral);
		memory_shuttle->v_norm_parral = NULL;
	}
	if (memory_shuttle->v_light_to_point)
	{
		free(memory_shuttle->v_light_to_point);
		memory_shuttle->v_light_to_point = NULL;
	}
	if (memory_shuttle->v_sphere_to_point)
	{
		free(memory_shuttle->v_sphere_to_point);
		memory_shuttle->v_sphere_to_point = NULL;
	}
	if (memory_shuttle->v_point_to_light)
	{
		free(memory_shuttle->v_point_to_light);
		memory_shuttle->v_point_to_light = NULL;
	}

	if (memory_shuttle->reflect_dir)
	{
		free(memory_shuttle->reflect_dir);
		memory_shuttle->reflect_dir = NULL;
	}
	if (memory_shuttle->scalar)
	{
		free(memory_shuttle->scalar);
		memory_shuttle->scalar = NULL;
	}
	if (memory_shuttle->view_dir)
	{
		free(memory_shuttle->view_dir);
		memory_shuttle->view_dir = NULL;
	}
	if (memory_shuttle->obj_inv)
	{
		free(memory_shuttle->obj_inv);
		memory_shuttle->obj_inv = NULL;
	}
	if (memory_shuttle->transp_inv)
	{
		free(memory_shuttle->transp_inv);
		memory_shuttle->transp_inv = NULL;
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
