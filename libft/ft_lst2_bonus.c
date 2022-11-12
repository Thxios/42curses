/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:57:19 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/12 17:38:01 by jimlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	(*del)(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*temp;

	cur = *lst;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*cur;

	cur = lst;
	while (cur)
	{
		(*f)(cur->content);
		cur = cur->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_begin;
	t_list	*new_prev;
	t_list	*new_cur;
	t_list	*cur;

	new_begin = NULL;
	new_prev = NULL;
	cur = lst;
	while (cur)
	{
		new_cur = ft_lstnew((*f)(cur->content));
		if (!new_cur)
		{
			ft_lstclear(&new_begin, del);
			return (NULL);
		}
		if (new_prev)
			new_prev->next = new_cur;
		else
			new_begin = new_cur;
		new_prev = new_cur;
		cur = cur->next;
	}
	return (new_begin);
}
