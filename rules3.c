/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:59:49 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/09 19:55:58 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*head;

	head = *stack_a;
	if (ft_lstsize(*stack_a) >= 2)
	{
		tmp = ft_lstlast(*stack_a);
		while (head->next->next)
		{
			head = head->next;
		}
		head->next = NULL;
		ft_lstadd_front(stack_a, tmp);
		ft_putstr_fd("rra\n", 1);
	}
}

void	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*head;

	head = *stack_b;
	if (ft_lstsize(*stack_b) >= 2)
	{
		tmp = ft_lstlast(*stack_b);
		while (head->next->next)
		{
			head = head->next;
		}
		head->next = NULL;
		ft_lstadd_front(stack_b, tmp);
		ft_putstr_fd("rrb\n", 1);
	}
}

void	reverse_rotate_a_n_b(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
