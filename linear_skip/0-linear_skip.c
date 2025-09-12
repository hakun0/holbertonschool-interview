#include "search.h"

/**
 * print_check - prints the index and value being checked
 * @node: pointer to the node
 */
static void print_check(skiplist_t *node)
{
	if (node != NULL)
		printf("Value checked at index [%lu] = [%d]\n",
			node->index, node->n);
}

/**
 * search_range - searches linearly in a range of skip list
 * @list: pointer to the start node
 * @end: pointer to the end node
 * @value: value to search for
 *
 * Return: pointer to the node if found, NULL otherwise
 */
static skiplist_t *search_range(skiplist_t *list,
		skiplist_t *end, int value)
{
	while (list != NULL && list->n <= end->n)
	{
		print_check(list);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}

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
	print_check(express);

	while (express != NULL && express->n < value)
	{
		list = express;
		express = express->express;
		if (express != NULL)
			print_check(express);
	}

	if (express == NULL)
	{
		express = list;
		while (express->next != NULL)
			express = express->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		list->index, express->index);

	return (search_range(list, express, value));
}
