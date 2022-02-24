/*


Given the head of a linked list, return the list after sorting it in ascending order.



*/





struct cmp
{
   bool operator()( const ListNode* a, const ListNode* b ) const 
   {
    return a->val > b->val;
   }
};


class Solution {
public:
    
    
    
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return NULL;
        priority_queue<ListNode*,vector<ListNode*>,cmp>  q;
        ListNode* ptr = head;
        while(ptr!=NULL){
            q.push(ptr);
            ptr = ptr->next;
        }
        ListNode* dummy = new ListNode(-1);
        ptr = dummy;
        
        while(!q.empty()){
            
            ListNode* curr = q.top();
           
            q.pop();
            ptr->next = curr;
            //cout<<ptr->val<<endl;
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return dummy->next;
    }
};
