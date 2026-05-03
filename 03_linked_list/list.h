/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 08:50:14 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 10:11:58 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

// # include <stdio.h>

typedef struct s_list
{
	int				id;
	void			*data;
	struct s_list	*back;
	struct s_list	*head;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int	n;
}	t_data;

int		list_append(t_list **list, void *data); // append
t_list	*remove_back(t_list **list, int use_return, int free_data); // remove and return back
t_list	*remove_head(t_list **list, int use_return, int free_data);
void	free_list(t_list **list, int free_data);

#endif
