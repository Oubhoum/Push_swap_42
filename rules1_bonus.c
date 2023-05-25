/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:00:32 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/26 08:33:58 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_bs(t_stack **stack_a)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack_a) >= 2)
	{
		tmp = *stack_a;
		(*stack_a) = (*stack_a)->next;
		ft_lstadd_back(stack_a, ft_lstnew((tmp)->content));
		free(tmp);
		tmp = NULL;
	}
}

void	rotate_b_bs(t_stack **stack_b)
{
	t_stack	*tmp;

	if (ft_lstsize(*stack_b) >= 2)
	{
		tmp = *stack_b;
		(*stack_b) = (*stack_b)->next;
		ft_lstadd_back(stack_b, ft_lstnew((tmp)->content));
		free(tmp);
		tmp = NULL;
	}
}

void	rotate_a_n_b_bs(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) >= 2 && ft_lstsize(*stack_a) >= 2)
	{
		rotate_a_bs(stack_a);
		rotate_b_bs(stack_b);
	}
}
