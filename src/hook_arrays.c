/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 23:15:28 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/13 17:19:39 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		protect_array(t_rt *rt)
{
	if (rt)
		return ;
}

static void	(**get_kp_array(int size))(t_rt *)
{
	int		i;
	void	(**kp)(t_rt *);

	i = 0;
	kp = (void (**)(t_rt *))ft_memalloc(sizeof(void (*)(t_rt *)) * size);
	while (i < size)
		kp[i++] = &protect_array;
	return (kp);
}

static void	(**get_kr_array(int size))(t_rt *)
{
	int		i;
	void	(**kr)(t_rt *);

	i = 0;
	kr = (void (**)(t_rt *))ft_memalloc(sizeof(void (*)(t_rt *)) * size);
	while (i < size)
		kr[i++] = &protect_array;
	return (kr);
}

void		set_arrays(t_rt *rt)
{
	rt->kp = get_kp_array(300);
	set_key_presses(rt->kp);
	rt->kr = get_kr_array(300);
	set_key_releases(rt->kr);
}
