/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:26:05 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/13 17:31:06 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int data)
{
	t_stack	*var;

	var = (t_stack *)malloc(sizeof(t_stack));
	if (!var)
		return (NULL);
	var->content = data;
	var->next = NULL;
	return (var);
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	*lst = new;
	new->next = tmp;
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_stack **list, t_stack *new)
{
	t_stack	*tmp;

	tmp = ft_lstlast(*list);
	tmp->next = new;
	new->next = NULL;
}
