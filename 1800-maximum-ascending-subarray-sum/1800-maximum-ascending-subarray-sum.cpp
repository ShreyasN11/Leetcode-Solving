class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi  = nums[0];
        int cursum = nums[0];
        int i = 1;
        while(i<n){
            while(i<n && nums[i] > nums[i-1]){
                cursum += nums[i];
                i++;
            }
            maxi = max(maxi, cursum);
            if(i<n) cursum = nums[i];
            i++;            
        }
        return maxi;
    }
};