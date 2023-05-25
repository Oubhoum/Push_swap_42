/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:38:36 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/13 17:39:54 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	call_func(t_stack **stack_xx)
{
	swap_a((*stack_xx));
	reverse_rotate_a(stack_xx);
}

void	sort_three(t_stack **lst)
{
	if (ft_lstsize(*lst) != 3)
		return ;
	if ((*lst)->content > (*lst)->next->content
		&& (*lst)->next->content < ft_lstlast(*lst)->content
		&& (*lst)->content < ft_lstlast(*lst)->content)
		swap_a((*lst));
	else if ((*lst)->content > (*lst)->next->content
		&& (*lst)->next->content > ft_lstlast(*lst)->content
		&& (*lst)->content > ft_lstlast(*lst)->content)
		call_func(lst);
	else if ((*lst)->content > (*lst)->next->content
		&& (*lst)->next->content < ft_lstlast(*lst)->content
		&& (*lst)->content > ft_lstlast(*lst)->content)
		rotate_a(lst);
	else if ((*lst)->content < (*lst)->next->content
		&& (*lst)->next->content > ft_lstlast(*lst)->content
		&& (*lst)->content < ft_lstlast(*lst)->content)
	{
		swap_a(*lst);
		rotate_a(lst);
	}
	else if ((*lst)->content < (*lst)->next->content
		&& (*lst)->next->content > ft_lstlast(*lst)->content
		&& (*lst)->content > ft_lstlast(*lst)->content)
		reverse_rotate_a(lst);
}

void	sort_four(t_stack **stack_xx)
{
	t_stack	**b_lst;
	t_stack	*b_lst_x;

	if (ft_lstsize(*stack_xx) != 4)
		return ;
	b_lst = &b_lst_x;
	func_go_top(get_min(stack_xx), stack_xx, 1);
	ft_push_b(b_lst, stack_xx);
	sort_three(stack_xx);
	ft_push_a(stack_xx, b_lst);
}

void	sort_five(t_stack **lst)
{
	t_stack	**b_lst;
	t_stack	*stack_x;

	b_lst = &stack_x;
	if (ft_lstsize(*lst) != 5)
		return ;
	func_go_top(get_min(lst), lst, 1);
	ft_push_b(b_lst, lst);
	func_go_top(get_min(lst), lst, 1);
	ft_push_b(b_lst, lst);
	sort_three(lst);
	ft_push_a(lst, b_lst);
	ft_push_a(lst, b_lst);
}

void	big_sort(t_stack **lst, t_stack **b_lst)
{
	int		size;

	size = ft_lstsize(*lst);
	while (size != 5)
	{
		ft_push_b(b_lst, lst);
		size--;
	}
	sort_five(lst);
	while (ft_lstsize(*b_lst))
	{
		back_to_a(lst, b_lst);
		if (ft_lstsize(*b_lst) == 1)
		{
			func_go_top(get_next((*b_lst)->content, *lst), lst, 1);
			ft_push_a(lst, b_lst);
		}
	}
	func_go_top(get_min(lst), lst, 1);
}
