#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct __node {
  int value;
  struct __node *next;
} node_t;

void shuffle(node_t **head) {
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

  while (len) {
    int random = rand() % len;
    indirect = head;

    while (random--)
      indirect = &(*indirect)->next;

    /* tmp means the node we randomly chosen */
    node_t *tmp = *indirect;
    /* Shift the element behind tmp to the position of tmp */
    *indirect = (*indirect)->next;
    /* put the node we chosen to the head of new list */
    tmp->next = *new_head;

    *new_head = tmp;
    len--;
  }

  *head = *new_head;
}

void add_entry(node_t **head, int new_value) {
  node_t **indirect = head;

  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = new_value;
  new_node->next = NULL;

  /* AA1 = "assert(new_node)" */
  assert(new_node);
  while (*indirect)
    indirect = &(*indirect)->next;
  /* AA2 = "*indirect = new_node" */
  *indirect = new_node;
}

void print_list(node_t *head) {
  for (node_t *current = head; current; current = current->next)
    printf("%d ", current->value);
  printf("\n");
}

int main(int argc, char const *argv[]) {
  node_t *head = NULL;

  add_entry(&head, 72);
  add_entry(&head, 101);
  add_entry(&head, 108);
  add_entry(&head, 109);
  add_entry(&head, 110);
  add_entry(&head, 111);

  print_list(head);

  shuffle(&head);
  print_list(head);

  return 0;
}
