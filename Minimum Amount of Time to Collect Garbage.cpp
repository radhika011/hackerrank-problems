/*
You are given a 0-indexed array of strings garbage where garbage[i] represents the assortment of garbage at the ith house. garbage[i] consists only of the characters 'M', 'P' and 'G' representing one unit of metal, paper and glass garbage respectively. Picking up one unit of any type of garbage takes 1 minute.

You are also given a 0-indexed integer array travel where travel[i] is the number of minutes needed to go from house i to house i + 1.

There are three garbage trucks in the city, each responsible for picking up one type of garbage. Each garbage truck starts at house 0 and must visit each house in order; however, they do not need to visit every house.

Only one garbage truck may be used at any given moment. While one truck is driving or picking up garbage, the other two trucks cannot do anything.

Return the minimum number of minutes needed to pick up all the garbage.






*/









class Solution {
public:
    
    
    
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int ans = 0;
        unordered_map<int,vector<int>> kinds;
        int mmax = -1;
        int gmax = -1;
        int pmax = -1;
        for(int i = 0;i<n;i++){
            vector<int> counts(3,0);
            for(int j = 0;j<garbage[i].size();j++){
                if(garbage[i][j]=='M') {
                    mmax = i;
                    counts[0]++;
                }
                if(garbage[i][j]=='P'){
                    pmax = i;
                    counts[1]++;
                } 
                if(garbage[i][j]=='G'){
                    gmax = i;
                    counts[2]++;
                }
            }
            kinds[i] = counts;
        }
        int m = 0;
        int p = 0;
        int g = 0;
        for(int i = 0;i<n;i++){
            if(i<=mmax){
                m+=kinds[i][0];
                if(i!=0) m+=travel[i-1];
            }
            if(i<=pmax){
                p+=kinds[i][1];
                if(i!=0) p+=travel[i-1];
            }
            if(i<=gmax){
                g+=kinds[i][2];
                if(i!=0) g+=travel[i-1];
            }
            
            //cout<<m<<" "<<p<<" "<<g<<endl;
        }
        return m+p+g;
        
    }
};
