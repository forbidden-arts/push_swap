/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:40:01 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/16 16:27:28 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Indexes numbers 1 to N, for easier handling. */
void	ft_assign_index(t_stack *stack)
{
	t_stack	*ptr;
	t_stack	*max;
	int		size;

	size = ft_s_size(stack);
	while (size)
	{
		ptr = stack;
		max = NULL;
		while (ptr)
		{
			if (ptr->index < 0 && (max == NULL || ptr->value > max->value))
				max = ptr;
			ptr = ptr->next;
		}
		max->index = size;
		size--;
	}
}

/* Returns the max index of a stack that is not already "sorted". */
int	ft_find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = 0;
	while (stack)
	{
		if (stack->index > max && !stack->sorted)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

/* Returns the min index of a stack that is not already "sorted". */
int	ft_find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = INT_MAX;
	while (stack)
	{
		if (min > stack->index && !stack->sorted)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}
