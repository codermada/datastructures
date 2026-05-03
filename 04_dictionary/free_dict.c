/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:49:17 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 18:52:15 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"

void	free_dict(t_dict **dict, int free_key, int free_value)
{
	t_dict	*tmp;

	while (*dict)
	{
		tmp = (*dict)->next;
		if (free_key)
			free((*dict)->key);
		if (free_value)
			free((*dict)->value);
		free(*dict);
		*dict = tmp;
	}
}
