#include "shell.h"

/**
 * add_node - this will adds a node to the start of the
 * in the program given list
 * @head: This is an address of pointer to head the node
 * to be returned.
 * @str: This is a string to the field of node
 * @num: This is a node index used by history in the program.
 * Return: This will give the size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *nhead;

	if (!head)
		return (NULL);
	nhead = malloc(sizeof(list_t));
	if (!nhead)
		return (NULL);
	_memset((void *)nhead, 0, sizeof(list_t));
	nhead->num = num;
	if (str)
	{
		nhead->str = _strdup(str);
		if (!nhead->str)
		{
			free(nhead);
			return (NULL);
		}
	}
	nhead->next = *head;
	*head = nhead;
	return (nhead);
}

/**
 * add_node_end - This will adds a node to the end of
 * in the list in the codes.
 * @head: This is an address of pointer to head node in the
 * codes and point to the nest one.
 * @str: This is the string  field of node to be returned.
 * @num: This is a node index used by history of the shell.
 * Return: This will returned size of list present in the codes.
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *nnode, *node;

	if (!head)
		return (NULL);

	node = *head;
	nnode = malloc(sizeof(list_t));
	if (!nnode)
		return (NULL);
	_memset((void *)nnode, 0, sizeof(list_t));
	nnode->num = num;
	if (str)
	{
		nnode->str = _strdup(str);
		if (!nnode->str)
		{
			free(nnode);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = nnode;
	}
	else
		*head = nnode;
	return (nnode);
}

/**
 * print_list_str - this to print only the string elements of
 * a list_t linked list present in the codes.
 * @h: This is a pointer to first node present in the codes.
 * Return: This will always returned the size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t pp = 0;

	do {
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		pp++;
	} while (h);

	return (pp);
}

/**
 * delete_node_at_index - This will delete node at given index
 * of the codes in the program.
 * @head: This is an address of pointer to first node present in the
 * codes.
 * @index: This is an index of node to be deleted in a
 * given nodes.
 * Return: on success, 1 is returned and  0 when fails.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *preNode;
	unsigned int pp = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	do {
		if (pp == index)
		{
			preNode->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		pp++;
		preNode = node;
		node = node->next;
	} while (node);

	return (0);
}

/**
 * free_list - This will free all nodes of a given list
 * in the program.
 * @head_ptr: This is an address of pointer to head node
 * which points to the next program in the file or codes present.
 * Return: void NUll or nothing.
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *nNode, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		nNode = node->next;
		free(node->str);
		free(node);
		node = nNode;
	}
	*head_ptr = NULL;
}
