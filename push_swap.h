/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoubhoum <aoubhoum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:57:09 by aoubhoum          #+#    #+#             */
/*   Updated: 2023/05/02 15:25:12 by aoubhoum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include	<unistd.h>
# include	"libft/libft.h"
# include	"get_next_line.h"
# include   <stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}	t_stack;

char	*join_function(char **av);
int		check_if_digit(char **tab);
int		check_befor_n_after_sign(char *str);
int		repeated_item(char **array);
int		check_sorting(char	**array);
t_stack	*ft_lstnew(int data);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **list, t_stack *new);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	swap_a_b(t_stack *stack_a, t_stack *stack_b);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b(t_stack **stack_b, t_stack **stack_a);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_a_n_b(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_a_n_b(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **lst);
void	sort_four(t_stack **stack_xx);
void	sort_five(t_stack **lst);
int		check_empty_string(char *str);
int		check_is_int(char **split);
//===================================] utils [===============================//
int		get_index(int x, t_stack **lst);
int		get_min(t_stack **lst);
void	func_go_top(int element, t_stack **lst, int flag);
void	big_sort(t_stack **lst, t_stack **b_lst);
int		get_next(int element, t_stack *lst);
int		best_move(int element, t_stack *lst);
int		min_best_move(t_stack *stack_a, t_stack *stack_b);
void	back_to_a(t_stack **stack_a, t_stack **stack_b);
void	who_is_sorting(int ac, t_stack *stack_a, t_stack *stack_b);
//=================================] bonus function [=========================//
void	read_stdin(t_stack **lst, t_stack **b_lst);
int		check_sorting_bonus(t_stack *stack_x);
void	swap_a_bs(t_stack *stack_a);
void	swap_b_bs(t_stack *stack_b);
void	swap_a_b_bs(t_stack *stack_a, t_stack *stack_b);
void	ft_push_a_bs(t_stack **stack_a, t_stack **stack_b);
void	ft_push_b_bs(t_stack **stack_b, t_stack **stack_a);
void	rotate_a_bs(t_stack **stack_a);
void	rotate_b_bs(t_stack **stack_b);
void	rotate_a_n_b_bs(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a_bs(t_stack **stack_a);
void	reverse_rotate_b_bs(t_stack **stack_b);
void	reverse_rotate_a_n_b_bs(t_stack **stack_a, t_stack **stack_b);

#endif