/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:38:04 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:36:03 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <solve.h>
#include <libft.h>
#include <stddef.h>
#include <stdint.h>

/**
 * Helper empty function for init_stacks(),
 * since we don't allocate anything on stack for our stacks.
 * @param	nothing	A pointer to anything. Nothing will happen to it.
 */
static void	empty_func(void *nothing)
{
	(void)nothing;
}

/**
 * Checks for duplicates in a 'stack'.
 * @param	stack	Stack to check for duplicates.
 * @return	Some non-negative value, if there are no duplicates;
 * 			(-1) otherwise.
 */
static int	check_for_dups(const t_list *stack)
{
	const t_list	*i;
	const t_list	*j;

	i = stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if ((uintptr_t)j->content == (uintptr_t)i->content)
				return (-1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

/**
 * A dirty hack to bypass Norminette.
 * @param	stacks	In here, 'stack_a' will be freed, will be set to NULL,
 * 					and 'stack_b' will point to 0x1.
 */
static void	clear_stack_and_report_dups(struct s_stacks *stacks)
{
	ft_lstclear(&(stacks->stack_a), empty_func);
	stacks->stack_a = NULL;
	stacks->stack_b = (t_list *)0x1;
}

struct s_stacks	init_stacks(const t_list *parsed_args)
{
	struct s_stacks	ret;
	size_t			i;
	t_list			*tmp;

	ret.stack_a = NULL;
	ret.stack_b = NULL;
	while (parsed_args != NULL)
	{
		i = 0;
		while (((const char **)(parsed_args->content))[i] != NULL)
		{
			tmp = ft_lstnew((void *)((uintptr_t)ft_atoi(
							((const char **)(parsed_args->content))[i++])));
			if (tmp == NULL)
			{
				ft_lstclear(&ret.stack_a, empty_func);
				return (ret);
			}
			ft_lstadd_back(&ret.stack_a, tmp);
		}
		parsed_args = parsed_args->next;
	}
	if (check_for_dups(ret.stack_a) == -1)
		clear_stack_and_report_dups(&ret);
	return (ret);
}
