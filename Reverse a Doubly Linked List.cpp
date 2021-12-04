/*
Given the pointer to the head node of a doubly linked list, reverse the order of the nodes in place. That is, change the next and prev pointers of the nodes so that the direction of the list is reversed. Return a reference to the head node of the reversed list.

Note: The head node might be NULL to indicate that the list is empty.

*/




DoublyLinkedListNode *head = list;
    DoublyLinkedListNode *end = head;
    while(end->next!=NULL) end = end->next;
    DoublyLinkedListNode *curr = end;
    while(curr!=NULL){
        DoublyLinkedListNode *temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->next;
    }
    return end;
