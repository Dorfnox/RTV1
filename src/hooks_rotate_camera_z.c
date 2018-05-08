/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotate_camera_z.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:53:39 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/28 17:37:24 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	trig_rotate_camera_pos_z(t_rt *rt)
{
	TRIG->rotate_camera_pos_z = 1;
}

void	untrig_rotate_camera_pos_z(t_rt *rt)
{
	TRIG->rotate_camera_pos_z = 0;
}

void	trig_rotate_camera_neg_z(t_rt *rt)
{
	TRIG->rotate_camera_neg_z = 1;
}

void	untrig_rotate_camera_neg_z(t_rt *rt)
{
	TRIG->rotate_camera_neg_z = 0;
}
