/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:36:43 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/01 14:36:45 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	char	*str;

	lens1 = 0;
	lens2 = 0;
	if (!s1 || !s2)
		return (NULL);
	i = -1;
	while (s1[lens1])
		lens1++;
	while (s2[lens2])
		lens2++;
	str = ft_memalloc(lens1 + lens2);
	if (!str)
		return (NULL);
	while (++i < lens1)
		str[i] = s1[i];
	i = -1;
	while (lens1 + ++i < lens1 + lens2)
		str[lens1 + i] = s2[i];
	str[lens1 + i] = '\0';
	return (str);
}
