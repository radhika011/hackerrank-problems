/*
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.




*/





class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* newHead = dummy;
        int currSum = 0;
        ListNode* ptr = head;
        ListNode* newPtr = newHead;
        while(ptr!=NULL){
            if(ptr->val==0){
                ListNode* newSum = new ListNode(currSum);
                newPtr->next = newSum;
                newPtr = newPtr->next;
                currSum = 0;
            }
            else{
                currSum+=ptr->val;
            }
            ptr = ptr->next;
        }
        return newHead->next->next;
    }
};
