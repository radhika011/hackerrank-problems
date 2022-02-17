
/*

Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.





*/





class Node{
    public:
    int val;
    Node* next;
    Node(){
        val = -1;
        next = NULL;
    }
    Node(int val){
        this->val = val;
        next = NULL;
    }
    
};



class MyLinkedList {
public:
    Node* head;
    int n;
    MyLinkedList() {
        head = NULL;
        n = 0;
    }
    
    int get(int index) {
        if(index>=n) return -1;
        Node* ptr = head;
        for(int i = 0;i<index;i++){
            ptr = ptr->next;
        }
        return ptr->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        n++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        Node* ptr = head;
        if(head==NULL){
            head = newNode;
            n++;
            return;
        }
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        n++;
    }
    
    void addAtIndex(int index, int val) {
        Node* newNode = new Node(val);
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==n){
            addAtTail(val);
            return;
        }
        if(index>n) return;
        Node* ptr = head;
        for(int i = 0;i<index-1;i++){
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
        n++;
        
    }
    
    void deleteAtIndex(int index) {
        if(index>=n) return;
         n--;
        if(index==0){
            head = head->next;
            return;
        }
        Node* ptr = head;
        Node* prev_ptr = head;
        for(int i =0;i<index;i++){
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = ptr->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
