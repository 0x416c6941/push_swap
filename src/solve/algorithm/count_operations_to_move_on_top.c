/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_operations_to_move_on_top.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:03:16 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:36:44 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm.h>
#include <libft.h>

int	count_operations_to_move_on_top(t_list *stack, t_list *node)
{
	int	stack_median;
	int	node_i;

	stack_median = ft_lstsize(stack) / 2;
	node_i = calculate_node_position_in_stack(stack, node);
	if (node_i == 0)
		return (0);
	else if (node_i > stack_median)
		return ((ft_lstsize(stack) - node_i) * (-1));
	else
		return (node_i);
}
