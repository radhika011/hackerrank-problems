
/*

Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.



*/





class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode(-10000);
       
        ListNode* ptr = head;
        while(ptr!=NULL){
            ListNode* newNode = new ListNode(ptr->val);
             ListNode* newPtr = newHead;
            ListNode* prev = newHead;
            while(newPtr!=NULL){
                if(newPtr->val>newNode->val){
                    newNode->next = prev->next;
                    prev->next = newNode;
                    break;
                }
                prev = newPtr;
                newPtr = newPtr->next;
            }
            if(newPtr==NULL){
                prev->next = newNode;
            }
            ptr = ptr->next;
        }
        newHead = newHead->next;
        return newHead;
        
    }
};
