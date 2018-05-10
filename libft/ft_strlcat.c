/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:04:51 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/15 17:36:29 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	dlen;

	dlen = ft_strlen(dst);
	len = ft_strlen(src);
	i = 0;
	if (dlen + 1 > dstsize)
		return (len + dstsize);
	if (dlen + 1 < dstsize)
	{
		while (i < len && dlen + i < dstsize - 1)
		{
			dst[dlen + i] = src[i];
			i++;
		}
		dst[dlen + i] = '\0';
	}
	return (dlen + len);
}
