//Naive: O(n)
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Queue{
    public:
    stack<int> st;
    stack<int> temp;
    Queue(){
        
    }
    void enqueue(int element){
        while(!st.empty()){
            int curr = st.top();
            st.pop();
            temp.push(curr);
        }
        st.push(element);
        while(!temp.empty()){
            int curr = temp.top();
            temp.pop();
            st.push(curr);
        }
    }
    void dequeue(){
       if(!st.empty()) st.pop();
    }
    int getFront(){
        return st.top();
    }
    
    
    
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin>>q;
    Queue *newQueue = new Queue();
    while(q--){
        int query;
        cin>>query;
        if(query==1){
            int element;
            cin>>element;
            newQueue->enqueue(element);
        }
        else if(query==2){
            newQueue->dequeue();
        }
        else if(query==3){
            cout<<newQueue->getFront()<<endl;
        }
    }
    
    
    
    return 0;
}
//Amortized O(1)
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Queue{
    public:
    stack<int> st;
    stack<int> temp;
    int front;
    Queue(){
        front = -1;
    }
    void enqueue(int element){
        if(st.empty()) {
            front = element;
        }
        st.push(element);
    }
    void dequeue(){
           if(temp.empty()){
               while(!st.empty()){
                   int curr = st.top();
                   st.pop();
                   temp.push(curr);
               }
           }
           temp.pop();
       }
    
    int getFront(){
        if(!temp.empty()) return temp.top();
        return front;
    }
    
    
    
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q;
    cin>>q;
    Queue *newQueue = new Queue();
    while(q--){
        int query;
        cin>>query;
        if(query==1){
            int element;
            cin>>element;
            newQueue->enqueue(element);
        }
        else if(query==2){
            newQueue->dequeue();
        }
        else if(query==3){
          cout<<newQueue->getFront()<<endl;
        }
    }
    
    
    
    return 0;
}
