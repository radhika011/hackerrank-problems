/*


Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.




*/













bool findPair(int arr[], int size, int n){
    //code
    unordered_set<int> done;
    for(int i = 0;i<size;i++){
        if(done.find(arr[i])!=done.end()) return true;
        done.insert(arr[i]-n);
        done.insert(arr[i]+n);
    }
    return false;
    
}
