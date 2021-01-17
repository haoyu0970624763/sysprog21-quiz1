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

    print_list(head);

    node_t *entry = find_entry(head, 101);
    remove_entry(&head, entry);

    entry = find_entry(head, 111);
    remove_entry(&head, entry);

    print_list(head);

    swap_pair(&head);
    print_list(head);

    reverse(&head);
    print_list(head);

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

    node_t *org_head=*head , *current=*head;
    int length=0;
    int randNum;
    int count;
    while (current)
    {
        current=current->next;
        length+=1;
    }
    // length為list的長度
    *head=NULL;
    for(int i=0; i < length ; i++){
        randNum=rand()%(length-i)+1;
        count=1;
        current=org_head;
        if(randNum==1){ 
            org_head=org_head->next;
            current->next=(*head);
            *head =current;
            continue;
        }
        else
        {
            while (current)
            {
                if(count+1==randNum){
                    node_t *tmp=current->next;
                    current->next=current->next->next;
                    tmp->next=(*head);
                    *head=tmp;
                    break;
                }
                else
                {
                    count+=1;
                    current= current->next;
                } 
            }
        }
    }
}
