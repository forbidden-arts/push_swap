/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:02:00 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/27 13:21:31 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Had to move different actions into their own file to meet Norminette.
	Positive dir is "normal" rotation, negative is "reverse".				*/

void	ft_rotate_a(t_stack **stack, int dir)
{
	if (dir >= 0)
	{
		ft_rotate_stack(stack, 1);
		ft_printf("ra\n");
	}
	else
	{
		ft_rotate_stack(stack, -1);
		ft_printf("rra\n");
	}
}

void	ft_rotate_b(t_stack **stack, int dir)
{
	if (dir >= 0)
	{
		ft_rotate_stack(stack, 1);
		ft_printf("rb\n");
	}
	else
	{
		ft_rotate_stack(stack, -1);
		ft_printf("rrb\n");
	}
}

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, int dir)
{
	if (dir >= 0)
	{
		ft_rotate_stack(stack_a, 1);
		ft_rotate_stack(stack_b, 1);
		ft_printf("rr\n");
	}
	else
	{
		ft_rotate_stack(stack_a, -1);
		ft_rotate_stack(stack_b, -1);
		ft_printf("rrr\n");
	}
}
