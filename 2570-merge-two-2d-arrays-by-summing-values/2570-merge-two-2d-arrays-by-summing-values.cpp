class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int>mp;
        for(auto it:nums1){
            int id = it[0];
            int val = it[1];
            if(mp.find(id) == mp.end()) mp[id] = val;
            else mp[id] += val;
        }
        for(auto it:nums2){
            int id = it[0];
            int val = it[1];
            if(mp.find(id) == mp.end()) mp[id] = val;
            else mp[id] += val;
        }
        vector<vector<int>> res;
        for(auto it: mp){
            res.push_back({it.first , it.second});
        }
        return res;
    }
};