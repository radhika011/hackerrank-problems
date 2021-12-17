
/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
HEAP


*/



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i = 0;i<lists.size();i++){
            ListNode* ptr = lists[i];
            while(ptr!=NULL){
                q.push(ptr->val);
                ptr = ptr->next;
            }
            
            
        }
        ListNode* newHead = new ListNode(-1);
        ListNode* ptr = newHead;
        while(!q.empty()){
            
            ListNode* newNode = new ListNode(q.top());
            q.pop();
            ptr->next = newNode;
            ptr = newNode;
        }
        newHead = newHead->next;
        return newHead;
    }
};
