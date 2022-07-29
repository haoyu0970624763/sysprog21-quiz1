typedef struct __node {
  int value;
  struct __node *next;
} node_t;

void swap_pair(node_t **head) {
  for (node_t **node = head; *node && (*node)->next;
       node = &(*node)->next->next) {
    node_t *tmp = *node;
    *node = (*node)->next;
    tmp->next = (*node)->next;
    (*node)->next = tmp;
  }
}
