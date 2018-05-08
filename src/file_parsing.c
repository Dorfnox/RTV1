/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:44:57 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 14:29:48 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				set_triple_values(t_xyz *xyz, t_colour *c, char *line)
{
	char **values;

	if (!(line = ft_strchr(line, '{')))
		return (ft_puterror("Could not find opening \"{\" in line\n", 0));
	if (!(values = ft_strsplits(line, "{, }")))
		return (ft_puterror("Could not malloc int * for xyz values\n", 0));
	if (xyz)
	{
		xyz->x = ft_atoi(values[0]);
		xyz->y = ft_atoi(values[1]);
		xyz->z = ft_atoi(values[2]);
	}
	else if (c)
	{
		c->r = ft_atoi(values[0]);
		c->g = ft_atoi(values[1]);
		c->b = ft_atoi(values[2]);
	}
	ft_strdelfour(&values[0], &values[1], &values[2], &values[3]);
	free(values);
	return (1);
}
