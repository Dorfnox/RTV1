/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 17:22:24 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/06 17:12:40 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfsub(char **s, unsigned int start, size_t len)
{
	char	*newstr;
	size_t	i;

	if (!*s)
		return (NULL);
	i = 0;
	if (!(newstr = ft_strnew(len)))
		return (NULL);
	while (s[0][start] && i < len)
		newstr[i++] = s[0][start++];
	newstr[i] = '\0';
	ft_strdel(s);
	return (newstr);
}
