/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 20:40:31 by opakhovs          #+#    #+#             */
/*   Updated: 2017/10/26 20:40:32 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*find;
	char	*temp;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		temp = (char *)haystack;
		find = (char *)needle;
		while (*temp == *find && *temp && *find)
		{
			temp++;
			find++;
			if (!*find)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
