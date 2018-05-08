/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:32:41 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/13 17:20:05 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			free_stuff(t_rt *rt)
{
	mlx_destroy_window(rt->mlx, rt->win);
	free(rt);
	return (1);
}
