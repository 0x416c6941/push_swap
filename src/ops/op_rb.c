/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:36:22 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:34:13 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ops.h>
#include <libft.h>
#include <stddef.h>
#include <stack.h>

int	op_rb(struct s_stacks *stacks)
{
	const int	min_size = 2;

	if (stacks == NULL || stacks->stack_b == NULL
		|| !(ft_lstsize(stacks->stack_b) >= min_size))
		return (-1);
	stack_rotate(&(stacks->stack_b));
	return (ft_printf("rb\n"));
}
