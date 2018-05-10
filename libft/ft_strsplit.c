/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:15:07 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/15 17:53:43 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_listdel(char **str, int word)
{
	while (!str[word] && word >= 0)
		word--;
	while (str[word])
	{
		free(str[word]);
		word--;
	}
	free(str);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		word;
	char	**str;
	int		i;
	int		j;
	int		k;

	word = ft_count_words(s, c);
	k = 0;
	if (!s || !(str = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	i = 0;
	while (k < word)
	{
		j = 0;
		if (!(str[k] = ft_strnew(ft_get_lengthword(&s[i], c))))
			return (ft_listdel(str, word));
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			str[k][j++] = s[i++];
		str[k++][j] = '\0';
	}
	str[k] = 0;
	return (str);
}
