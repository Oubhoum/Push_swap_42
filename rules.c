/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:48:06 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/28 10:41:10 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	int		tmp;
	t_stack	*node;

	node = stack_a;
	if (ft_lstsize(stack_a) >= 2)
	{
		tmp = stack_a->content;
		node = node->next;
		stack_a->content = node->content;
		node->content = tmp;
		ft_putstr_fd("sa\n", 1);
	}
}

void	swap_b(t_stack *stack_b)
{
	int		tmp;
	t_stack	*node;

	node = stack_b;
	if (ft_lstsize(stack_b) >= 2)
	{
		tmp = stack_b->content;
		node = node->next;
		stack_b->content = node->content;
		node->content = tmp;
		ft_putstr_fd("sb\n", 1);
	}
}

void	swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putstr_fd("ss\n", 1);
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	ft_lstadd_front(stack_a, ft_lstnew(tmp->content));
	(*stack_b) = (*stack_b)->next;
	free(tmp);
	tmp = NULL;
	ft_putstr_fd("pa\n", 1);
}

void	ft_push_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	ft_lstadd_front(stack_b, ft_lstnew(tmp->content));
	(*stack_a) = (*stack_a)->next;
	free(tmp);
	tmp = NULL;
	ft_putstr_fd("pb\n", 1);
}
