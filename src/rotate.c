/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:37:53 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/16 17:09:45 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Makes the shortest possible move to bring that number to the top. */
void	ft_smart_rotate_a(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	tmp = ft_stack_last(*b);
	if (ft_find_fwd(*a, i) <= ft_find_bwd(*a, i))
	{
		if (ft_s_size(*b) > 1 && (*a)->index < (*b)->index)
			ft_do_op(a, b, RR);
		else
			ft_do_op(a, b, RA);
	}
	else
	{
		if (ft_s_size(*b) > 1 && (*a)->index > tmp->index)
			ft_do_op(a, b, RRR);
		else
			ft_do_op(a, b, RRA);
	}
	ft_print_stack(*a);
	ft_print_stack(*b);
}

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
