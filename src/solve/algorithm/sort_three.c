/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:13:19 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:38:43 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm.h>
#include <solve.h>
#include <ops.h>
#include <libft.h>
#include <stdint.h>

void	sort_three(struct s_stacks *stacks)
{
	int		a_size;
	t_list	*max_node;

	a_size = ft_lstsize(stacks->stack_a);
	if (a_size <= 1)
		return ;
	max_node = find_max(stacks->stack_a);
	if (calculate_node_position_in_stack(stacks->stack_a, max_node) == 0)
		op_ra(stacks);
	else if (calculate_node_position_in_stack(stacks->stack_a, max_node) == 1)
		op_rra(stacks);
	if ((int)((uintptr_t)(stacks->stack_a->content))
		> (int)((uintptr_t)(stacks->stack_a->next->content)))
		op_sa(stacks);
}
