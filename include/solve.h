/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 22:33:32 by asagymba          #+#    #+#             */
/*   Updated: 2024/10/14 19:17:47 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H 
# define SOLVE_H

# include <libft.h>

struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
};

/**
 * Init stacks required for push_swap.
 * 'stack_a' will point to a head of stack 'a', if everything went fine;
 * 	otherwise (e.g. there were duplicates), it will point to NULL.
 * 'stack_b' will point to NULL, if everything went fine;
 * 	in case if there were duplicates, it'll point to 0x1.
 * @param	parsed_args	List of parsed arguments.
 * @return	Initialized stacks.
 */
struct s_stacks	init_stacks(const t_list *parsed_args);

/**
 * Checks, if stack is sorted or not.
 * @param	stack	A stack to check.
 * @return	Some non-negative value, if it yes;
 * 			(-1) otherwise.
 */
int				is_sorted(t_list *stack);

/**
 * Solves push_swap.
 * @param	parsed_args	List of parsed arguments.
 * @return	Some non-negative value, if no errors listed in a subject's PDF
 * 				were found;
 * 			otherwise (e.g. in case of duplicates), -1 will be returned.
 */
int				push_swap(const t_list *parsed_args);

/**
 * Clears stacks.
 * @param	stacks	Pointer to structure containing stacks.
 */
void			destroy_stacks(struct s_stacks *stacks);

#endif	/* SOLVE_H */
