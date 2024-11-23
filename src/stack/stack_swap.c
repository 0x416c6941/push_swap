/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:27:39 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:40:53 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <libft.h>
#include <stddef.h>

void	stack_swap(t_list **stack_head)
{
	t_list	*head;
	t_list	*head_next_next;

	if (stack_head == NULL
		|| *stack_head == NULL || (*stack_head)->next == NULL)
		return ;
	head = *stack_head;
	head_next_next = (*stack_head)->next->next;
	*stack_head = (*stack_head)->next;
	(*stack_head)->next = head;
	(*stack_head)->next->next = head_next_next;
}
