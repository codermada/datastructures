/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:53:36 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 11:22:01 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static int	new_list(t_list **list, int id, void *data)
{
	*list = malloc(sizeof(t_list));
	if (!(*list))
		return (0);
	(*list)->id = id;
	(*list)->data = data;
	(*list)->back = *list;
	(*list)->head = *list;
	(*list)->prev = NULL;
	(*list)->next = NULL;
	return (1);
}

int	list_append(t_list **list, void *data)
{
	t_list	*last;
	t_list	*new;

	if (*list == NULL)
	{
		if (!new_list(list, 0, data))
			return (0);
	}
	else
	{
		last = *list;
		while (last->next)
			last = last->next;
		if (!new_list(&new, last->id + 1, data))
			return (0);
		(*list)->back = new;
		new->head = *list;
		new->prev = last;
		last->next = new;
	}
	return (1);
}
