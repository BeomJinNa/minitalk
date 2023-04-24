/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:30:05 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:19:14 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (1)
	{
		f(lst->content);
		lst = lst->next;
		if (lst == 0)
			return ;
	}
}
