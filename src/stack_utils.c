/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:30:18 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/20 12:23:54 by dpalmer          ###   ########.fr       */
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

void	ft_push_stack(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	tmp = *src;
	*src = (*src)->next;
	ft_stack_add_head(dst, tmp);
}

int	ft_stack_size(t_stack *stack)
{
	if (!stack)
		return (0);
	if (stack->next == NULL)
		return (1);
	return (1 + (ft_stack_size(stack->next)));
}
