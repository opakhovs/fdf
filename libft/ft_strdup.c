/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:21:05 by opakhovs          #+#    #+#             */
/*   Updated: 2017/10/25 19:15:25 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*newstr;
	int		count;
	int		i;

	count = 0;
	while (src[count] != '\0')
		count++;
	i = -1;
	if (!(newstr = ft_memalloc((count + 1))))
		return (NULL);
	while (++i < count)
		newstr[i] = src[i];
	newstr[count] = '\0';
	return (newstr);
}
