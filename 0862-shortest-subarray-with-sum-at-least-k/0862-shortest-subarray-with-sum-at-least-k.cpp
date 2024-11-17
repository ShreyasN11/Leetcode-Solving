class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        long long n = nums.size();
        long long mini = LLONG_MAX;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long,long long>>> pq;
        pq.push({nums[0],0});
        if(nums[0] >= k) return 1;
        long long i=1;
        long long cursum = nums[0];
        while(i<n){
            cursum += (long long)nums[i];
            while(!pq.empty() && cursum - pq.top().first >= k){
                mini = min(mini,i-pq.top().second);
                pq.pop();
            }
            cout<<cursum<<" ";
            pq.push({cursum,i});
            if(cursum >= k){
                mini = min(mini,i+1);
            }
            i++;
        }

        if(mini != LLONG_MAX) return mini;
        else return -1;
    }
};