/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:12:42 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:40:48 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <libft.h>
#include <stddef.h>

void	stack_rotate(t_list **stack_head)
{
	t_list	*head;

	if (stack_head == NULL
		|| *stack_head == NULL || (*stack_head)->next == NULL)
		return ;
	head = *stack_head;
	*stack_head = (*stack_head)->next;
	while ((*stack_head)->next != NULL)
		stack_head = &((*stack_head)->next);
	(*stack_head)->next = head;
	head->next = NULL;
}
