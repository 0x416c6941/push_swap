/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_bigger.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:02:48 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:37:25 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm.h>
#include <libft.h>
#include <stddef.h>
#include <stdint.h>

t_list	*find_closest_bigger(t_list *lst, int nb)
{
	t_list	*ret;

	ret = NULL;
	while (lst != NULL)
	{
		if ((int)((uintptr_t)(lst->content)) > nb
			&& (ret == NULL
				|| (int)((uintptr_t)(ret->content))
					> (int)((uintptr_t)(lst->content))))
			ret = lst;
		lst = lst->next;
	}
	return (ret);
}
