/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:09:52 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:33:21 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <args.h>
#include <stddef.h>
#include <libft.h>
#include <stdlib.h>

/**
 * Calculates amount of strings in a successful return value of ft_split().
 * @param	ft_split_result	Successful result value of ft_split().
 * @return	Count of strings in a successful result value of ft_split().
 */
static size_t	ft_split_result_size(const char **ft_split_result)
{
	size_t	i;

	i = 0;
	while (ft_split_result[i] != NULL)
		i++;
	return (i);
}

/**
 * Bypass Norminette.
 * @param	arg_split	Result of ft_split(), on which
 * 						ft_split_result_size() will be called.
 * @param	head		A head of a list to be cleared.
 */
/* Should this be in the condition for the error checker ???:
	|| (ft_split_result_size(arg_split) > 1 && argc != 0)) */
static void	parse_args_end(char **arg_split, t_list *head)
{
	ft_split_free(arg_split);
	ft_lstclear(&head, (void (*)(void *))ft_split_free);
}

t_list	*parse_args(int argc, const char **argv)
{
	t_list		*head;
	const char	**arg_split;
	t_list		*next;

	head = NULL;
	while (argc-- > 0)
	{
		arg_split = (const char **)ft_split(*argv++, ' ');
		if (arg_split == NULL
			|| ft_split_result_size(arg_split) == 0)
		{
			parse_args_end((char **)arg_split, head);
			return (NULL);
		}
		next = ft_lstnew(arg_split);
		if (next == NULL)
		{
			parse_args_end((char **)arg_split, head);
			return (NULL);
		}
		ft_lstadd_back(&head, next);
	}
	return (head);
}

void	ft_split_free(char **to_free)
{
	size_t	i;

	if (to_free == NULL)
		return ;
	i = 0;
	while (to_free[i] != NULL)
		free(to_free[i++]);
	free(to_free);
}
