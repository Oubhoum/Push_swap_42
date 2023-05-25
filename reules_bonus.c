/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reules_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:55:06 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/26 08:33:36 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_bs(t_stack *stack_a)
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
	}
}

void	swap_b_bs(t_stack *stack_b)
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
	}
}

void	swap_a_b_bs(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b) < 2)
	{
		swap_a_bs(stack_a);
		swap_b_bs(stack_b);
	}
	else
		return ;
}

void	ft_push_a_bs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	if (stack_b && ft_lstsize(*stack_b) >= 1)
	{
		tmp = *stack_b;
		ft_lstadd_front(stack_a, ft_lstnew(tmp->content));
		(*stack_b) = (*stack_b)->next;
		free(tmp);
		tmp = NULL;
	}
}

void	ft_push_b_bs(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (stack_b && ft_lstsize(*stack_a) >= 1)
	{
		tmp = *stack_a;
		(*stack_a) = (*stack_a)->next;
		ft_lstadd_front(stack_b, ft_lstnew(tmp->content));
		free(tmp);
		tmp = NULL;
	}
}
