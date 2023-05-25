/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 22:04:41 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/15 01:43:10 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a_bs(t_stack **stack_a)
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
	}
	else
		return ;
}

void	reverse_rotate_b_bs(t_stack **stack_b)
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
	}
	else
		return ;
}

void	reverse_rotate_a_n_b_bs(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
	{
		reverse_rotate_a_bs(stack_a);
		reverse_rotate_b_bs(stack_b);
	}
	else
		return ;
}
