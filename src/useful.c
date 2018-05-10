/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:37:21 by opakhovs          #+#    #+#             */
/*   Updated: 2018/04/02 18:37:24 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		pos(int x, int y)
{
	if (x > y)
		return (x - y);
	else
		return (y - x);
}

void	freestr(char ***res)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (*((*res) + k))
		k++;
	while (j < k)
	{
		free(*((*res) + j));
		*((*res) + j) = NULL;
		j++;
	}
	free((*res));
	(*res) = NULL;
}

int		atoii(char *str, int *i)
{
	unsigned long	nb;
	int				minus;
	int				count;

	minus = 0;
	count = 0;
	nb = 0;
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t'
		|| str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f')
		(*i)++;
	if (str[*i] == '-')
		minus = 1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		nb = (nb * 10) + (str[(*i)++] - '0');
		if (++count >= 20 || (nb > 9223372036854775807 && minus == 1))
			return (0);
		if (nb > 9223372036854775807)
			return (-1);
	}
	if (minus == 1)
		return ((int)-nb);
	return ((int)nb);
}

int		ft_strcount(char ***res)
{
	int		size;

	size = 0;
	while ((*res)[size])
		size++;
	return (size);
}

int		count_num(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] < 48 || str[i] > 57))
			i++;
		if (!str[i])
			break ;
		while (str[i] && (str[i] > 47 && str[i] < 58))
			i++;
		count++;
	}
	return (count);
}
