/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:30:18 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/20 11:54:01 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	if (stack->next == NULL)
		return (stack);
	return (ft_stack_last(stack->next));
}

t_stack	*ft_stack_sec_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

void	ft_rotate_stack(t_stack **stack, int dir)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (dir >= 0)
	{
		tail = ft_stack_last(*stack);
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		tail->next = tmp;
	}
	else
	{
		tail = ft_stack_sec_last(*stack);
		tmp = ft_stack_last(*stack);
		tail->next = NULL;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
}
