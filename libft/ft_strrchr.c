/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 19:50:11 by opakhovs          #+#    #+#             */
/*   Updated: 2017/10/26 19:50:12 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	if (*s == c)
		count++;
	if (count != 0)
	{
		while (*s != c)
			s--;
		return ((char *)s);
	}
	return (0);
}
