#include "queue.h"

#include <stdio.h>
void print_queue(t_queue *queue)
{
	t_queue *current;

	current = queue;
	while (current)
	{
		printf("[id: %d, current: %p, data->n: %d , top: %p, bottom: %p]\n", current->id, current, ((t_data *)current->data)->n, current->top, current->bottom);
		current = current->next;
	}
}

int main()
{
	t_queue *queue;
	t_queue *dequeued;

	queue = NULL;
	enqueue(&queue, (void *)(&((t_data){0})));
	enqueue(&queue, (void *)(&((t_data){1})));
	enqueue(&queue, (void *)(&((t_data){2})));
	dequeue(&queue, 0, 0);
	// dequeued = dequeue(&queue, 1, 0);
	// printf("{%d}", dequeued->id);
	print_queue(queue);
	free_queue(&queue, 0);
	// free_queue(&dequeued, 0);
	return (0);
}
