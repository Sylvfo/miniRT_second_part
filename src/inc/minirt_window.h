/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_window.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:26:47 by syl               #+#    #+#             */
/*   Updated: 2025/10/07 20:09:57 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_WINDOW_H
# define MINIRT_WINDOW_H

# include "minirt_data_struct.h"

int		ft_exit(t_scene *scene);
int		ft_keys(int keycode, t_scene *scene);
void	my_mlx_pixel_put(t_image *ima, int x, int y, int color);
void	pix_to_window(t_pix ***pix, t_scene *scene);

//event_hooks.c
void	image_hooks(t_scene *scene);
//void	image_hooks_bonus(t_scene *scene);
void	image_hooks_bonus(t_glob **data);

void	handle_img(t_scene *scene, t_obj *obj, char *path);
#endif