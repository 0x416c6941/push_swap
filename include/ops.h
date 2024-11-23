/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:29:47 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:41:36 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
# define OPS_H

# include <solve.h>

/**
 * All available OPerations (sa, sb, ss, pa, pb, ...) are programmed here.
 * If something fails, (-1) is returned;
 * 	otherwise non-negative value is returned.
 * Please take a note, that the appropriate log, e.g. "sa\n", is also
 * 	written on STDOUT_FILENO (by using ft_printf()).
 */

int	op_sa(struct s_stacks *stacks);
int	op_sb(struct s_stacks *stacks);
int	op_ss(struct s_stacks *stacks);

int	op_pa(struct s_stacks *stacks);
int	op_pb(struct s_stacks *stacks);

int	op_ra(struct s_stacks *stacks);
int	op_rb(struct s_stacks *stacks);
int	op_rr(struct s_stacks *stacks);

int	op_rra(struct s_stacks *stacks);
int	op_rrb(struct s_stacks *stacks);
int	op_rrr(struct s_stacks *stacks);

#endif	/* OPS_H */
