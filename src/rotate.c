/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:29:03 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/12 21:58:34 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotate_vector_x(t_xyz *n_vector, double radians)
{
	double	y_coor;

	y_coor = n_vector->y;
	n_vector->y = (cos(radians) * y_coor) + (sin(radians) * n_vector->z);
	n_vector->z = (-sin(radians) * y_coor) + (cos(radians) * n_vector->z);
}

void	rotate_vector_y(t_xyz *n_vector, double radians)
{
	double	x_coor;

	x_coor = n_vector->x;
	n_vector->x = (cos(radians) * x_coor) + (-sin(radians) * n_vector->z);
	n_vector->z = (sin(radians) * x_coor) + (cos(radians) * n_vector->z);
}

void	rotate_vector_z(t_xyz *n_vector, double radians)
{
	double	x_coor;

	x_coor = n_vector->x;
	n_vector->x = (cos(radians) * x_coor) + (sin(radians) * n_vector->y);
	n_vector->y = (-sin(radians) * x_coor) + (cos(radians) * n_vector->y);
}
