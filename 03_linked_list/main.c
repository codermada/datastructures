#include "list.h"

#include <stdio.h>
void print_list(t_list *list)
{
	t_list *current;

	current = list;
	while (current)
	{
		printf("[id: %d, current: %p, data->n: %d , back: %p, head: %p]\n", current->id, current, ((t_data *)current->data)->n, current->back, current->head);
		current = current->next;
	}
}

int main()
{
	t_list *list;
	t_list *back;
	t_list *head;

	list = NULL;
	list_append(&list, (void *)(&((t_data){0})));
	list_append(&list, (void *)(&((t_data){1})));
	list_append(&list, (void *)(&((t_data){2})));
	// back = remove_back(&list, 1, 0);
	back = remove_back(&list, 0, 0);
	head = remove_head(&list, 1, 0);
	print_list(list);

	free_list(&list, 0);
	// free_list(&back, 0);
	free_list(&head, 0);
	return (0);
}
