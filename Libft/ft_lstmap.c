/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated: 2024/11/10 17:55:10 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*_list;
	t_list		*elem;
	void		*cont;

	_list = NULL;
	elem = NULL;
	cont = 0;
	while (lst)
	{
		cont = f(lst->content);
		elem = ft_lstnew(cont);
		if (!elem)
		{
			del(cont);
			ft_lstclear(&_list, del);
			return (NULL);
		}
		if (!_list)
			_list = elem;
		else
			ft_lstadd_back(&_list, elem);
		lst = lst->next;
	}
	return (_list);
}
