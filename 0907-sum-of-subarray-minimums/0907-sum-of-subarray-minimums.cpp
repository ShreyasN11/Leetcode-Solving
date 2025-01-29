class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long mod = 1e9+7;
        long long n = arr.size();
        vector<long long>pse(n,-1); vector<long long>nse(n,n);
        long long sum = 0;
        stack<long long>st;
        for(long long i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i); 
        }
        stack<long long>stt;
        for(long long i=n - 1; i>=0; i--) {
            while (!stt.empty() && arr[stt.top()] >= arr[i]) {
                stt.pop();
            }
            nse[i] = stt.empty() ? n : stt.top();
            stt.push(i);
        }
        long long res=0;
        for(long long i=0; i<n; i++){
            res += (long long)((long long)(((i-pse[i])*(nse[i]-i))%mod) * (long long)arr[i])%mod;
        }
        return res;
    }
};