/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:29:21 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/11 21:50:08 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (ft_lstsize(*stack_a) >= 2)
	{
		(*stack_a) = (*stack_a)->next;
		ft_lstadd_back(stack_a, ft_lstnew((tmp)->content));
		free(tmp);
		tmp = NULL;
		ft_putstr_fd("ra\n", 1);
	}
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	if (ft_lstsize(*stack_b) >= 2)
	{
		(*stack_b) = (*stack_b)->next;
		ft_lstadd_back(stack_b, ft_lstnew((tmp)->content));
		free(tmp);
		tmp = NULL;
		ft_putstr_fd("rb\n", 1);
	}
}

void	rotate_a_n_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putstr_fd("rr\n", 1);
}
