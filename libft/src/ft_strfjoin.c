/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:46:57 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/07 20:53:56 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char **s1, const char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(newstr = ft_strnew(ft_strlen((char *)*s1) + ft_strlen((char *)s2))))
		return (NULL);
	while ((*s1)[++i])
		newstr[i] = (*s1)[i];
	while (s2[j])
		newstr[i++] = s2[j++];
	ft_strdel(s1);
	return (newstr);
}
