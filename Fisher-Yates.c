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
