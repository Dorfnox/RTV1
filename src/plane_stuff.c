/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 15:36:08 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 20:53:01 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			plane_intersect(t_obj *o, t_xyz *ro, t_xyz *rv)
{
	double		denom;
	t_xyz		subtract;
	double		dist;

	denom = -dot_product(&o->vector, rv);
	if (ABS(denom) < 0.0001)
		return (0);
	subtract = vector_diff(ro, &o->pos);
	dist = dot_product(&subtract, &o->vector) / denom;
	return (dist > 0 ? dist : 0);
}

t_xyz			plane_normal(t_obj *o, t_xyz *hitpos)
{
	(void)hitpos;
	return (o->vector);
}

void			set_plane_reqs(t_obj *o)
{
	if (o->type == PLANE)
	{
		if (o->vector.x == 0 && o->vector.y == 0 &&
				o->vector.z == 0)
			o->vector.y = 1;
		normalize_vector(&o->vector);
		if (o->rot.x != 0)
			rotate_vector_x(&o->vector, (o->rot.x * M_PI / 180));
		if (o->rot.y != 0)
			rotate_vector_y(&o->vector, (o->rot.y * M_PI / 180));
		if (o->rot.z != 0)
			rotate_vector_z(&o->vector, (o->rot.z * M_PI / 180));
		if (o->albedo <= 0)
			o->albedo = 1;
	}
}
