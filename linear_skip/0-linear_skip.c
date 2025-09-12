#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer to the node containing the value, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express;

	if (list == NULL)
		return (NULL);

	express = list->express;
	if (express != NULL)
		printf("Value checked at index [%lu] = [%d]\n",
			express->index, express->n);

	while (express != NULL && express->n < value)
	{
		list = express;
		express = express->express;

		if (express == NULL)
			break;

		printf("Value checked at index [%lu] = [%d]\n",
			express->index, express->n);
	}

	if (express == NULL)
	{
		express = list;
		while (express->next != NULL)
			express = express->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		list->index, express->index);

	while (list != NULL && list->n <= express->n)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			list->index, list->n);

		if (list->n == value)
			return (list);

		list = list->next;
	}

	return (NULL);
}
