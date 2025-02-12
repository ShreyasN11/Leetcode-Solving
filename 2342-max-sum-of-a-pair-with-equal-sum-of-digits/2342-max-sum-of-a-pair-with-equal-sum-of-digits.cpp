class Solution {
public:
    int sum(int num){
        int res=0;
        while(num){
            res+= num%10;
            num/=10;
        }
        return res;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<int,pair<int,int>>mp;
        int res = -1;
        for(int i=0; i<n; i++){
            int digits = sum(nums[i]);
            if(mp.find(digits) == mp.end()) mp[digits] = {nums[i],-1};
            else{
                int max1 = mp[digits].first;
                int max2 = mp[digits].second;
                if (nums[i] > max1){
                    mp[digits].first = max1; 
                    mp[digits].second = nums[i];  
                } 
                else if(nums[i] > max2){
                    mp[digits].second = nums[i]; 
                }
            }
        }
        for(auto it: mp){
            int x = it.second.first; int y = it.second.second;
            if(x!= -1 && y!= -1){
                res= max(res, x+y);
            }
        }
        return res;

    }
};