/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:40:01 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/02 21:41:58 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_index(t_stack *stack)
{
	t_stack	*ptr;
	t_stack	*max;
	int		size;

	size = ft_stack_size(stack);
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

void	ft_bucketize(t_stack *stack, int buckets)
{
	int	size;

	size = ft_stack_size(stack);
	while (stack->next)
	{
		stack->bucket = (stack->index / (size / buckets + 1) + 1);
		stack = stack->next;
	}
	stack->bucket = (stack->index / (size / buckets + 1) + 1);
}

int	ft_find_max(t_stack *stack)
{
	int	max;
	int	size;

	if (!stack)
		return (0);
	max = 0;
	size = ft_stack_size(stack);
	while (size--)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	ft_find_min(t_stack *stack)
{
	int	min;
	int	size;

	if (!stack)
		return (0);
	size = ft_stack_size(stack);
	min = stack->index;
	while (size--)
	{
		if (min > stack->index)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

int	ft_stack_avg(t_stack *stack)
{
	int		i;
	int		size;
	float	total;

	if (!stack)
		return (0);
	size = ft_stack_size(stack);
	i = 0;
	total = 0;
	while (i++ < size)
	{
		total += stack->index;
		stack = stack->next;
	}
	return ((int)(total / size + 0.5));
}
