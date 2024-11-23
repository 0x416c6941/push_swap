/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:23:49 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:40:33 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack.h>
#include <libft.h>
#include <stddef.h>

t_list	*stack_pop(t_list **stack_head)
{
	t_list	*ret;

	if (stack_head == NULL || *stack_head == NULL)
		return (NULL);
	ret = *stack_head;
	*stack_head = (*stack_head)->next;
	ret->next = NULL;
	return (ret);
}
