/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:50:14 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 10:11:58 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

// # include <stdio.h>

typedef struct s_stack
{
	int				id;
	void			*data;
	struct s_stack	*top;
	struct s_stack	*bottom;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	int	n;
}	t_data;

int		push(t_stack **stack, void *data); // append
t_stack	*pop(t_stack **stack); // remove and return end
void	free_stack(t_stack **stack, int free_data);

#endif
