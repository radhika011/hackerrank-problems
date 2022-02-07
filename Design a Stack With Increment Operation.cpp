/*

Design a stack which supports the following operations.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack or do nothing if the stack reached the maxSize.
void push(int x) Adds x to the top of the stack if the stack hasn't reached the maxSize.
int pop() Pops and returns the top of stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, just increment all the elements in the stack.

*/




class CustomStack {
public:
    vector<int> stack;
    int top;
    CustomStack(int maxSize) {
        //cout<<"done"<<endl;
        stack.resize(maxSize);
        top = 0;
    }
    
    void push(int x) {
        if(top==stack.size()) return;
        stack[top] = x;
        top++;
    }
    
    int pop() {
        if(top==0) return -1;
        --top;
        int popped = stack[top];
        stack[top] = 0;
        return popped;
    }
    
    void increment(int k, int val) {
        for(int i = 0;i<k&&i<stack.size();i++){
            if(stack[i]==0) return;
            stack[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
