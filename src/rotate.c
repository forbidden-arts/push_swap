/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:37:53 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/10 16:10:17 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Makes the shortest possible move to bring that number to the top. */
void	ft_smart_rotate_a(t_stack **stack, int i)
{
	if (ft_find_fwd(*stack, i) <= ft_find_bwd(*stack, i))
		ft_do_op_n(stack, NULL, RA, ft_find_fwd(*stack, i));
	else
		ft_do_op_n(stack, NULL, RRA, ft_find_bwd(*stack, i));
}

// void	ft_smart_rotate_b(t_stack **stack, int i)
// {

// }

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
