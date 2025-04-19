class Solution {
public:
    long long countFairPairs(vector<int>& a, int lower, int upper) {
        sort(a.begin(), a.end());
        long long count = 0;
        for(int i=0; i<a.size()-1; i++){
            count += (upper_bound(a.begin()+i+1, a.end(), upper - a[i]) - lower_bound(a.begin()+i+1, a.end(), lower-a[i]));
        }
        return count;
    }
};