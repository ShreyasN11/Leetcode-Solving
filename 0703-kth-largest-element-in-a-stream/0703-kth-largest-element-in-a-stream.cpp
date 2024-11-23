class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        int n =k; int i=0;
        kk = k;
        sort(nums.rbegin(),nums.rend()); 
        while(n && i<nums.size()){
            pq.push(nums[i]); n--; i++;
        }
    }
    
    int add(int val) {
        if(pq.empty() || pq.size()< kk){
            pq.push(val);
            return pq.top();
        }
        else if(val > pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */