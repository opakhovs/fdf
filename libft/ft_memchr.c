/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:12:41 by opakhovs          #+#    #+#             */
/*   Updated: 2017/10/26 17:12:54 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	unsigned	char	*news;
	unsigned	char	newc;

	i = n;
	news = (unsigned char *)s;
	newc = (unsigned char)c;
	while (i > 0)
	{
		if (*news == newc)
		{
			return (news);
		}
		news++;
		i--;
	}
	return (0);
}
