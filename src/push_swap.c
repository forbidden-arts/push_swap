/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:10:20 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/25 13:34:53 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	ft_stk_chk_valid(argv);
	a = ft_build_stack(a, argv);
	ft_chk_dup_stack(a);
	assign_index(a);
	ft_print_stack(a);
	ft_push_stack(&b, &a);
	ft_print_stack(a);
	ft_print_stack(b);
	// ft_rotate_stack(&a, 1);
	// ft_print_stack(a);
	// ft_rotate_stack(&a, -1);
	// ft_rotate_stack(&a, -1);
	// ft_print_stack(a);
	return (0);
}
