/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:51:04 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:41:08 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <args.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <libft.h>

int	check_arg(const char *arg)
{
	bool	got_digit;
	int		atoi_result;
	int8_t	first_non_zero_digit;

	got_digit = false;
	atoi_result = ft_atoi(arg);
	first_non_zero_digit = 0;
	if (arg == NULL)
		return (-1);
	while (ft_isspace(*arg))
		arg++;
	if (*arg == '+' || *arg == '-')
		arg++;
	while (ft_isdigit(*arg))
	{
		got_digit = true;
		if (!first_non_zero_digit)
			first_non_zero_digit = *arg - '0';
		arg++;
	}
	while (ft_isspace(*arg))
		arg++;
	if (got_digit && *arg == '\0' && (!first_non_zero_digit || atoi_result))
		return (0);
	return (-1);
}

int	check_args(const t_list *parsed_args)
{
	const t_list	*node;
	size_t			i;

	node = parsed_args;
	while (node != NULL)
	{
		i = 0;
		while (((const char **)(node->content))[i] != NULL)
			if (check_arg(((const char **)(node->content))[i++]) == -1)
				return (-1);
		node = node->next;
	}
	return (0);
}
