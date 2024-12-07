class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo =1; int hi = *max_element(nums.begin(), nums.end());
        int mini = INT_MAX;
        int n = nums.size();
        while(lo<=hi){
            int k = lo + (hi-lo)/2;
            int ops = 0;
            for(int i=0; i<n; i++){
                ops += (nums[i]-1)/k;
            }
            if(ops<=maxOperations){
                mini = min(mini, k);
                hi = k-1;
            }
            else{
                lo = k+1;
            }
        }
        return mini;
    }
};

/*

    1 operation ceil(x/2);
    2 operations ceil (x/3);

    mininum = ceil(x/ops+1) 
    ops+1 = x/minimum


*/