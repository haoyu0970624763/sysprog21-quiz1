#include <stdio.h>

void shuffle(node_t **head)
{
    srand(time(NULL));
    
    /* Trace the length of the linked list */
    int len = 0;
    node_t **indirect = head;
    while (*indirect) {
        len++;
        indirect = &(*indirect)->next;
    }   

    /* Append shuffling result to another linked list */
    node_t *new = NULL;
    node_t **new_head = &new;
    node_t **new_tail = &new;

    while (len) {
        int random = rand() % len;
        indirect = head;

        while (random--)
            indirect = &(*indirect)->next;

        /* tmp means the node we randomly chosen */
        node_t *tmp = *indirect;
        /* Shift the element behind tmp to the position of tmp */
        *indirect = (*indirect)->next;
        /* put the node we chosen to the tail of new list */
        tmp->next = NULL;

        if (new) {
            (*new_tail)->next = tmp;
            new_tail = &(*new_tail)->next;
        } else {
            new = tmp; 
        }

        len--;
    }   

    *head = *new_head;
}
  