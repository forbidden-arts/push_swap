/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:22:54 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/20 08:07:26 by dpalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

// t_stack	*ft_build_stack(char **argv);
long	ft_stack_atoi(const char *str);

void	ft_free_stack(t_stack **stack);
void	**ft_tab_unwind(char **tab);

void	exit_on_error(t_stack **a, t_stack **b);

#endif
