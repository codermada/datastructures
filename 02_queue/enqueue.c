/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:53:36 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 10:57:53 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

static int	new_queue(t_queue **queue, int id, void *data)
{
	*queue = malloc(sizeof(t_queue));
	if (!(*queue))
		return (0);
	(*queue)->id = id;
	(*queue)->data = data;
	(*queue)->top = *queue;
	(*queue)->bottom = *queue;
	(*queue)->prev = NULL;
	(*queue)->next = NULL;
	return (1);
}

int	enqueue(t_queue **queue, void *data)
{
	t_queue	*last;
	t_queue	*new;

	if (*queue == NULL)
	{
		if (!new_queue(queue, 0, data))
			return (0);
	}
	else
	{
		last = *queue;
		while (last->next)
			last = last->next;
		if (!new_queue(&new, last->id + 1, data))
			return (0);
		(*queue)->top = new;
		new->bottom = *queue;
		new->prev = last;
		last->next = new;
	}
	return (1);
}
