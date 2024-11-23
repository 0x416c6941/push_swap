/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:40:23 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:33:03 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <args.h>
#include <unistd.h>
#include <solve.h>

#define MIN_ARGC	2

int	main(int argc, char **argv)
{
	t_list	*parsed_args;

	if (!(argc >= MIN_ARGC))
		return (0);
	parsed_args = parse_args(--argc, (const char **)++argv);
	if (parsed_args == NULL || check_args(parsed_args) == -1)
	{
		(void)write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
		ft_lstclear(&parsed_args, (void (*)(void *))ft_split_free);
		return (1);
	}
	if (push_swap(parsed_args) == -1)
	{
		(void)write(STDERR_FILENO, "Error\n", ft_strlen("Error\n"));
		ft_lstclear(&parsed_args, (void (*)(void *))ft_split_free);
		return (1);
	}
	ft_lstclear(&parsed_args, (void (*)(void *))ft_split_free);
	return (0);
}

#undef MIN_ARGC
