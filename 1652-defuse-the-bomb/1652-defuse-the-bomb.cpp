class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k==0){
            vector<int>res(n,0);
            return res;
        }  
        else{
            bool flip = false; 
            for(int i=0; i<n; i++){
                code.push_back(code[i]);
            }
            if(k<0){
                reverse(code.begin(), code.end()); k = -k;
                flip = true;
            } 
            vector<int>res(n,0);
            int sum = 0;
            for(int i=1; i<=k; i++){
                sum+=code[i];
            }
            res[0]=sum;
            for(int i=1; i<n; i++){
                sum = sum + code[i+k] - code[i];
                res[i] = sum;
            }
            if(flip){
                reverse(res.begin(), res.end());
            }
            return res;
        }
    }
};