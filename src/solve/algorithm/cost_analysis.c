/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_analysis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:06:13 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:36:39 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solve.h>
#include <algorithm.h>
#include <stddef.h>

/**
 * I hate Norminette. Used to bypass a limit of 25 lines per function.
 * @param	ret			A pointer to ret.
 * @param	a_ops_cnt	A pointer to a_ops_cnt.
 * @param	b_ops_cnt	A pointer to, you guessed it, b_ops_cnt.
 */
static void	cost_analysis_helper_common(size_t *ret,
				int *a_ops_cnt, int *b_ops_cnt)
{
	while (*a_ops_cnt < 0 && *b_ops_cnt < 0)
	{
		(*ret)++;
		(*a_ops_cnt)++;
		(*b_ops_cnt)++;
	}
	while (*a_ops_cnt > 0 && *b_ops_cnt > 0)
	{
		(*ret)++;
		(*a_ops_cnt)--;
		(*b_ops_cnt)--;
	}
}

size_t	cost_analysis(struct s_stacks *stacks,
			t_list *node_a, t_list *node_b)
{
	int		a_ops_cnt;
	int		b_ops_cnt;
	size_t	ret;

	a_ops_cnt = count_operations_to_move_on_top(stacks->stack_a, node_a);
	b_ops_cnt = count_operations_to_move_on_top(stacks->stack_b, node_b);
	ret = 0;
	cost_analysis_helper_common(&ret, &a_ops_cnt, &b_ops_cnt);
	while (a_ops_cnt != 0)
	{
		ret++;
		if (a_ops_cnt < 0)
			a_ops_cnt++;
		else
			a_ops_cnt--;
	}
	while (b_ops_cnt != 0)
	{
		ret++;
		if (b_ops_cnt < 0)
			b_ops_cnt++;
		else
			b_ops_cnt--;
	}
	return (ret);
}
