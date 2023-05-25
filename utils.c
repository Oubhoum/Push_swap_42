/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 02:12:56 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/09 21:38:34 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int x, t_stack **lst)
{
	int		index;
	t_stack	*tmp;

	index = 0;
	tmp = (*lst);
	while (tmp)
	{
		if (tmp->content == x)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

int	get_min(t_stack **lst)
{
	int		min;
	t_stack	*tmp;

	tmp = *lst;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

static	void	handel_25_line_rr(t_stack **stack_x, int flag)
{
	if (flag == 1)
		reverse_rotate_a(stack_x);
	else
		reverse_rotate_b(stack_x);
}

void	func_go_top(int element, t_stack **lst, int flag)
{
	int	index;

	index = get_index(element, lst);
	if (index == -1)
	{
		ft_putstr_fd("element dont exist\n", 2);
		return ;
	}
	while (index != 0)
	{
		if (index > (ft_lstsize(*lst) / 2))
		{
			handel_25_line_rr(lst, flag);
			index = get_index(element, lst);
		}
		else if (index <= (ft_lstsize(*lst) / 2))
		{
			if (flag == 1)
				rotate_a(lst);
			else
				rotate_b(lst);
			index = get_index(element, lst);
		}
	}
}
