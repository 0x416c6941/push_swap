/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:17:54 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:36:10 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solve.h>
#include <stddef.h>
#include <libft.h>
#include <stdint.h>

int	is_sorted(t_list *stack)
{
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (!((int)((uintptr_t)(stack->next->content))
				> (int)((uintptr_t)(stack->content))))
			return (-1);
		stack = stack->next;
	}
	return (0);
}
