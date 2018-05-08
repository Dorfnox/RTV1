/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_rotate_object_z.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 22:53:39 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/12 20:35:19 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	trig_rotate_object_pos_z(t_rt *rt)
{
	TRIG->rotate_object_pos_z = 1;
}

void	untrig_rotate_object_pos_z(t_rt *rt)
{
	TRIG->rotate_object_pos_z = 0;
}

void	trig_rotate_object_neg_z(t_rt *rt)
{
	TRIG->rotate_object_neg_z = 1;
}

void	untrig_rotate_object_neg_z(t_rt *rt)
{
	TRIG->rotate_object_neg_z = 0;
}
