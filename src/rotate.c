/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:37:53 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/09 20:07:22 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds a number less than "i" and returns direction. */
int	ft_smart_rotate(t_stack **stack, int i)
{
	while ((*stack)->index > i)
	{
		if (ft_find_fwd(*stack, i) <= ft_find_bwd(*stack, i))
			return (1);
		else
			return (-1);
	}
	return (0);
}

/* Moves int "i" to the top the quickest way by indicating direction */
void	ft_to_top_a(t_stack **stack, int i)
{
	int	pos;

	if ((*stack)->index == i)
		return ;
	while ((*stack)->index != i)
	{
	pos = ft_get_pos(*stack, i);
	if (pos <= ft_s_size(*stack) / 2)
		ft_do_op(stack, NULL, RA);
	else
		ft_do_op(stack, NULL, RRA);
	}
}
