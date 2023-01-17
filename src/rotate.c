/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:37:53 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/17 11:59:12 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Initialized only once, before qsort, to cut down on later operations. */
// void	ft_smart_rotate_a(t_stack **a, t_stack **b, int i)
// {
// 	int		seek;
// 	// t_stack	*tmp;

// 	// tmp = NULL;
// 	// if (ft_s_size(*b) > 1)
// 	// 	tmp = ft_stack_sec_last(*b);
// 	// if (ft_find_fwd(*a, i) <= ft_find_bwd(*a, i))
// 		seek = ft_get_pos_idx(*a, ft_find_fwd(*a, i) + 1);
// 		// ft_printf("seek: %d\n", seek);
// 	// else
// 	// 	seek = ft_get_pos_idx(*a, ft_s_size(*a) - ft_find_bwd(*a, i) + 1);
// 	// ft_printf("Seeking: %d\n", seek);
// 	// if (ft_find_fwd(*a, i) <= ft_find_bwd(*a, i))
// 	// {
// 		if (ft_s_size(*b) > 1 &&
// 			// (seek < (*b)->index || (*b)->index < (*b)->next->index))
// 			(seek < (*b)->index && seek > (*b)->next->index))
// 			ft_do_op(a, b, RR);
// 		else
// 			ft_do_op(a, b, RA);
// 	// }
// 	// else
// 	// {
// 	// 	if (tmp && ((*b)->index < tmp->next->index))
// 	// 		ft_do_op(a, b, RRR);
// 	// 	else
// 	// 		ft_do_op(a, b, RRA);
// 	// }
// }

/* B-Smart happens 1 step at a time to allow for opportunistic moves. */
void	ft_smart_rotate_b(t_stack **a, t_stack **b, int i)
{
	int	pos;
	int	size;

	if ((*b)->index == i)
		return ;
	pos = ft_get_pos(*b, i);
	size = ft_s_size(*b);
	if (pos <= size - pos + 2)
		ft_do_op(a, b, RB);
	else
		ft_do_op(a, b, RRB);
}

/* Moves int "i" to the top the quickest way by indicating direction */
void	ft_top_a(t_stack **stack, int i)
{
	int	pos;
	int	size;

	if ((*stack)->index == i)
		return ;
	pos = ft_get_pos(*stack, i);
	size = ft_s_size(*stack);
	if (pos <= size - pos + 2)
		ft_do_op_n(stack, NULL, RA, (pos - 1));
	else
		ft_do_op_n(stack, NULL, RRA, (size - pos + 1));
}

void	ft_sort_to_bot(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = ft_stack_last(*a);
	while (!tmp->sorted)
	{
		if ((*b)->index != ft_find_max(*b))
		{
			ft_do_op(a, b, RRR);
		}
		else
			ft_do_op(a, b, RRA);
		tmp = ft_stack_last(*a);
	}
}
