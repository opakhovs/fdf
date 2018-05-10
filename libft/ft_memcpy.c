/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:02:56 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/15 17:35:40 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*newdst;
	char		*newsrc;

	i = 0;
	newdst = (char *)dst;
	newsrc = (char *)src;
	while (i < n)
	{
		newdst[i] = newsrc[i];
		i++;
	}
	return (newdst);
}
