/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:57:50 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/15 17:11:37 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	nb;
	int				minus;
	int				count;

	minus = 0;
	count = 0;
	nb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		minus = 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str++ - '0');
		if (++count >= 20 || (nb > 9223372036854775807 && minus == 1))
			return (0);
		if (nb > 9223372036854775807)
			return (-1);
	}
	if (minus == 1)
		return ((int)-nb);
	return ((int)nb);
}
