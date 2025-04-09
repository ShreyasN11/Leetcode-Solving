class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double maxi = 0;
        int n = nums.length;
        double sum = 0.0;
        for(int i=0; i<k; i++){
            sum+=nums[i];
        }
        maxi = sum;
        for(int i=k; i<n; i++){
            sum += nums[i]; sum-=nums[i-k];
            maxi = Math.max(maxi,sum);
        }
        return maxi/k;
    }
}