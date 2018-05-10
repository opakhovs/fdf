/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:11:50 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/15 17:15:37 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		count;
	char	*str;
	long	try;
	int		i;

	count = ft_getcountnum(n);
	i = 0;
	if (n < 0)
		count++;
	if (!(str = ft_strnew(count)))
		return (NULL);
	try = n;
	if (n < 0)
		try *= -1;
	str[--count] = (try % 10 + '0');
	while ((try /= 10) > 9)
		str[--count] = (try % 10 + '0');
	str[--count] = (try % 10 + '0');
	if (n < 0)
		str[0] = ('-');
	return (str);
}
