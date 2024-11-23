/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_up_to_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:46:07 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:38:25 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm.h>
#include <solve.h>
#include <ops.h>

/**
 * We push up to two elements. But what, if this changes in the future? :)
 */
#define HOW_MANY	2

void	push_up_to_two(struct s_stacks *stacks)
{
	int	a_size;
	int	i;

	if (stacks == NULL || stacks->stack_a == NULL)
		return ;
	a_size = ft_lstsize(stacks->stack_a);
	i = 0;
	while (a_size > TURK_ALGORITHM_MOVE_FROM_A_UNTIL && i < HOW_MANY)
	{
		op_pb(stacks);
		a_size--;
		i++;
	}
}
