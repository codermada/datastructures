/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:53:47 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 10:44:36 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	free_queue(t_queue **queue, int free_data)
{
	t_queue	*current;

	while (*queue)
	{
		current = (*queue)->next;
		if (free_data)
		{
			if (current)
				free(current->data);
		}
		free(*queue);
		*queue = current;
	}
}
