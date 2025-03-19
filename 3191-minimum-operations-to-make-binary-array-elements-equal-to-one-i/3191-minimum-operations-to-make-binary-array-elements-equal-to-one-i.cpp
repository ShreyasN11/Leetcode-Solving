class Solution {
public:
    int minOperations(vector<int>& res) {
        int count = 0;
        int n = res.size();
        for(int i=0; i<n-2; i++){
            if(res[i] == 0){
                res[i] = 1-res[i];
                res[i+1] = 1-res[i+1];
                res[i+2] = 1-res[i+2];
                count++;
            }
        }
        if(res[n-1] == 1 && res[n-2] == 1){
            return count;
        }
        return -1;
    }
};