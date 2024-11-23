/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asagymba <asagymba@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:01:02 by asagymba          #+#    #+#             */
/*   Updated: 2024/11/23 22:37:44 by asagymba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm.h>
#include <libft.h>
#include <stddef.h>
#include <stdint.h>

t_list	*find_min(t_list *lst)
{
	t_list	*ret;

	ret = lst;
	while (lst != NULL)
	{
		if ((int)((uintptr_t)(ret->content))
			> (int)((uintptr_t)(lst->content)))
			ret = lst;
		lst = lst->next;
	}
	return (ret);
}
