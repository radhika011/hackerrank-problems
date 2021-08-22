int binSearch(long start,long end){
    if(start<end){
        long mid  = (start+end)/2;
        if(isBadVersion(mid)==true){
            long next = binSearch(start,mid);
            if(next<mid&&next!=-1){
                return next;
            }
            return mid;
        }
        else{
            return binSearch(mid+1,end);
        }
    }
    else if(start==end){
        return start;
    }
    return -1;
}




class Solution {
public:
    int firstBadVersion(int n) {
       
        int ans = binSearch(1,n);
        return ans;
    }
};
