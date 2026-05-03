/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:50:14 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 10:59:38 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdlib.h>

// # include <stdio.h>

typedef struct s_queue
{
	int				id;
	void			*data;
	struct s_queue	*top;
	struct s_queue	*bottom;
	struct s_queue	*prev;
	struct s_queue	*next;
}	t_queue;

typedef struct s_data
{
	int	n;
}	t_data;

int		enqueue(t_queue **queue, void *data); // append
t_queue	*dequeue(t_queue **queue, int use_return, \
int free_data); // remove and return old top
void	free_queue(t_queue **queue, int free_data);

#endif
