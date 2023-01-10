/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:37:53 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 19:45:10 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Makes the shortest possible move to bring that number to the top. */
void	ft_smart_rotate_a(t_stack **a, t_stack **b, int i)
{
	if (ft_find_fwd(*a, i) <= ft_find_bwd(*a, i))
		ft_do_op_n(a, b, RA, ft_find_fwd(*a, i) - 1);
	else
		ft_do_op_n(a, b, RRA, ft_find_bwd(*a, i) - 1);
}

/* B-Smart happens 1 step at a time to allow for opportunistic moves. */
void	ft_smart_rotate_b(t_stack **a, t_stack **b, int i)
{
	if (ft_find_fwd_a(*b, i) <= ft_find_bwd_a(*b, i))
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
