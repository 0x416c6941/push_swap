/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:36:22 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:33:32 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ops.h>
#include <libft.h>
#include <stddef.h>
#include <stack.h>

int	op_pa(struct s_stacks *stacks)
{
	if (stacks == NULL || stacks->stack_b == NULL)
		return (-1);
	stack_push(&(stacks->stack_a), stack_pop(&(stacks->stack_b)));
	return (ft_printf("pa\n"));
}
