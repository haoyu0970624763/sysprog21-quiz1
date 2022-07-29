#include "reverse.c"
typedef struct __node {
  int value;
  struct __node *next;
} node_t;

void recursive_reverse_step(node_t *curr, node_t *prev, node_t **head) {
  /* next represent the element behind the current element in the list
   * if next equal to NULL , then the element we traced is last in the list
   */
  node_t *next = curr->next;
  if (!next) {
    *head = curr;
    return;
  }
  /*  prev represent the previous recursive function parameter curr
   *  it should be linked behind the current element
   */
  curr->next = prev;

  recursive_rev_step(next, curr, head);
}

void recursive_reverse(node_t **head) {
  if (!head)
    return;

  recursive_reverse_step(*head, NULL, head);
}
