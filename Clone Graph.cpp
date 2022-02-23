
/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.




*/




class Solution {
    unordered_map<int,vector<int>> adjList;
    unordered_map<int,Node*> graph;
    set<int> visited;
public:
    void dfs(Node* curr){
        if(curr==NULL) return;
         if(visited.find(curr->val)!=visited.end()) return; 
         vector<Node*> neighbors = curr->neighbors;
         visited.insert(curr->val);
         for(int i = 0;i<neighbors.size();i++){
             adjList[curr->val].push_back(neighbors[i]->val);
             dfs(neighbors[i]);
         }
    }
    
    
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        dfs(node);
        
        int s = node->val;
        Node *newNode = new Node(s);
        graph[s] = newNode;
        queue<int> q;
        q.push(s);
        visited.clear();
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(visited.find(curr)!=visited.end()) continue;
            Node* temp = NULL;
            if(graph.find(curr)==graph.end()){
                temp = new Node(curr);
                graph[curr] = temp;
            }
            else{
                temp = graph[curr];
            }
            vector<int> ns = adjList[curr];
            vector<Node*> tt;
            for(int i = 0;i<ns.size();i++){
                if(graph.find(ns[i])==graph.end()){
                    Node* newNode = new Node(ns[i]);
                    graph[ns[i]] = newNode;
                }
                q.push(ns[i]);
                tt.push_back(graph[ns[i]]);
            }
            temp->neighbors = tt;
            visited.insert(curr);
             //cout<<temp->neighbors.size()<<endl;
        }
       
        return newNode;
        
    }
};
