/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimlee <jimlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:57:19 by jimlee            #+#    #+#             */
/*   Updated: 2022/11/15 17:04:55 by jimlee           ###   ########.fr       */
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

static void	ft_addback_last(t_list **begin, t_list **end, t_list *new)
{
	if (*end)
	{
		(*end)->next = new;
		*end = new;
	}
	else
	{
		*begin = new;
		*end = new;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_begin;
	t_list	*new_end;
	t_list	*new_node;
	t_list	*cur;
	void	*new_content;

	new_begin = NULL;
	new_end = NULL;
	cur = lst;
	while (cur)
	{
		new_content = (*f)(cur->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			(*del)(new_content);
			ft_lstclear(&new_begin, del);
			return (NULL);
		}
		ft_addback_last(&new_begin, &new_end, new_node);
		cur = cur->next;
	}
	return (new_begin);
}
