/*

Design a number container system that can do the following:

Insert or Replace a number at the given index in the system.
Return the smallest index for the given number in the system.
Implement the NumberContainers class:

NumberContainers() Initializes the number container system.
void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.




*/





class NumberContainers {
public:
    unordered_map<int,int> umap;
    
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>> heaper;
    
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        
        umap[index] = number;
        heaper[number].push(index);
    }
    
    int find(int number) {

        while(!heaper[number].empty()){
            //cout<<"hello"<<endl;
            int currIndex = heaper[number].top();
            if(umap[currIndex]==number) return currIndex;
            heaper[number].pop();
        }
        return -1;
    }
};
