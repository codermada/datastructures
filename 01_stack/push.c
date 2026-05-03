/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:53:36 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 10:10:30 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	new_stack(t_stack **stack, int id, void *data)
{
	*stack = malloc(sizeof(t_stack));
	if (!(*stack))
		return (0);
	(*stack)->id = id;
	(*stack)->data = data;
	(*stack)->top = *stack;
	(*stack)->bottom = *stack;
	(*stack)->prev = NULL;
	(*stack)->next = NULL;
	return (1);
}

int	push(t_stack **stack, void *data)
{
	t_stack	*last;
	t_stack	*new;

	if (*stack == NULL)
	{
		if (!new_stack(stack, 0, data))
			return (0);
	}
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		if (!new_stack(&new, last->id + 1, data))
			return (0);
		(*stack)->top = new;
		new->bottom = *stack;
		new->prev = last;
		last->next = new;
	}
	return (1);
}
