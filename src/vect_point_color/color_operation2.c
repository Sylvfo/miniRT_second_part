/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:45:49 by syl               #+#    #+#             */
/*   Updated: 2025/06/02 10:26:19 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

// pour moduler ou appliquer un couleur de lumiere
t_color	multipling_color(t_color c_1, t_color c_2)
{
	t_color result;

	result.r = c_1.r * c_2.r;
	result.g = c_1.g * c_2.g;
	result.b = c_1.b * c_2.b;
	result.rgb = 0;
	return (result);
}

t_color copy_color(t_color src)
{
	t_color new;

	new.r = src.r;
	new.g = src.g;
	new.b = src.b;
	new.rgb = src.rgb;
	return (new);
}

// pour additionner deux couleurs
t_color	add_color(t_color c_1, t_color c_2)
{
	t_color result;

	result.r = c_1.r + c_2.r;
	result.g = c_1.g + c_2.g;
	result.b = c_1.b + c_2.b;
	result.rgb = 0;
	return (result);
}