class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int>res;
        map<int,int>mp; // ball -> color
        map<int,int>mpp; // color -> ball count
        int q=queries.size();
        for(int i=0; i<q; i++){
            int ball = queries[i][0];
            int col = queries[i][1];

            if(mp.find(ball) != mp.end()){
                int oldcol = mp[ball];
                mpp[oldcol]--;
                if(mpp[oldcol] == 0) mpp.erase(oldcol);            
            }
            mp[ball] = col;    
            mpp[col]++;
            res.push_back(mpp.size());
        }
        return res;
    }
};