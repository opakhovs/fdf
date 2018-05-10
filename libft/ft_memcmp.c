/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:37:28 by opakhovs          #+#    #+#             */
/*   Updated: 2017/10/26 17:37:30 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned	char	*news1;
	const unsigned	char	*news2;
	int						i;

	i = 0;
	news1 = s1;
	news2 = s2;
	while (n > 0)
	{
		if (*news1 != *news2)
		{
			return (*news1 - *news2);
		}
		news1++;
		news2++;
		n--;
	}
	return (0);
}
