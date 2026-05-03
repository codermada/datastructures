/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:53:47 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 09:56:15 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_stack(t_stack **stack, int free_data)
{
	t_stack	*current;

	while (*stack)
	{
		current = (*stack)->next;
		if (free_data)
		{
			if (current)
				free(current->data);
		}
		free(*stack);
		*stack = current;
	}
}
