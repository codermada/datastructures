/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:09:51 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 11:20:36 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*remove_back(t_list **list, int use_return, int free_data)
{
	t_list	*new_back;
	t_list	*last;

	last = *list;
	new_back = NULL;
	while (last->next)
		last = last->next;
	if (last && last->prev)
		new_back = last->prev;
	new_back->next = NULL;
	if (use_return)
		return (last);
	else
	{
		free_list(&last, free_data);
		return (NULL);
	}
}
