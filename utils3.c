/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:24:27 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/27 15:57:28 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static	int	min_index_func(int *table, int len)
{
	int	min_index;
	int	min;
	int	i;

	min = table[0];
	i = 1;
	while (i < len)
	{
		if (table[i] < min)
		{
			min = table[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	min_best_move(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		*table;
	int		i;
	int		min_index;

	tmp = stack_b;
	i = 0;
	table = (int *)malloc(ft_lstsize(stack_b) * sizeof(int));
	if (!table)
		return (0);
	while (tmp)
	{
		table[i] = best_move(tmp->content, stack_b)
			+ best_move(get_next(tmp->content, stack_a), stack_a);
		i++;
		tmp = tmp->next;
	}
	min_index = min_index_func(table, ft_lstsize(stack_b));
	free (table);
	return (min_index);
}

void	back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int		min_index;
	t_stack	*tmp;
	int		i;

	tmp = *stack_b;
	min_index = min_best_move(*stack_a, *stack_b);
	i = 0;
	while (tmp)
	{
		if (min_index == i)
		{
			func_go_top(tmp->content, stack_b, 1337);
			func_go_top(get_next(tmp->content, *stack_a), stack_a, 1);
			ft_push_a(stack_a, stack_b);
		}
		tmp = tmp->next;
		i++;
	}
}
