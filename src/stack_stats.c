/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:40:01 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/02 12:05:46 by dpalmer          ###   ########.fr       */
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

int	ft_stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	return (1 + (ft_stack_size(stack->next)));
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

// void	ft_find_max(t_stack *stack)
// {
// 	int	size;

// 	size = ft_stack_size(stack);
// 	while (stack->next)
// 	{
// 		if (stack->index == size)
// 		{
// 			stack->is_max = 1;
// 			break ;
// 		}
// 		stack = stack->next;
// 	}
// 	if (stack->index == size)
// 		stack->is_max = 1;
// }
