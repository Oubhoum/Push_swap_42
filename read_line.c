/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 21:35:48 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/04/26 08:33:05 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i] != '\0' || us2[i] != '\0')
	{
		if (us1[i] != us2[i])
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}

int	check_sorting_bonus(t_stack *stack_x)
{
	int		nbr;
	t_stack	*tmp;

	nbr = 0;
	tmp = stack_x;
	while (tmp)
	{
		if (tmp->next)
			if (tmp->content > tmp->next->content)
				nbr = 1;
		tmp = tmp->next;
	}
	if (nbr == 0)
		return (0);
	return (1);
}

static	void	display_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

static void	handel_25_line(char *str, t_stack **stack_x, t_stack **b_stack_x)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap_a_bs(*stack_x);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap_b_bs(*b_stack_x);
	else if (ft_strcmp(str, "ss\n") == 0)
		swap_a_b_bs(*stack_x, *b_stack_x);
	else if (ft_strcmp(str, "pa\n") == 0)
		ft_push_a_bs(stack_x, b_stack_x);
	else if (ft_strcmp(str, "pb\n") == 0)
		ft_push_b_bs(b_stack_x, stack_x);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate_a_bs(stack_x);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate_b_bs(b_stack_x);
	else if (ft_strcmp(str, "rr\n") == 0)
		rotate_a_n_b_bs(stack_x, b_stack_x);
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse_rotate_a_bs(stack_x);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse_rotate_b_bs(b_stack_x);
	else if (ft_strcmp(str, "rrr\n") == 0)
		reverse_rotate_a_n_b_bs(stack_x, b_stack_x);
	else
		display_error();
}

void	read_stdin(t_stack **lst, t_stack **b_lst)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		handel_25_line(line, lst, b_lst);
		free(line);
		line = get_next_line(0);
	}
}
