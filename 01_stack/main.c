#include "stack.h"

#include <stdio.h>
void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		printf("[id: %d, current: %p, data->n: %d , top: %p, bottom: %p]\n", current->id, current, ((t_data *)current->data)->n, current->top, current->bottom);
		current = current->next;
	}	
}

int	main()
{
	t_stack	*stack;
	//t_stack *popped;

	stack = NULL;
	push(&stack, (void *)(&((t_data){0})));
	push(&stack, (void *)(&((t_data){1})));
	push(&stack, (void *)(&((t_data){2})));
	push(&stack, (void *)(&((t_data){3})));
	push(&stack, (void *)(&((t_data){4})));
	//popped = pop(&stack);
	print_stack(stack);
	//printf("{%d}", ((t_data *)popped->data)->n);
	free_stack(&stack, 0);
	return (0);
}
