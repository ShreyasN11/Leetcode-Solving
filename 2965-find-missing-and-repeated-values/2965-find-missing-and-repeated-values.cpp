class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long sum = 0;
        long long ssum = 0;
        for(auto it:grid){
            for(auto itt:it){
                sum+=(long long)itt;
                ssum+=(long long)(itt*itt);
            }
        }
        vector<long long>res;
        long long sqr = n*n;
        long long sum_exp = (sqr*(sqr+1)/2);
        long long ssum_exp = (sqr*(sqr+1)*(2*sqr+1))/6;
        long long x = sum_exp-sum;
        long long y = (ssum_exp-ssum)/(x);
        long long c = (x + y)/2;
        long long b = y - c;
        return {(int)b,(int)c};
    }
};