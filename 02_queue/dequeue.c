/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:09:51 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 11:03:22 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue	*dequeue(t_queue **queue, int use_return, int free_data)
{
	t_queue	*old_bottom;
	t_queue	*new_bottom;

	old_bottom = *queue;
	new_bottom = NULL;
	if (*queue)
		new_bottom = (*queue)->next;
	*queue = new_bottom;
	if (old_bottom)
		old_bottom->next = NULL;
	if (use_return)
		return (old_bottom);
	else
	{
		free_queue(&old_bottom, free_data);
		return (NULL);
	}
}
