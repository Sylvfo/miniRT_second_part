/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:13:35 by cmegret           #+#    #+#             */
/*   Updated: 2025/05/25 19:29:26 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	save_triangle(char *str, t_obj **obj, int *pos)
{
	char	**params;
	int		i;

	i = 0;
	params = ft_split(str, ' ');
	if (!params)
		return (error_system());
	while (obj[i]->type == TRIANGLE)
	{
		i++;
	}
	obj[i]->type = TRIANGLE;
	if (!save_coordonnee(params[1], obj[i]->tr_p1) || \
!save_coordonnee(params[2], obj[i]->tr_p2) || \
!save_coordonnee(params[3], obj[i]->tr_p3) || \
!save_color(params[4], obj[i]->color, &obj[i]->color2))
	{
		free_arg(params);
		return (0);
	}
	free_arg(params);
	substraction_p_to_v_na(obj[i]->tr_e1, obj[i]->tr_p2, obj[i]->tr_p1);
	substraction_p_to_v_na(obj[i]->tr_e2, obj[i]->tr_p3, obj[i]->tr_p1);
	cross_product_na(obj[i]->normal, obj[i]->tr_e2, obj[i]->tr_e1);
	normalize_vector_na(obj[i]->normal);
	*pos = i;
	return (1);
}
