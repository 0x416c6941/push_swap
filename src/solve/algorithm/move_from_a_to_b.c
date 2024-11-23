/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_from_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:23:38 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:37:57 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm.h>
#include <solve.h>
#include <libft.h>
#include <ops.h>

/**
 * Bypasses Norminette. Used to move two nodes simultaneously.
 * @param	stacks	Stacks.
 * @param	from_a	Node in 'stacks->stack_a'.
 * @param	to_b	Node in 'stacks->stack_b'.
 */
static void	move_from_a_to_b_helper_common(struct s_stacks *stacks,
		t_list *from_a, t_list *to_b)
{
	int	a_ops_cnt;
	int	b_ops_cnt;

	a_ops_cnt = count_operations_to_move_on_top(stacks->stack_a, from_a);
	b_ops_cnt = count_operations_to_move_on_top(stacks->stack_b, to_b);
	while (a_ops_cnt < 0 && b_ops_cnt < 0)
	{
		op_rrr(stacks);
		a_ops_cnt++;
		b_ops_cnt++;
	}
	while (a_ops_cnt > 0 && b_ops_cnt > 0)
	{
		op_rr(stacks);
		a_ops_cnt--;
		b_ops_cnt--;
	}
}

/**
 * Bypasses Norminette. Moves 'a_node' to top of 'stacks->stack_a'.
 * @param	stacks	Two stacks.
 * @param	a_node	Nove from a to move to top of 'stacks->stack_a'.
 */
static void	move_from_a_to_b_helper_a(struct s_stacks *stacks, t_list *a_node)
{
	int	a_ops_cnt;

	a_ops_cnt = count_operations_to_move_on_top(stacks->stack_a, a_node);
	while (a_ops_cnt < 0)
	{
		op_rra(stacks);
		a_ops_cnt++;
	}
	while (a_ops_cnt > 0)
	{
		op_ra(stacks);
		a_ops_cnt--;
	}
}

/**
 * Bypasses Norminette. Moves 'b_node' to top of 'stacks->stack_b'.
 * @param	stacks	Two stacks.
 * @param	b_node	Nove from a to move to top of 'stacks->stack_b'.
 */
static void	move_from_a_to_b_helper_b(struct s_stacks *stacks, t_list *b_node)
{
	int	b_ops_cnt;

	b_ops_cnt = count_operations_to_move_on_top(stacks->stack_b, b_node);
	while (b_ops_cnt < 0)
	{
		op_rrb(stacks);
		b_ops_cnt++;
	}
	while (b_ops_cnt > 0)
	{
		op_rb(stacks);
		b_ops_cnt--;
	}
}

void	move_from_a_to_b(struct s_stacks *stacks)
{
	int		a_size;
	t_list	*best_node_in_a;
	t_list	*target_node_in_b;

	a_size = ft_lstsize(stacks->stack_a);
	while (a_size-- > TURK_ALGORITHM_MOVE_FROM_A_UNTIL)
	{
		find_best_node_to_b(stacks, &best_node_in_a, &target_node_in_b);
		move_from_a_to_b_helper_common(stacks,
			best_node_in_a, target_node_in_b);
		move_from_a_to_b_helper_a(stacks, best_node_in_a);
		move_from_a_to_b_helper_b(stacks, target_node_in_b);
		op_pb(stacks);
	}
}
