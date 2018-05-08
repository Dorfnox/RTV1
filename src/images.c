/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:28:14 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 22:48:28 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_image			*new_image(t_rt *rt, int width, int height)
{
	t_image		*image;

	image = (t_image *)malloc(sizeof(t_image));
	image->img = mlx_new_image(rt->mlx, width, height);
	image->pix = (int *)mlx_get_data_addr(image->img,
			&image->bpp, &image->w, &image->endian);
	image->w /= 4;
	image->h = height;
	return (image);
}

void			fill_image_with_colour(t_image *i, int c)
{
	int		x;
	int		y;

	y = -1;
	while (++y < i->h)
	{
		x = -1;
		while (++x < i->w)
			i->pix[(y * i->w) + x] = c;
	}
}

static t_image	*get_xpm_image(t_rt *rt, char *filename)
{
	t_image		*image;

	if (!(image = (t_image *)ft_memalloc(sizeof(t_image))))
		return (ft_putnull("Failed to malloc for xpm image"));
	image->img = mlx_xpm_file_to_image(rt->mlx, filename, &image->w, &image->h);
	return (image);
}

t_info_panel	*get_info_panels(t_rt *rt)
{
	t_info_panel	*i;

	if (!(i = (t_info_panel *)ft_memalloc(sizeof(t_info_panel))))
		return (ft_putnull("Failed to malloc for t_info_panel"));
	if (!(i->topleft = get_xpm_image(rt, "img/rt1.xpm")))
		return (ft_putnull("Failed to get rt1.xpm"));
	if (!(i->topright = get_xpm_image(rt, "img/rt2.xpm")))
		return (ft_putnull("Failed to get rt2.xpm"));
	if (!(i->bot = get_xpm_image(rt, "img/rt3.xpm")))
		return (ft_putnull("Failed to get rt3.xpm"));
	return (i);
}
