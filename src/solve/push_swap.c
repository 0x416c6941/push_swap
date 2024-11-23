/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 23:01:55 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:36:22 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solve.h>
#include <stddef.h>
#include <algorithm.h>

int	push_swap(const t_list *parsed_args)
{
	struct s_stacks	stacks;

	stacks = init_stacks(parsed_args);
	if (stacks.stack_a == NULL)
	{
		if (stacks.stack_b == (t_list *)0x1)
			return (-1);
		return (0);
	}
	if (is_sorted(stacks.stack_a) != (-1))
	{
		destroy_stacks(&stacks);
		return (0);
	}
	push_up_to_two(&stacks);
	move_from_a_to_b(&stacks);
	sort_three(&stacks);
	move_from_b_to_a(&stacks);
	final_sort_a(&stacks);
	destroy_stacks(&stacks);
	return (0);
}
