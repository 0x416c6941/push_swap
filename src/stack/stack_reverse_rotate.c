/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:21:48 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:40:43 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <libft.h>
#include <stddef.h>

void	stack_reverse_rotate(t_list **stack_head)
{
	t_list	*i;
	t_list	*last;

	if (stack_head == NULL
		|| *stack_head == NULL || (*stack_head)->next == NULL)
		return ;
	i = *stack_head;
	while (i->next->next != NULL)
		i = i->next;
	last = i->next;
	i->next = NULL;
	last->next = *stack_head;
	*stack_head = last;
}
