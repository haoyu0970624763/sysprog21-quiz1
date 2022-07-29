#include <stdio.h>

typedef struct __node {
  int value;
  struct __node *next;
} node_t;

void reverse(node_t **head) {
  node_t *cursor = NULL;
  while (*head) {
    node_t *next = (*head)->next;
    (*head)->next = cursor;
    cursor = *head;
    (*head) = next;
  }
  *head = cursor;
}
