/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 16:21:20 by opakhovs          #+#    #+#             */
/*   Updated: 2017/10/25 19:05:19 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	unsigned	char	*news1;
	unsigned	char	*news2;
	int					i;

	i = 0;
	news1 = (unsigned char *)s1;
	news2 = (unsigned char *)s2;
	while (news1[i] && news2[i])
	{
		if (news1[i] != news2[i])
			return (news1[i] - news2[i]);
		i++;
	}
	if (news1[i])
		return (news1[i]);
	if (news2[i])
		return (-news2[i]);
	return (0);
}
