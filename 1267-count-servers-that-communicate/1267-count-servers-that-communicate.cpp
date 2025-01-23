class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>row(n,0);
        vector<int>cols(m,0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row[i] += grid[i][j];
                cols[j] += grid[i][j];
            }
        }

        int servers = 0;
        int iso = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    servers++;
                    if(row[i]==1 && cols[j]==1){
                        iso++;
                    }
                }
            }
        }

        return servers-iso;        
    }
};