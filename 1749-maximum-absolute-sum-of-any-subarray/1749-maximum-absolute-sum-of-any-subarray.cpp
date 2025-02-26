class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0; int cursum = 0;
        int mini = 0; int cursum2 = 0;
        for(int i=0; i<n; i++){
            cursum+=nums[i];
            if(cursum<0){
                cursum=0;
            }
            else{
                maxi = max(maxi,cursum);
            }
            cursum2+=nums[i];
            if(cursum2>0){
                cursum2=0;
            }
            else{
                mini=min(mini,cursum2);
            }
        }

        return max(maxi,abs(mini));

    }
};