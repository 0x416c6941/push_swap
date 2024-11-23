/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:16:09 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:40:38 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>

void	stack_push(t_list **stack_head, t_list *node)
{
	node->next = *stack_head;
	*stack_head = node;
}
