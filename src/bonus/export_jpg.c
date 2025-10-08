/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_jpg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syl <syl@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:50:06 by syl               #+#    #+#             */
/*   Updated: 2025/10/08 17:37:31 by syl              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

/*
void	export_jpg(t_pix ***pix, t_scene *scene)
{
	int		x;
	int		y;

	//creer fichier
	//en tete
	//enregistrer dedans
	x = 0;
	while (x < WND_WIDTH)
	{
		y = 0;
		while (y < WND_HEIGHT)
		{
			color_float_to_int(pix[x][y]->color);
			//normalement ils le sont déjà
			y++;
		}
		x++;
	}
	//fermer image
}*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


//pas fait par moi
// --- Structures BMP standard ---
#pragma pack(push, 1)
typedef struct s_bmp_header
{
	uint16_t	type;
	uint32_t	size;
	uint16_t	reserved1;
	uint16_t	reserved2;
	uint32_t	offset;
}	t_bmp_header;

typedef struct s_bmp_info_header
{
	uint32_t	size;
	int32_t		width;
	int32_t		height;
	uint16_t	planes;
	uint16_t	bits_per_pixel;
	uint32_t	compression;
	uint32_t	image_size;
	int32_t		x_pixels_per_meter;
	int32_t		y_pixels_per_meter;
	uint32_t	colors_used;
	uint32_t	important_colors;
}	t_bmp_info_header;
#pragma pack(pop)

static void	init_bmp_headers(t_bmp_header *h, t_bmp_info_header *i)
{
	int	row_size;
	int	padding;

	row_size = WND_WIDTH * 3;
	padding = (4 - (row_size % 4)) % 4;
	h->type = 0x4D42;
	h->size = sizeof(*h) + sizeof(*i)
		+ (row_size + padding) * WND_HEIGHT;
	h->reserved1 = 0;
	h->reserved2 = 0;
	h->offset = sizeof(*h) + sizeof(*i);
	i->size = sizeof(*i);
	i->width = WND_WIDTH;
	i->height = -WND_HEIGHT;
	i->planes = 1;
	i->bits_per_pixel = 24;
	i->compression = 0;
	i->image_size = (row_size + padding) * WND_HEIGHT;
	i->x_pixels_per_meter = 5906;
	i->y_pixels_per_meter = 5906;
	i->colors_used = 0;
	i->important_colors = 0;
}

static void	write_pixels(FILE *file, t_pix ***pix)
{
	int				x;
	int				y;
	int				padding;
	unsigned char	pad[3];

	pad[0] = 0;
	pad[1] = 0;
	pad[2] = 0;
	padding = (4 - ((WND_WIDTH * 3) % 4)) % 4;
	y = 0;
	while (y < WND_HEIGHT)
	{
		x = 0;
		while (x < WND_WIDTH)
		{
			unsigned char	r;
			unsigned char	g;
			unsigned char	b;

			b = (unsigned char)(pix[x][y]->color->b * 255.0);
			g = (unsigned char)(pix[x][y]->color->g * 255.0);
			r = (unsigned char)(pix[x][y]->color->r * 255.0);
			fwrite(&b, 1, 1, file);
			fwrite(&g, 1, 1, file);
			fwrite(&r, 1, 1, file);
			x++;
		}
		fwrite(pad, 1, padding, file);
		y++;
	}
}

void	export_bmp(t_pix ***pix, const char *filename)
{
	FILE				*file;
	t_bmp_header		header;
	t_bmp_info_header	info;

	file = fopen(filename, "wb");
	if (!file)
	{
		perror("fopen");
		return ;
	}
	init_bmp_headers(&header, &info);
	fwrite(&header, sizeof(header), 1, file);
	fwrite(&info, sizeof(info), 1, file);
	write_pixels(file, pix);
	fclose(file);
	printf("Image BMP exportée : %s\n", filename);
}


/* fonctionne =)
void	export_bmp(t_pix ***pix, const char *filename)
{
	FILE				*file;
	t_bmp_header		header;
	t_bmp_info_header	info;
	int					x, y;
	unsigned char		padding[3] = {0, 0, 0};
	int					row_size;
	int					padding_size;

	file = fopen(filename, "wb");
	if (!file)
	{
		perror("fopen");
		return;
	}
	// --- Calcul du padding ---
	row_size = WND_WIDTH * 3;
	padding_size = (4 - (row_size % 4)) % 4; // lignes multiples de 4 bytes

	// --- Remplir les headers ---
	header.type = 0x4D42; // "BM"
	header.size = sizeof(header) + sizeof(info) + (row_size + padding_size) * WND_HEIGHT;
	header.reserved1 = 0;
	header.reserved2 = 0;
	header.offset = sizeof(header) + sizeof(info);

	info.size = sizeof(info);
	info.width = WND_WIDTH;
	info.height = -WND_HEIGHT; // image stockée "top-down"
	info.planes = 1;
	info.bits_per_pixel = 24;
	info.compression = 0;
	info.image_size = (row_size + padding_size) * WND_HEIGHT;
	info.x_pixels_per_meter = 2835; // ~72 DPI
	info.y_pixels_per_meter = 2835;
	info.colors_used = 0;
	info.important_colors = 0;

	// --- Écrire headers ---
	fwrite(&header, sizeof(header), 1, file);
	fwrite(&info, sizeof(info), 1, file);

	// --- Écrire pixels (BGR, ligne par ligne) ---
	for (y = 0; y < WND_HEIGHT; y++)
	{
		for (x = 0; x < WND_WIDTH; x++)
		{
			unsigned char b = (unsigned char)(pix[x][y]->color->b * 255.0);
			unsigned char g = (unsigned char)(pix[x][y]->color->g * 255.0);
			unsigned char r = (unsigned char)(pix[x][y]->color->r * 255.0);
			fwrite(&b, 1, 1, file);
			fwrite(&g, 1, 1, file);
			fwrite(&r, 1, 1, file);
		}
		fwrite(padding, 1, padding_size, file);
	}

	fclose(file);
	printf("✅ Image BMP exportée : %s\n", filename);
}
*/