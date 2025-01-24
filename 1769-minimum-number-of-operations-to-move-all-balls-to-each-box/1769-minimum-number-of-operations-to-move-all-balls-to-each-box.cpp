class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n= boxes.size();
        vector<int>res(n,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int x = boxes[j] == '1' ? 1 : 0;
                res[i] += x*abs(i-j);
            }
        }

        return res;
    }
};