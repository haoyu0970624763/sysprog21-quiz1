void *reverse(node_t **head)
{
    node_t *cursor = NULL;
    while (*head) {
        node_t *next = (*head)->next;
        (*head)->next = cursor; cursor = *head;
        (*head) = next;
    }
    *head=cursor;
}
