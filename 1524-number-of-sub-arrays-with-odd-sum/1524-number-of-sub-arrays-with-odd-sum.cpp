class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        long long mod = 1e9+7;
        long long cursum = 0;
        long long odd = 0;
        long long even = 1;
        long long res = 0;

        for(int i=0; i<n; i++){
            cursum += (long long)arr[i];
            if(cursum%2 == 1){
                res +=even; 
                odd++;
            }
            else{
                res += odd;
                even++;
            }
            res%=mod;
        }
        return res%mod;
    }
};