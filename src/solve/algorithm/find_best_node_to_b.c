/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_node_to_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:15:30 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:37:18 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solve.h>
#include <libft.h>
#include <stddef.h>
#include <algorithm.h>
#include <stdint.h>

void	find_best_node_to_b(struct s_stacks *stacks,
			t_list **from_a, t_list **to_b)
{
	t_list	*current_node;
	t_list	*target_node;
	size_t	current_cost;
	size_t	best_cost;

	current_node = stacks->stack_a;
	*from_a = NULL;
	while (current_node != NULL)
	{
		target_node = find_closest_smaller(stacks->stack_b,
				(int)(uintptr_t)(current_node->content));
		if (target_node == NULL)
			target_node = find_max(stacks->stack_b);
		current_cost = cost_analysis(stacks, current_node, target_node);
		if (*from_a == NULL
			|| best_cost > current_cost)
		{
			*from_a = current_node;
			best_cost = current_cost;
			*to_b = target_node;
		}
		current_node = current_node->next;
	}
}
