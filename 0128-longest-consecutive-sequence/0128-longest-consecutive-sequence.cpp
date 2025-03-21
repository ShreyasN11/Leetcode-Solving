class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_map<int,int>mp;
        sort(nums.begin(), nums.end());
        int maxi = 1;
        for(int i=0; i<n; i++){
            int x = nums[i];
            if(mp.find(x-1) != mp.end()){
                mp[x]=mp[x-1]+1;
                maxi = max(maxi,mp[x]);
            }
            else mp[x] = 1;
        }
        return maxi;
    }
};