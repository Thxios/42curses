/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:57:19 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/09 19:17:21 by jimlee           ###   ########.fr       */
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
	t_list	*new_cur;

	cur = *lst;
	while (cur)
	{
		(*del)(cur->content);
		new_cur = cur;
		cur = cur->next;
		free(new_cur);
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

static t_list	*ft_lstdel_next(t_list *lst, void (*del)(void *))
{
	t_list	*new_cur;

	new_cur = lst->next;
	ft_lstdelone(lst, del);
	return (new_cur);
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
		cur = ft_lstdel_next(cur, del);
	}
	return (new_begin);
}
