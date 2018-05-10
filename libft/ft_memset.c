/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:40:20 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/15 18:20:07 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				count_len;
	unsigned char	*to_ret;

	count_len = 0;
	to_ret = b;
	while (len > 0)
	{
		to_ret[count_len] = c;
		count_len++;
		len--;
	}
	return (to_ret);
}
