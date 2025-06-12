/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:02:20 by cmegret           #+#    #+#             */
/*   Updated: 2025/06/12 14:59:52 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_ALL_H
# define FREE_ALL_H

# include "minirt_data_struct.h"

int		free_arg(char **str);
int		error_line(char **params, int line, int col);
int		number_param_error(char **params, int ligne);
int		error_system(void);
bool	error_missing(t_doublons num, int nb_light);

#endif