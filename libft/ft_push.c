/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:02:37 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/16 18:02:40 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_push(t_list **list, t_list *newlist)
{
	t_list *head;

	if (!list || !newlist)
		return ;
	if (*list)
	{
		head = *list;
		while ((*list)->next)
			*list = (*list)->next;
		(*list)->next = newlist;
		*list = head;
	}
	else
		*list = newlist;
}
