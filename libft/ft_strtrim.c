/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:44:31 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/05 16:31:31 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		st;
	char	*str;
	int		en;
	int		k;

	st = 0;
	k = 0;
	if (!s)
		return (NULL);
	en = (ft_strlen(s) - 1);
	while ((s[st] == ' ' || s[st] == '\n' || s[st] == '\t') && s[st] != '\0')
		st++;
	while ((s[en] == ' ' || s[en] == '\n' || s[en] == '\t') && s[en] != '\0')
		en--;
	if (st == (int)ft_strlen(s) && en == -1 && (str = ft_memalloc(1)))
	{
		*str = '\0';
		return (str);
	}
	if (!(str = ft_memalloc(en - st + 2)))
		return (NULL);
	while (st <= en)
		*(str + k++) = *(s + st++);
	str[k] = '\0';
	return (str);
}
