/*
Basically keep track of max element in the stack in O(1) time

*/



vector<int> getMax(vector<string> operations) {
    stack<StackNode*> st;
    vector<int> ans;
    int currMax = INT_MIN;
    StackNode* curr = NULL;
    for(int i =0;i<operations.size();i++){
        if(operations[i][0]=='1'){
            int number = stoi(operations[i].substr(2));
            StackNode* newNode = new StackNode(number);
            if(number>currMax){
                //cout<<"max changes:"<<number<<endl;
                currMax = number;
                newNode->prevMax = curr;
                curr = newNode;
            }
            st.push(newNode);
        }
        else if(operations[i][0]=='2'){
          /* StackNode* temp = st.top();
            cout<<"Top:"<<temp->val<<endl;*/
            if(st.top()==curr){
                curr = curr->prevMax;
                if(curr!=NULL) {
                    currMax = curr->val;
                }
                else currMax = INT_MIN;
            }
            
            st.pop();
        }
        
        else{
            ans.push_back(curr->val);
            //cout<<curr->val<<endl;
        }
        
    }
    return ans;
}
