/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:19:33 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 18:36:53 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

int	new_item(t_dict **dict_node, void *key, void *value)
{
	*dict_node = malloc(sizeof(t_dict));
	if (*dict_node == NULL)
		return (0);
	(*dict_node)->key = key;
	(*dict_node)->value = value;
	(*dict_node)->next = NULL;
	return (1);
}

int	dict_add(t_dict **dict, void *key, void *value, int cmp(void *, void *))
{
	t_dict	*last;
	t_dict	*new;

	if (*dict == NULL)
	{
		if (!new_item(dict, key, value))
			return (0);
	}
	else
	{
		last = *dict;
		while (last->next)
		{
			if (cmp(last->key, key) == 0)
				return (-1);
			last = last->next;
		}
		if (cmp(last->key, key) == 0)
			return (-1);
		if (!new_item(&new, key, value))
			return (0);
		last->next = new;
	}
	return (1);
}
