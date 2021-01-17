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
