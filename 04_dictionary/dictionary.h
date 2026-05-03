/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:14:33 by toloandr          #+#    #+#             */
/*   Updated: 2025/06/29 18:52:25 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include <stdlib.h>

typedef struct s_dict
{
	void			*key;
	void			*value;
	struct s_dict	*next;
}	t_dict;

int		dict_add(t_dict **dict, void *key, void *value, int cmp(void *, void *));
t_dict	*get_item(t_dict *dict, void *key, int cmp(void *, void *));
void	free_dict(t_dict **dict, int free_key, int free_value);

#endif