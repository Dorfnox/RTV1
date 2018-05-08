/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotate_camera_y.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:53:39 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/28 17:37:06 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	trig_rotate_camera_pos_y(t_rt *rt)
{
	TRIG->rotate_camera_pos_y = 1;
}

void	untrig_rotate_camera_pos_y(t_rt *rt)
{
	TRIG->rotate_camera_pos_y = 0;
}

void	trig_rotate_camera_neg_y(t_rt *rt)
{
	TRIG->rotate_camera_neg_y = 1;
}

void	untrig_rotate_camera_neg_y(t_rt *rt)
{
	TRIG->rotate_camera_neg_y = 0;
}
