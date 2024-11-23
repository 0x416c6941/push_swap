/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:54:27 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:35:58 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solve.h>
#include <stddef.h>
#include <libft.h>

/**
 * Helper empty function for destroy_stacks(),
 * since we don't allocate anything on stack for our stacks.
 * @param	nothing	A pointer to anything. Nothing will happen to it.
 */
static void	empty_func(void *nothing)
{
	(void)nothing;
}

/**
 * stacks->stack_b should be empty by this point, but just to be sure,
 * let's also call ft_lstclear() on it.
 */
void	destroy_stacks(struct s_stacks *stacks)
{
	if (stacks == NULL)
		return ;
	ft_lstclear(&(stacks->stack_a), empty_func);
	ft_lstclear(&(stacks->stack_b), empty_func);
}
