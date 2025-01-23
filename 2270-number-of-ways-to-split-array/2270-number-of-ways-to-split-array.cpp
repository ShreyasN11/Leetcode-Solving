class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long r = accumulate(nums.begin(),nums.end(),0LL) - nums[0];
        long long l = nums[0];
        int count = 0;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(l>=r) count++;
            l += (long long)nums[i];
            r -= (long long)nums[i];
        }
        return count;
    }
};