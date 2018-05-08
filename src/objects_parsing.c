/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 21:09:51 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 14:10:10 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_obj			*new_obj(void)
{
	t_obj	*tmp;

	if (!(tmp = (t_obj *)ft_memalloc(sizeof(t_obj))))
		return (ft_putnull("failed to malloc for new obj *...\n"));
	tmp->next = NULL;
	return (tmp);
}

static int		set_type(t_obj *o, char *l)
{
	if (STR(l, "sphere") && (o->type = SPHERE))
	{
		o->intersect = &sphere_intersect;
		o->normal = &sphere_normal;
	}
	else if (STR(l, "plane") && (o->type = PLANE))
	{
		o->intersect = &plane_intersect;
		o->normal = &plane_normal;
	}
	else if (STR(l, "cylinder") && (o->type = CYLINDER))
	{
		o->intersect = &cylinder_intersect;
		o->normal = &cylinder_normal;
	}
	else if (STR(l, "cone") && (o->type = CONE))
	{
		o->intersect = &cone_intersect;
		o->normal = &cone_normal;
	}
	return (o->type);
}

static int		set_more_object_info(t_obj *o, char *l)
{
	if (STR(l, "type"))
		if (!(set_type(o, l)))
			return (ft_puterror("Object 'type' could not be id'd\n", 0));
	if (STR(l, "position"))
		if (!(set_triple_values(&o->pos, NULL, l)))
			return (ft_puterror("Couldn't set position values\n", 0));
	if (STR(l, "rotation"))
		if (!(set_triple_values(&o->rot, NULL, l)))
			return (ft_puterror("Couldn't set rotation values\n", 0));
	if (STR(l, "color"))
		if (!(set_triple_values(NULL, &o->colour, l) && (SET_HEX_COLOUR)))
			return (ft_puterror("Couldn't set colour values\n", 0));
	if (STR(l, "shine"))
		o->shine = ft_atoi(ft_strchr(l, '=') + 1);
	else if (STR(l, "brghtness"))
		o->brghtnss = ft_atoi(ft_strchr(l, '=') + 1);
	else if (STR(l, "radius"))
		o->radius = ft_atoi(ft_strchr(l, '=') + 1);
	else if (STR(l, "angle"))
		o->angle = cos(ft_atoi(ft_strchr(l, '=') + 1) * M_PI / 180);
	else if (STR(l, "width"))
		o->width = ft_atoi(ft_strchr(l, '=') + 1);
	else if (STR(l, "height"))
		o->height = ft_atoi(ft_strchr(l, '=') + 1);
	return (1);
}

static int		set_object_info(int fd, char **line, t_obj *tmp)
{
	while (ft_gnl(fd, line) > 0 && !(EQU("}", *line)))
	{
		if (STR(*line, "vector"))
			if (!(set_triple_values(&tmp->vector, NULL, *line)))
				return (ft_puterror("Couldn't set plane normal values\n", 0));
		if (!(set_more_object_info(tmp, *line)))
			return (ft_puterror("Failed to set object info\n", 0));
	}
	set_sphere_reqs(tmp);
	set_plane_reqs(tmp);
	set_cylinder_reqs(tmp);
	set_cone_reqs(tmp);
	return (1);
}

t_obj			*get_obj_list(char *file)
{
	int		fd;
	char	*line;
	t_obj	*head;
	t_obj	*tmp;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_putnull("Open failed to open given filename\n"));
	head = NULL;
	while (ft_gnl(fd, &line) > 0)
	{
		if (EQU("object", line))
		{
			tmp = new_obj();
			if (!(set_object_info(fd, &line, tmp)))
				return (ft_putnull("Failed to really set object info\n"));
			tmp->next = head;
			head = tmp;
		}
	}
	return ((close(fd) != -1) ? head : ft_putnull("Failed to close fd"));
}
