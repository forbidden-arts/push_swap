/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmer <dpalmer@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:22:54 by dpalmer           #+#    #+#             */
/*   Updated: 2022/12/20 11:54:41 by dpalmer          ###   ########.fr       */
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

/*		Stack building			*/
t_stack	*ft_parse_to_stack(t_stack *a, char *str);
t_stack	*ft_make_new_stack(int i);
void	ft_stack_add_tail(t_stack **stack, t_stack *new);
t_stack	*ft_build_stack(t_stack *a, char **argv);

/*		General Utilities		*/
long	ft_stk_atoi(const char *str);

/*		Error Related			*/
void	ft_tab_unwind(char **tab);
void	ft_exit_on_error(t_stack **a, t_stack **b);
void	ft_stk_chk_valid(char **argv);
void	ft_free_stack(t_stack **stack);
void	ft_chk_dup_stack(t_stack *a);

/*		Stack Utilities			*/
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_sec_last(t_stack *stack);
void	ft_rotate_stack(t_stack **stack, int dir);

void	ft_print_stack(t_stack *a);

#endif
