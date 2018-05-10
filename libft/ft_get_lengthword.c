/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lengthword.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:49:16 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/07 19:51:07 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_lengthword(char const *s, char c)
{
	int		len;

	len = 0;
	if (!s)
		return (0);
	while (*s == c && *s != '\0')
		s++;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
