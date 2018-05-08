/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_translate_object_x.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:53:25 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/12 21:30:25 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	trig_translate_object_pos_x(t_rt *rt)
{
	TRIG->translate_object_pos_x = 1;
}

void	trig_translate_object_neg_x(t_rt *rt)
{
	TRIG->translate_object_neg_x = 1;
}

void	untrig_translate_object_pos_x(t_rt *rt)
{
	TRIG->translate_object_pos_x = 0;
}

void	untrig_translate_object_neg_x(t_rt *rt)
{
	TRIG->translate_object_neg_x = 0;
}
