/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 10:41:03 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/02 12:17:24 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_next(t_stack *stack, int b)
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

int	ft_find_last(t_stack *stack, int b)
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

int	ft_isbig(t_stack *stack, int i)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->index > i)
			return (0);
		stack = stack->next;
	}
	return (1);
}
