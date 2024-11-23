/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:42:34 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:25:34 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include <solve.h>
# include <libft.h>
# include <stddef.h>

/**
 * Everything related to Turk Algorithm.
 */

/**
 * We need to move nodes from 'stack_a' to 'stack_b',
 * and we need to do so precisely until ft_lstsize(stack_a) > 3.
 */
# define TURK_ALGORITHM_MOVE_FROM_A_UNTIL	3

/**
 * Pushes up to two nodes from 'stack_a' to 'stack_b'.
 * @param	stacks	A pointer to stacks.
 */
void	push_up_to_two(struct s_stacks *stacks);

/**
 * Find the node with the closest smaller number to 'nb'.
 * @param	lst		List to look for such a node in.
 * @param	nb		Number.
 * @return	Found node;
 * 			if no nodes in 'lst' have values less than 'nb', NULL is returned.
 */
t_list	*find_closest_smaller(t_list *lst, int nb);

/**
 * Returns the node with maximum number stored in 'lst'.
 * @param	lst	A list.
 * @return	Node with the maximum number;
 * 			if there are multiple such nodes, the first one is returned.
 */
t_list	*find_max(t_list *lst);

/**
 * Find the node with the closest bigger number to 'nb'.
 * @param	lst		List to look for such a node in.
 * @param	nb		Number.
 * @return	Found node;
 * 			if no nodes in 'lst' have values more than 'nb', NULL is returned.
 */
t_list	*find_closest_bigger(t_list *lst, int nb);

/**
 * Returns the node with minimum number stored in 'lst'.
 * @param	lst	A list.
 * @return	Node with the minimum number;
 * 			if there are multiple such nodes, the first one is returned.
 */
t_list	*find_min(t_list *lst);

/**
 * Calculates node position in stack.
 * @param	stack	A stack.
 * @param	node	A node in stack.
 * @return	(-1), if node isn't present in stack;
 * 			nodes position in stack otherwise.
 */
int		calculate_node_position_in_stack(t_list *stack, t_list *node);

/**
 * Calculates, how many operations are required to put 'node'
 * on top of 'stack'.
 * @param	stack	Some stack.
 * @param	node	You guessed it! Some node!!
 * @return	Amount of operations needed to put 'node' on top of 'stack'.
 * 			Negative means reverse rotate, positive means rotate.
 */
int		count_operations_to_move_on_top(t_list *stack, t_list *node);

/**
 * Calculates, how many operations are required to put 'node_a'
 * to top of 'stacks->stack_a', and 'node_b' to top of 'stacks->stack_b'.
 * @param	stacks	Structure containing both stacks.
 * @param	node_a	Element in 'stack_a', that we want to put
 * 					on top of 'stack_a';
 * @param	node_b	Element in 'stack_b', that we want to put
 * 					on stop of 'stack_b'.
 */
size_t	cost_analysis(struct s_stacks *stacks,
			t_list *node_a, t_list *node_b);

/**
 * For first stage of moving in Turk Algorithm.
 * @param	stacks	Stacks.
 * @param	from_a	It will point to a best node to move in 'stacks->stack_a'.
 * @param	to_b	It will point to a target node of 'from_a' in stack_b.
 */
void	find_best_node_to_b(struct s_stacks *stacks,
			t_list **from_a, t_list **to_b);

/**
 * Moves elements from 'stack_a' to 'stack_b' in a sorted way,
 * while ft_lstsize(stack_a) > TURK_ALGORITHM_MOVE_FROM_A_UNTIL.
 */
void	move_from_a_to_b(struct s_stacks *stacks);

/**
 * When the first stage of Turk Algorithm is done, sort the three elements
 * remaining in 'stacks->stack_a'.
 * @param	stacks	Stacks.
 */
void	sort_three(struct s_stacks *stacks);

/**
 * For the third stage of moving in Turk Algorithm.
 * @param	stacks	Stacks.
 * @param	from_b	It will point to a best node to move in 'stacks->stack_b'.
 * @param	to_b	It will point to a target node of 'from_b' in stack_a.
 */
void	find_best_node_to_a(struct s_stacks *stacks,
			t_list **from_b, t_list **to_a);

/**
 * Moves elements from 'stack_b' to 'stack_a' in a sorted way.
 * Third stage of Turk Algorithm.
 * @param	stacks	Stacks.
 */
void	move_from_b_to_a(struct s_stacks *stacks);

/**
 * Move the minimal element of 'stacks->stack_a' to top of 'stacks->stack_a'.
 * @param	stacks	Stacks.
 */
void	final_sort_a(struct s_stacks *stacks);

#endif	/* ALGORITHM_H */
