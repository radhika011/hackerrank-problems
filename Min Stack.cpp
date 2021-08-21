class Node{
    public:
    int val;
    Node *next;
    Node *prevMin;
    Node(int val){
        this->val = val;
        next = NULL;
        prevMin = NULL;
    }
};


class MinStack {
public:
    /** initialize your data structure here. */
    Node* top1;
    Node* min;
    MinStack() {
       top1 = NULL;
        min = NULL;
    }
    
    void push(int val) {
        Node* newNode = new Node(val);
       if(top1==NULL){
           top1 = newNode;
           min = newNode;
           return;
       }
        newNode->next = top1;
        top1 = newNode;
        if(newNode->val<min->val){
            newNode->prevMin = min;
            min = newNode;
        }
    }
    
    void pop() {
        if(min==top1){
            min = top1->prevMin;
            top1 = top1->next;
            return;
        }
        
        top1 = top1->next;
    }
    
    int top() {
        return top1->val;
    }
    
    int getMin() {
        return min->val;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
