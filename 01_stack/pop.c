/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:09:51 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 09:13:56 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*pop(t_stack **stack)
{
	t_stack	*new_top;
	t_stack	*last;

	last = *stack;
	while (last->next)
		last = last->next;
	if (last && last->prev)
		new_top = last->prev;
	new_top->next = NULL;
	return (last);
}
