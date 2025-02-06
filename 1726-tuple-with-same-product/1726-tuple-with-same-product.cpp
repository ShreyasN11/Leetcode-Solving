class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i!=j){
                    mp[nums[i]*nums[j]]++;
                }
            }
        }

        int res = 0;

        for(auto it: mp){
            if(it.second>1){
                int x = it.second;
                res += 8*(x-1)*x/2;
            }
        }
        return res;
    }
};