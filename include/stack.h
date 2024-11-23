/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:21:51 by asagymba          #+#    #+#             */
/*   Updated: 2024/10/06 23:15:43 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <libft.h>

/**
 * Stacks first two elements in '*stack_head'.
 * If there are no at least two elements in '*stack_head',
 * 	nothing will be done.
 * @param	stack_head	A pointer to a head of stack.
 */
void	stack_swap(t_list **stack_head);

/**
 * Pops the first element out of '*stack_head'.
 * @param	stack_head	A pointer to a head of stack.
 * @return	An element from the top of the stack;
 * 			NULL, if stack is empty of stack_head is NULL.
 */
t_list	*stack_pop(t_list **stack_head);

/**
 * Pushes 'node' into the top of '*stack_head'.
 * @param	stack_head	A pointer to a head of stack.
 * @param	node		A node to push to a top of '*stack_head'.
 */
void	stack_push(t_list **stack_head, t_list *node);

/**
 * Rotates stack: the first element becomes the last one.
 * If the are no at least two elements in '*stack_head',
 * 	nothing will be done.
 * @param	stack_head	A pointer to a head of stack.
 */
void	stack_rotate(t_list **stack_head);

/**
 * Reverse rotates stack: the last element becomes the first one.
 * If the are no at least two elements in '*stack_head',
 * 	nothing will be done.
 * @param	stack_head	A pointer to a head of stack.
 */
void	stack_reverse_rotate(t_list **stack_head);

#endif	/* STACK_H */
