class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>a;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                a.push_back(grid[i][j]);
            }
        }
        int rem = a[0]%x;
        for(int i=0; i<a.size(); i++){
            if(a[i]%x != rem){
                return -1;
            }
            a[i]/=x;
        }
        sort(a.begin(), a.end());
        int k = a.size();
        int z = a[k/2];
        int res = 0;
        for(int i=0; i<a.size(); i++){
            res += abs(z-a[i]);
        }
        return res;
    }
};