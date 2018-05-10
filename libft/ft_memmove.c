/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:55:28 by opakhovs          #+#    #+#             */
/*   Updated: 2017/10/26 16:55:29 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*newdst;
	const char	*newsrc;

	i = -1;
	newdst = (char *)dst;
	newsrc = (char *)src;
	if (newsrc < newdst)
		while ((int)(--len) >= 0)
			*(newdst + len) = *(newsrc + len);
	else
		while (++i < len)
			*(newdst + i) = *(newsrc + i);
	return (newdst);
}
