/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 23:09:48 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/12 11:12:26 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_xy	solve_quadratic(double a, double b, double c)
{
	t_xy	root;
	double	determinant;
	double	sqroot;

	determinant = (b * b) - (4 * a * c);
	if (determinant > 0)
	{
		sqroot = sqrt(determinant);
		root.x = (-b + sqroot) / (2 * a);
		root.y = (-b - sqroot) / (2 * a);
	}
	else if (determinant == 0)
	{
		root.x = -b / (2 * a);
		root.y = root.x;
	}
	else
	{
		root.x = 0;
		root.y = 0;
	}
	return (root);
}

double	solve_pythagoras(t_xyz *start, t_xyz *finish)
{
	return (sqrt(
				((start->x - finish->x) * (start->x - finish->x)) +
				((start->y - finish->y) * (start->y - finish->y)) +
				((start->z - finish->z) * (start->z - finish->z))));
}
