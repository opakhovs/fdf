/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:40:15 by opakhovs          #+#    #+#             */
/*   Updated: 2017/10/26 20:40:17 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*to_find;
	char	*temp;
	int		i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		i = len;
		temp = (char *)haystack;
		to_find = (char *)needle;
		while (*temp == *to_find && i > 0 && *to_find && *temp)
		{
			temp++;
			to_find++;
			i--;
		}
		if (!*to_find)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
