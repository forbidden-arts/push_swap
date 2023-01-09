/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:37:53 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/09 12:31:57 by dpalmer          ###   ########.fr       */
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
int	ft_to_top(t_stack **stack, int i)
{
	int	pos;

	if ((*stack)->index == i)
		return (0);
	pos = ft_get_pos(*stack, i);
	if (pos - 1 <= ft_stack_size(*stack) - pos)
		return (-1);
	else
		return (1);
}
