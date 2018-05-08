/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:31:31 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/25 22:20:47 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_settings		*new_settings(void)
{
	t_settings	*new;

	if (!(new = (t_settings *)ft_memalloc(sizeof(t_settings))))
		return (NULL);
	return (new);
}

static t_xyz	*get_normalized_vector_array(t_settings *s)
{
	t_xyz	*nva;
	t_xyz	v;
	int		x;
	int		y;

	if (!(nva = (t_xyz *)ft_memalloc(sizeof(t_xyz) * W * H)))
		return (ft_putnull("Failed to malloc normalized vector array\n"));
	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			v = vector(PX, PY, -1);
			v = vector_diff(&v, &s->camera);
			normalize_vector(&v);
			nva[XY] = v;
		}
	}
	return (nva);
}

static void		even_more_settings(t_rt *rt, t_settings *s)
{
	t_obj	*tmp;

	tmp = rt->obj;
	while (tmp)
	{
		tmp = tmp->next;
		s->num_objs++;
	}
	s->fov = 90;
	s->max_ray_depth = 1;
	s->max_draw_dist = 1000;
	s->shadow_bias = 0.001;
	s->shortcut_to_object_currently_being_edited = OBJT;
	s->aspect_ratio = (double)W / (double)H;
	s->normalized_vector_ray = get_normalized_vector_array(s);
	s->num_of_threads = 8;
	s->translate_speed = 0.1;
	s->rotate_speed = 5;
	s->raytrace_func = &raytrace;
}

static void		more_settings(t_settings *new, int fd, char **l)
{
	if (EQU("camera", *l))
	{
		while (ft_gnl(fd, l) > 0 && !(EQU("}", *l)))
			if (STR(*l, "position"))
				set_triple_values(&new->camera, NULL, *l);
	}
}

t_settings		*get_settings(t_rt *rt, char *file)
{
	t_settings	*new;
	char		*line;
	int			fd;

	if (!(new = new_settings()))
		return (ft_putnull("Failed to malloc for new settings\n"));
	if (file)
	{
		if ((fd = open(file, O_RDONLY)) == -1)
			return (ft_putnull("Open failed for given filename in settings\b"));
		while (ft_gnl(fd, &line) > 0)
			more_settings(new, fd, &line);
		close(fd);
	}
	even_more_settings(rt, new);
	return (new);
}
