class Solution {
public:
    class DSU{
        public:
        vector<int>par;
        vector<int>size;
        vector<int>edges;

        DSU(int n){
            par.resize(n+1);
            size.resize(n+1,1);
            edges.resize(n+1,0);
            for(int i=0; i<=n; i++){
                par[i] = i;
            }
        }

        int findpar(int x){
            if(x==par[x]) return x;
            else return par[x] = findpar(par[x]);
        }

        void uni(int x, int y){
            int parx = findpar(x); int pary = findpar(y);
            if(parx == pary){
                edges[parx]++; return;
            }
            if(size[parx] > size[pary]){
                edges[parx]++;
                edges[parx] += edges[pary];
                par[pary] = parx;
                size[parx] += size[pary];
            }
            else{
                edges[pary]++;
                edges[pary] += edges[parx];
                par[parx] = pary;
                size[pary] += size[parx];
            }
        }
    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        DSU d(n);
        for(auto it: edges){
            d.uni(it[0], it[1]);
        }
        // for(auto it: d.edges) cout<<it<<" ";
        // cout<<endl;
        for(int i=0; i<n; i++){
            if(d.par[i] == i){
                int s = d.size[i];
                int req = s*(s-1)/2;
                // cout<<i<<" req: "<<req<<" found: "<<d.edges[i]<<endl;
                if(req == d.edges[i]) count++;
            }
        }
        return count;
    }
};