/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.


*/





class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>> q;
    KthLargest(int k, vector<int>& nums) {
        for(int i =0;i<nums.size()&&i<k;i++){
            q.push(nums[i]);
        }
        this->k = k;
        for(int i = k;i<nums.size();i++){
            q.push(nums[i]);
            if(q.size()>k) q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>k) q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
