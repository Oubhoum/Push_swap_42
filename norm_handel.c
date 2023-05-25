/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_handel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:33:39 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/29 14:32:51 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *fr_lst)
{
	t_stack	*tmp;

	while (fr_lst)
	{
		tmp = fr_lst;
		fr_lst = fr_lst->next;
		free(tmp);
		tmp = NULL;
	}
}

static	void	first_func(int stack_size, t_stack *stack_a)
{
	if (stack_size == 2)
	{
		swap_a(stack_a);
		free_stack(stack_a);
	}
	else if (stack_size == 3)
	{
		sort_three(&stack_a);
		free_stack(stack_a);
	}
	else if (stack_size == 4)
	{
		sort_four(&stack_a);
		free_stack(stack_a);
	}
	else if (stack_size == 5)
	{
		sort_five(&stack_a);
		free_stack(stack_a);
	}
}

void	who_is_sorting(int stack_size, t_stack *stack_a, t_stack *stack_b)
{
	if (stack_size == 2 || stack_size == 3
		|| stack_size == 4 || stack_size == 5)
		first_func(stack_size, stack_a);
	else
	{
		big_sort(&stack_a, &stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
}
