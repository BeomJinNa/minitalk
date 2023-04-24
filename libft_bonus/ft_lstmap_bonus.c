/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:36:06 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:17 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void			ft_lstclear(t_list **lst, void (*del)(void *));
static t_list	*remove_list(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*list;
	t_list	*ptr;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == 0)
		return (0);
	ptr = list;
	while (ptr)
	{
		ptr->content = f(lst->content);
		ptr->next = 0;
		if (lst->next)
		{
			ptr->next = (t_list *)malloc(sizeof(t_list));
			if (ptr->next == 0)
				return (remove_list(&list, del));
		}
		ptr = ptr->next;
		lst = lst->next;
	}
	return (list);
}

static t_list	*remove_list(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (0);
}
