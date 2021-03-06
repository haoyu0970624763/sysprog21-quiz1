#include<stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

typedef struct __node {
    int value;
    struct __node *next;
} node_t;

void add_entry(node_t **head, int new_value);
node_t *find_entry(node_t *head, int value);
void remove_entry(node_t **head, node_t *entry);

void *swap_pair(node_t **head);// use pointer to pointer to rewrite this function
void *reverse(node_t **head); // use pointer to pointer to rewrite this function

node_t *recursive_reverse(node_t *head);
void reverse_recur(node_t **head);
void print_list(node_t *head);

void random_sort(node_t **head);



int main(){

    node_t *head = NULL;

    print_list(head);

    add_entry(&head, 72);
    add_entry(&head, 101);
    add_entry(&head, 108);
    add_entry(&head, 109);
    add_entry(&head, 110);
    add_entry(&head, 111);
    add_entry(&head, 2);
    add_entry(&head, 1);
    add_entry(&head, 18);
    add_entry(&head, 19);
    add_entry(&head, 113);


    node_t *entry = find_entry(head, 101);
    remove_entry(&head, entry);

    entry = find_entry(head, 111);
    remove_entry(&head, entry);

    

    swap_pair(&head);

    reverse(&head);

    reverse_recur(&head);
    print_list(head);

    random_sort(&head);
    print_list(head);
    return 0;

}
void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = new_value;
    new_node->next = NULL;

    assert(new_node);
    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node;
}
node_t *find_entry(node_t *head, int value)
{
    node_t *current = head;
    for (; current && current->value != value; current = current->next)
        /* interate */;
    return current;
}
void remove_entry(node_t **head, node_t *entry)
{
    node_t **indirect = head;

    while ((*indirect) != entry)
        indirect = &(*indirect)->next;

    *indirect = entry->next;
    free(entry);
}
void *swap_pair(node_t **head)
{
    for (node_t **node = head; *node && (*node)->next; node = &(*node)->next->next) {
        node_t *tmp = *node;
        *node = (*node)->next;
        tmp->next = (*node)->next;
        (*node)->next = tmp;
    }
}
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
node_t *recursive_reverse(node_t *head)
{
    //當list為空或list遞迴到只剩一個的時候 即回傳
    if(!head || !head->next){
        return head;
    }
    node_t *recursive_head = recursive_reverse(head->next);//recursive_head 被初始化為list的尾巴(後面一直沒有更新過)
    (head->next)->next = head; // a->b->c->d  變成 a->b->c->d->c
    head->next = NULL;// 將原本的list變為 a->b->c  和 d->c
    return recursive_head;
}
void reverse_recur(node_t **head)
{
    *head = recursive_reverse(*head);
}
void print_list(node_t *head)
{
    for (node_t *current = head; current; current = current->next)
        printf("%d ", current->value);
    printf("\n");
}
void random_sort(node_t **head){

    srand(time(NULL));

    node_t *old_head=*head;
    node_t  **current=head;

    int length=0;
    // current here to count length of list
    while (*current)
    {
        current= &(*current)->next;
        length++;
    }
    // length為list的長度
    *head=NULL;
    
    for( ; length>0 ; length--){
        // current here to trace old head of list 
        current = &old_head;
        node_t *tmp;
        int index = rand() % length-1;
        if(index == -1){
            tmp=*current;
            if(tmp->next!=NULL)
                old_head=tmp->next;
            tmp->next = *head;
            *head = tmp;
        }
        else
        {
            for(; index > 0; index--)
                current= &(*current)->next;

            tmp = (*current)->next;
            if((*current)->next->next !=NULL)
                (*current)->next=(*current)->next->next;
            else
               (*current)->next=NULL;
            tmp->next = *head;
            *head = tmp;
        }
    }
}
