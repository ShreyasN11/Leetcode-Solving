class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto it: gifts){
            pq.push(it);
            sum+= (long long)it;
        }
        while(k){
            int x = pq.top(); pq.pop();
            int y = sqrt(x);
            sum -= (long long)(x-y);
            pq.push(y);
            k--;
        }
        return (int)sum;
    }
};