/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:10:40 by ylabbe            #+#    #+#             */
/*   Updated: 2021/10/11 18:10:57 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_things;

	new_lst = NULL;
	while (lst)
	{
		if (!lst)
		{
			f(lst->content);
			(*del)(new_lst->content);
			return (NULL);
		}
		new_things = ft_lstnew(f(lst->content));
		ft_lstadd_back(&new_lst, new_things);
		lst = lst->next;
	}
	return (new_lst);
}
