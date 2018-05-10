/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:41:38 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/15 17:35:11 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst,
	const void *src, int c, size_t n)
{
	size_t		i;
	char		*newdst;

	i = -1;
	newdst = dst;
	while (++i < n)
	{
		*(newdst + i) = *((unsigned char *)src + i);
		if (*((unsigned char *)src + i) == (unsigned char)c)
			return (newdst + i + 1);
	}
	return (NULL);
}
