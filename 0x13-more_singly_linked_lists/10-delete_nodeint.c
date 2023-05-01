/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t linked list.
 * @head: pointer to pointer to the head node of the list
 * @index: index of the node to be deleted
 *
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *prev, *curr;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		curr = *head;
		*head = (*head)->next;
		free(curr);
		return (1);
	}

	prev = *head;
	curr = (*head)->next;

	for (i = 1; curr != NULL && i < index; i++)
	{
		prev = curr;
		curr = curr->next;
	}

	if (curr == NULL)
		return (-1);

	prev->next = curr->next;
	free(curr);

	return (1);
}
