/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:38:31 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/28 15:27:50 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		cone_intersect(t_obj *o, t_xyz *ro, t_xyz *rv)
{
	t_cone_intersect	c;
	t_xyz				vecdiff;
	t_xy				root;
	double				*result;

	c.a_temp = dot_product(rv, &o->vector);
	c.cos2 = o->angle * o->angle;
	c.a = (c.a_temp * c.a_temp) - c.cos2;
	vecdiff = vector_diff(ro, &o->pos);
	c.b_temp = dot_product(&vecdiff, &o->vector);
	c.b = 2 * ((c.a_temp * c.b_temp) - (dot_product(rv, &vecdiff) * c.cos2));
	c.c = (c.b_temp * c.b_temp) - (dot_product(&vecdiff, &vecdiff) * c.cos2);
	root = solve_quadratic(c.a, c.b, c.c);
	result = NULL;
	if (root.x > 0.0001 && root.x < root.y)
		result = &root.x;
	if (root.y > 0.0001 && root.y < root.x)
		result = &root.y;
	return (result ? *result : 0);
}

t_xyz		cone_normal(t_obj *o, t_xyz *hitpos)
{
	double	dist;
	t_xyz	new;
	t_xyz	tmp;

	dist = solve_pythagoras(hitpos, &o->pos);
	dist /= o->angle;
	tmp = vector_diff(hitpos, &o->pos);
	if (dot_product(&tmp, &o->vector) < 0)
		dist = -dist;
	new.x = o->pos.x + (o->vector.x * dist);
	new.y = o->pos.y + (o->vector.y * dist);
	new.z = o->pos.z + (o->vector.z * dist);
	new = vector_diff(hitpos, &new);
	normalize_vector(&new);
	return (new);
}

void		set_cone_reqs(t_obj *o)
{
	if (o->type == CONE)
	{
		if (o->angle == 1)
			o->angle = cos(45 * M_PI / 180);
		if (o->vector.x == 0 && o->vector.y == 0 && o->vector.z == 0)
			o->vector.y = -1;
		if (o->rot.x != 0)
			rotate_vector_x(&o->vector, (o->rot.x * M_PI / 180));
		if (o->rot.y != 0)
			rotate_vector_y(&o->vector, (o->rot.y * M_PI / 180));
		if (o->rot.z != 0)
			rotate_vector_z(&o->vector, (o->rot.z * M_PI / 180));
		if (!o->angle)
			o->angle = cos(45 * M_PI / 180);
		if (o->albedo <= 0)
			o->albedo = 1;
		normalize_vector(&o->vector);
	}
}
