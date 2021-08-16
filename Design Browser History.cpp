class Node{
    public:
    string currURL;
    Node * next;
    Node* prev;
    
    
    Node(string currURL){
        this->currURL = currURL;
        next = NULL;
        prev = NULL;
    }
};



class BrowserHistory {
    Node * curr;
public:
    BrowserHistory(string homepage) {
        Node *newNode = new Node(homepage);
        curr = newNode;
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;
        newNode->prev = curr; 
        curr = newNode;
    }
    
    string back(int steps) {
        Node * ptr = curr;
        for(int i=0;i<steps;i++){
            
            if(ptr->prev==NULL){
                break;
            }
            ptr = ptr->prev;
            
        }
        curr = ptr;
        return curr->currURL;
    }
    
    string forward(int steps) {
        Node *ptr = curr;
        for(int i=0;i<steps;i++){
            if(ptr->next==NULL){
                break;
            }
            ptr = ptr->next;
            
        }
        curr = ptr;
        return curr->currURL;
    }
};
