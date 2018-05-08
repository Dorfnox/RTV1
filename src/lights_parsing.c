/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 19:31:31 by bpierce           #+#    #+#             */
/*   Updated: 2017/10/16 14:25:52 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_light			*new_light(void)
{
	t_light	*new;

	if (!(new = (t_light *)ft_memalloc(sizeof(t_light))))
		return (NULL);
	new->next = NULL;
	return (new);
}

static int		set_light_info(int fd, char **l, t_light *tmp)
{
	while (ft_gnl(fd, l) > 0 && !(EQU("}", *l)))
	{
		if (STR(*l, "position"))
			if (!(set_triple_values(&tmp->pos, NULL, *l)))
				return (ft_puterror("Can't set position vals for light\n", 0));
		if (STR(*l, "color"))
			if (!(set_triple_values(NULL, &tmp->colour, *l)))
				return (ft_puterror("Can't set colour vals for light\n", 0));
		if (STR(*l, "intensity"))
			tmp->intensity = ft_atoi(ft_strchr(*l, '=') + 1);
	}
	tmp->falloff = LINEAR_FALLOFF;
	return (1);
}

t_light			*get_light_list(char *file)
{
	int			fd;
	char		*line;
	t_light		*head;
	t_light		*tmp;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_putnull("Open failed for given filename in light\b"));
	head = NULL;
	while (ft_gnl(fd, &line) > 0)
	{
		if (EQU("light", line))
		{
			tmp = new_light();
			if (!(set_light_info(fd, &line, tmp)))
				return (ft_putnull("Failed to really set light info\n"));
			tmp->next = head;
			head = tmp;
		}
	}
	return ((close(fd) != -1) ? head : ft_putnull("Failed to close fd"));
}
