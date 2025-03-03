class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int g = 0; int s = 0; int eq = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > pivot) g++;
            else if(nums[i] < pivot) s++;
            else eq++;
        }
        int lo = 0; int mid = s; int hi = s+eq;
        vector<int>res(n,0);
        for(int i=0; i<n; i++){
            if(nums[i] > pivot) res[hi++] = nums[i];
            else if(nums[i] < pivot) res[lo++] = nums[i];
            else res[mid++] = nums[i]; 
        }
        return res;
    }
};