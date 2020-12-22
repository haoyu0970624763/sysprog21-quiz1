node_t *recursive_reverse(node_t *head)
{
    //當list為空或list遞迴到只剩一個的時候 即回傳
    if(!head || !head->next){
        return head;
    }
    node_t *recursive_head = recursive_reverse(head->next);//recursive_head 被初始化為list的尾巴(後面一直沒有更新過)
    (head->next)->next = head; // a->b->c->d  變成 a->b->c->d->c
    head->next = NULL;// 將原本的list變為 a->b->c  和 d->c
    return recursive_head; // 保留d的位址
}
void reverse(node_t **head)
{
    *head = recursive_reverse(*head);
}
