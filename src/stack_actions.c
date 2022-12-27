/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:16:36 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/27 13:49:40 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack **stack)
{
	ft_stack_swap(stack);
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack **stack)
{
	ft_stack_swap(stack);
	ft_printf("sb\n");
}

void	ft_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_stack_swap(stack_a);
	ft_stack_swap(stack_b);
	ft_printf("ss\n");
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_stack(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_stack(stack_a, stack_b);
	ft_printf("pb\n");
}
