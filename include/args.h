/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:05:55 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:26:57 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include <libft.h>

/**
 * Divides 'argv' into a list, each node of which contains an array of strings.
 * One of the checks done: if after the string with multiple arguments
 * follows some another string, then NULL is returned,
 * since such an argument is always the last one (see checker).
 * @param	argc	Argument count.
 * @param	argv	Argument vector.
 * @return	A list of parsed argument, or NULL in case of some error.
 */
t_list	*parse_args(int argc, const char **argv);

/**
 * Frees the array of strings, that is a result of ft_split().
 * @param	to_free	Array of strings to free().
 */
void	ft_split_free(char **to_free);

/**
 * Checks, if 'arg' contains a string of the following format:
 * [0-n whitespaces][+/- sign][1-m digits][0-l whitespaces]
 * Integer in 'arg' must also be in range [INT_MIN, INT_MAX].
 * @param	arg	Argument to check.
 * @return	If all arguments in 'arg' are of the required format,
 * 				and are in range [INT_MIN, INT_MAX],
 * 				then amount of those arguments.
 * 			-1 otherwise.
 */
int	check_arg(const char *arg);

/**
 * Checks, if all argument in 'parsed_args' fulfill format
 * provided in check_arg().
 * @warning	Duplicates aren't checked.
 * @param	parsed_args	A list of parsed argument.
 * @return	Some non-negative value, if all arguments in 'parsed_args' fulfill
 * 				format provided in check_arg(), and if there are no duplicates;
 * 			-1 otherwise.
 */
int	check_args(const t_list *parsed_args);

#endif	/* ARGS_H */
