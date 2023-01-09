/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:30:18 by dpalmer           #+#    #+#             */
/*   Updated: 2023/01/09 18:21:05 by dpalmer          ###   ########.fr       */
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

	if (ft_s_size(*stack) < 2)
		return ;
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

	if (!(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	ft_stack_add_head(dst, tmp);
}

void	ft_stack_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next->next;
	(*stack)->next->next = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->next->next = tmp;
}
