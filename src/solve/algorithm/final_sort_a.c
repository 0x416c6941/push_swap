/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:23:38 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:36:59 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm.h>
#include <solve.h>
#include <libft.h>
#include <ops.h>

void	final_sort_a(struct s_stacks *stacks)
{
	t_list	*to_the_top;
	int		ops_cnt;

	to_the_top = find_min(stacks->stack_a);
	ops_cnt = count_operations_to_move_on_top(stacks->stack_a, to_the_top);
	while (ops_cnt < 0)
	{
		op_rra(stacks);
		ops_cnt++;
	}
	while (ops_cnt > 0)
	{
		op_ra(stacks);
		ops_cnt--;
	}
}
