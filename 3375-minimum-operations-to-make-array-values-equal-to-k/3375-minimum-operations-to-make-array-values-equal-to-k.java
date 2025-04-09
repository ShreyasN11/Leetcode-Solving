class Solution {
    public int minOperations(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int ops = 0; int i=0;
        while(i<n){
            if(nums[i] < k) return -1;
            if(nums[i] == k){
                i++; continue;
            } 
            int j=i; ops++;
            while(j<n && nums[j] == nums[i]){
                j++;
            }
            i=j;
        }
        return ops;
    }
}