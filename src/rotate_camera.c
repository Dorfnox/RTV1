/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:29:03 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/28 17:11:09 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rotate_camera_x(t_xyz *nva, t_xyz *camera_pos, double radians)
{
	t_rotate_math	m;

	m.cos = cos(radians);
	m.sin = sin(radians);
	m.y = -1;
	while (++m.y < H)
	{
		m.x = -1;
		while (++m.x < W)
		{
			m.y_coor = nva[MXY].y;
			nva[MXY].y = (m.cos * m.y_coor) + (m.sin * nva[MXY].z);
			nva[MXY].z = (-m.sin * m.y_coor) + (m.cos * nva[MXY].z);
		}
	}
	m.camera.y = camera_pos->y;
	camera_pos->y = (m.cos * m.camera.y) + (m.sin * camera_pos->z);
	camera_pos->z = (-m.sin * m.camera.y) + (m.cos * camera_pos->z);
}

void	rotate_camera_y(t_xyz *nva, t_xyz *camera_pos, double radians)
{
	t_rotate_math	m;

	m.cos = cos(radians);
	m.sin = sin(radians);
	m.y = -1;
	while (++m.y < H)
	{
		m.x = -1;
		while (++m.x < W)
		{
			m.x_coor = nva[MXY].x;
			nva[MXY].x = (m.cos * m.x_coor) + (-m.sin * nva[MXY].z);
			nva[MXY].z = (m.sin * m.x_coor) + (m.cos * nva[MXY].z);
		}
	}
	m.camera.x = camera_pos->x;
	camera_pos->x = (m.cos * m.camera.x) + (-m.sin * camera_pos->z);
	camera_pos->z = (m.sin * m.camera.x) + (m.cos * camera_pos->z);
}

void	rotate_camera_z(t_xyz *nva, t_xyz *camera_pos, double radians)
{
	t_rotate_math	m;

	m.cos = cos(radians);
	m.sin = sin(radians);
	m.y = -1;
	while (++m.y < H)
	{
		m.x = -1;
		while (++m.x < W)
		{
			m.x_coor = nva[MXY].x;
			nva[MXY].x = (m.cos * m.x_coor) + (m.sin * nva[MXY].y);
			nva[MXY].y = (-m.sin * m.x_coor) + (m.cos * nva[MXY].y);
		}
	}
	m.camera.x = camera_pos->x;
	camera_pos->x = (m.cos * m.camera.x) + (m.sin * camera_pos->y);
	camera_pos->y = (-m.sin * m.camera.x) + (m.cos * camera_pos->y);
}
