class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int>res;
        for(int i=0; i<k; i++){
            while(!dq.empty() && dq.front().first < nums[i]){
                dq.pop_front();
            }
            dq.push_front({nums[i],i});
        }
        res.push_back(dq.back().first);
        //for(auto it: dq) cout<<it.first<<" "<<it.second<<" ";
        int i=k;
        while(i<nums.size()){
            int in = nums[i];
            int out = dq.back().first;
            int outindex = dq.back().second;
            if(i-outindex >= k) dq.pop_back();
            while(!dq.empty() && dq.front().first < nums[i]){
                dq.pop_front();
            }
            dq.push_front({nums[i],i});
            res.push_back(dq.back().first);
            i++;
        }

        return res;;
    }
};