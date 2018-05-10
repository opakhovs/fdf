/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:54:52 by opakhovs          #+#    #+#             */
/*   Updated: 2017/10/26 20:54:53 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned	char	*news1;
	unsigned	char	*news2;
	size_t				i;

	i = 0;
	news1 = (unsigned char *)s1;
	news2 = (unsigned char *)s2;
	while (news1[i] && news2[i] && i < n)
	{
		if (news1[i] != news2[i])
			return (news1[i] - news2[i]);
		i++;
	}
	if (i == n)
		return (0);
	if (news1[i])
		return (news1[i]);
	if (news2[i])
		return (-news2[i]);
	return (0);
}
