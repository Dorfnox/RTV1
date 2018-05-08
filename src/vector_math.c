/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 15:36:08 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/19 13:35:07 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_xyz	vector(double x, double y, double z)
{
	t_xyz	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

double	dot_product(t_xyz *a, t_xyz *b)
{
	return ((a->x * b->x) + (a->y * b->y) + (a->z * b->z));
}

t_xyz	vector_diff(t_xyz *a, t_xyz *b)
{
	t_xyz	new_xyz;

	new_xyz.x = a->x - b->x;
	new_xyz.y = a->y - b->y;
	new_xyz.z = a->z - b->z;
	return (new_xyz);
}

double	vector_dist(t_xyz *v)
{
	return (sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

void	normalize_vector(t_xyz *v)
{
	double	vector_length_otherwise_known_as_magnitude;

	vector_length_otherwise_known_as_magnitude = vector_dist(v);
	v->x = v->x / vector_length_otherwise_known_as_magnitude;
	v->y = v->y / vector_length_otherwise_known_as_magnitude;
	v->z = v->z / vector_length_otherwise_known_as_magnitude;
}
