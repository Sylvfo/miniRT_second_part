/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_jpg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:50:06 by syl               #+#    #+#             */
/*   Updated: 2026/01/21 16:54:07 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../inc/minirt_bonus.h"

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
/*
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
}*/

static void	print_pix(FILE *file, t_pix ***pix, int x, int y)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	b = (unsigned char)float_to_byte(pix[x][y]->color->b);
	g = (unsigned char)float_to_byte(pix[x][y]->color->g);
	r = (unsigned char)float_to_byte(pix[x][y]->color->r);
	fwrite(&b, 1, 1, file);
	fwrite(&g, 1, 1, file);
	fwrite(&r, 1, 1, file);
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
			print_pix(file, pix, x, y);
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
