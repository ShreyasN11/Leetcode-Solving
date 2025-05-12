class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>res;
        vector<int>cnt(10,0);
        for(int x: digits){
            cnt[x]++;
        }
        for(int i=100; i<=999; i+=2){
            vector<int>cnt2(10,0);
            int x = i;
            while(x){
                cnt2[x%10]++;
                x/=10;
            }
            bool check = true;
            for(int j=0; j<10; j++){
                if(cnt2[j] > cnt[j]){
                    check = false; break;
                }  
            }
            if(check){
                res.push_back(i);
            }
        }
        return res;
    }
};