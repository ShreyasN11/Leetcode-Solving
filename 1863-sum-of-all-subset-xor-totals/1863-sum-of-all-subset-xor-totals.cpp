class Solution {
public:
    int backtrack(vector<int>& nums, int index, int cursum){
        if(index == nums.size()) return cursum;
        int notake = backtrack(nums, index+1, cursum);
        int take = backtrack(nums, index+1, nums[index]^cursum);
        return take + notake;
    }
    int subsetXORSum(vector<int>& nums) {
        return backtrack(nums, 0, 0);
    }
};