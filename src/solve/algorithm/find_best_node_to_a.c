/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_node_to_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:15:30 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:37:09 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solve.h>
#include <libft.h>
#include <stddef.h>
#include "algorithm.h"
#include <stdint.h>

void	find_best_node_to_a(struct s_stacks *stacks,
			t_list **from_b, t_list **to_a)
{
	t_list	*current_node;
	t_list	*target_node;
	size_t	current_cost;
	size_t	best_cost;

	current_node = stacks->stack_b;
	*from_b = NULL;
	while (current_node != NULL)
	{
		target_node = find_closest_bigger(stacks->stack_a,
				(int)(uintptr_t)(current_node->content));
		if (target_node == NULL)
			target_node = find_min(stacks->stack_a);
		current_cost = cost_analysis(stacks, current_node, target_node);
		if (*from_b == NULL
			|| best_cost > current_cost)
		{
			*from_b = current_node;
			best_cost = current_cost;
			*to_a = target_node;
		}
		current_node = current_node->next;
	}
}
