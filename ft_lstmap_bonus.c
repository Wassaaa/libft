/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:34:18 by aklein            #+#    #+#             */
/*   Updated: 2023/10/26 23:06:06 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*add;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	while (lst)
	{
		add = ft_lstnew(f(lst->content));
		if (!add)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, add);
		lst = lst->next;
	}
	return (new_list);
}

t_list	*ft_lstmap_test(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
	{
		ft_lstclear(&new_list, del);
		return (NULL);
	}
	new_list->next = ft_lstmap_test(lst->next, f, del);
	return (new_list);
}
