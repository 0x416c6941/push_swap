/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_node_position_in_stack.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:09:57 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:36:30 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm.h>

int	calculate_node_position_in_stack(t_list *stack, t_list *node)
{
	int	ret;

	ret = 0;
	while (stack != NULL && stack != node)
	{
		ret++;
		stack = stack->next;
	}
	if (stack != node)
		return (-1);
	return (ret);
}
