/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_stats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:40:01 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/31 09:50:22 by dpalmer          ###   ########.fr       */
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
