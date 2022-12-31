/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:41:03 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/31 12:04:01 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_next_b(t_stack *stack, int b)
{
	int	i;

	i = 1;
	while (stack->bucket != b)
	{
		if (!stack->next)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}

int	ft_find_last_b(t_stack *stack, int b)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (stack->next)
	{
		if (stack->bucket == b)
			i = stack->index;
		stack = stack->next;
	}
	if (stack->bucket == b)
		i = stack->index;
	return (ft_get_pos(tmp, i));
}
