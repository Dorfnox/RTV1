/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_stuff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 18:38:31 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 21:46:13 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		cylinder_intersect(t_obj *o, t_xyz *ro, t_xyz *rv)
{
	t_cylinder_intersect	c;
	t_xy					root;
	double					*result;

	c.dot = dot_product(rv, &o->vector);
	c.tmp = vector(c.dot * o->vector.x,
			c.dot * o->vector.y,
			c.dot * o->vector.z);
	c.a_temp = vector_diff(rv, &c.tmp);
	c.a = dot_product(&c.a_temp, &c.a_temp);
	c.delta_p = vector_diff(ro, &o->pos);
	c.dot = dot_product(&c.delta_p, &o->vector);
	c.tmp.x = c.dot * o->vector.x;
	c.tmp.y = c.dot * o->vector.y;
	c.tmp.z = c.dot * o->vector.z;
	c.b_temp = vector_diff(&c.delta_p, &c.tmp);
	c.b = 2 * (dot_product(&c.a_temp, &c.b_temp));
	c.c = dot_product(&c.b_temp, &c.b_temp) - (o->radius * o->radius);
	root = solve_quadratic(c.a, c.b, c.c);
	result = NULL;
	if (root.x > 0.0001 && root.x < root.y)
		result = &root.x;
	if (root.y > 0.0001 && root.y < root.x)
		result = &root.y;
	return (result ? *result : 0);
}

t_xyz		cylinder_normal(t_obj *o, t_xyz *hitpos)
{
	t_xyz	temp;
	double	dist;

	temp = vector_diff(hitpos, &o->pos);
	normalize_vector(&temp);
	dist = dot_product(&temp, &o->vector);
	dist *= solve_pythagoras(hitpos, &o->pos);
	temp.x = o->pos.x + (o->vector.x * dist);
	temp.y = o->pos.y + (o->vector.y * dist);
	temp.z = o->pos.z + (o->vector.z * dist);
	temp = vector_diff(hitpos, &temp);
	normalize_vector(&temp);
	return (temp);
}

void		set_cylinder_reqs(t_obj *o)
{
	if (o->type == CYLINDER)
	{
		if (!o->vector.x && !o->vector.y && !o->vector.z)
			o->vector.y = 1;
		if (o->rot.x != 0)
			rotate_vector_x(&o->vector, (o->rot.x * M_PI / 180));
		if (o->rot.y != 0)
			rotate_vector_y(&o->vector, (o->rot.y * M_PI / 180));
		if (o->rot.z != 0)
			rotate_vector_z(&o->vector, (o->rot.z * M_PI / 180));
		if (!o->radius)
			o->radius = 1;
		if (o->albedo <= 0)
			o->albedo = 1;
		normalize_vector(&o->vector);
	}
}
