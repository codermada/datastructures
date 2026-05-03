#include "dictionary.h"

#include <stdio.h>

void	print_dict(t_dict *dict)
{
	t_dict	*current;

	current = dict;
	while (current)
	{
		printf("key: %s, value: %s\n", (char *)current->key, (char *)current->value);
		current = current->next;
	}
}

int	cmp(void *ptr_1, void *ptr_2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = ptr_1;
	p2 = ptr_2;
	if (!p1 || !p2)
		return (-1);
	while (*p2 && *p1)
	{
		if (*p2 != *p1)
			return (1);
		p1++;
		p2++;
	}
	return (0);
}

int	main()
{
	t_dict	*dict;
	t_dict	*item;

	dict = NULL;
	dict_add(&dict, "1", "test1", cmp);
	dict_add(&dict, "2", "test2", cmp);
	dict_add(&dict, "3", "test3", cmp);
	item = get_item(dict, "1", cmp);
	item->value = "test4";
	print_dict(dict);
	printf("{%s}", (char *)item->value);
	free_dict(&dict, 0, 0);
	return (0);
}