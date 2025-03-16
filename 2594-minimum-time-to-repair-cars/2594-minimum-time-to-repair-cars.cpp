class Solution {
public:
    bool helper(vector<int>& ranks, long long ca, long long time){
        long long count = 0;
        for(auto it: ranks){
            count += sqrt(time/(long long)it);
        }
        return count>=ca;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long ca = (long long)cars;
        int n = ranks.size();
        long long lo = 1LL; long long hi = ca*ca*ranks[0];
        long long mini = LLONG_MAX;
        while(lo<=hi){
            long long time = lo + (hi-lo)/2;
            if(helper(ranks,ca,time)){
                mini = min(mini,time);
                hi=time-1;
            }
            else{
                lo=time+1;
            }
        }
        return mini;
    }
};