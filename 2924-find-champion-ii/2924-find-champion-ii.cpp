class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>d(n,0);
        for(auto it: edges){
            d[it[1]]++;
        }
        vector<int>res;
        for(int i=0; i<d.size(); i++){
            if(d[i] == 0){
                res.push_back(i);
            }
        }
        if(res.size() == 1){
            return res[0];
        }
        else return -1;
    }
};