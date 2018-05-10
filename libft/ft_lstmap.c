/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:56:31 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/15 17:55:53 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*to_f;

	if (!lst || !f)
		return (NULL);
	to_f = f(lst);
	newlst = to_f;
	while (lst->next)
	{
		lst = lst->next;
		if (!(to_f->next = f(lst)))
			return (NULL);
		to_f = to_f->next;
	}
	return (newlst);
}
