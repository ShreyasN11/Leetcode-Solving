class Solution {
public:
    bool check(vector<int>& candies, long long k, long long mid){
        int i=0; int n=candies.size();
        while(i<n && k>0){
            k-= candies[i++]/mid;
        }
        if(k<=0) return true;
        else return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size(); 
        int lo = 1; int hi = *max_element(candies.begin(), candies.end());
        int maxi = 0; 
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(candies,k,mid)){
                maxi = max(maxi, mid);
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return maxi;
    }
};