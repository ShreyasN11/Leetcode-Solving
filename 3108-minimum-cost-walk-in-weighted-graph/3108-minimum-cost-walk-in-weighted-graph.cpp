class Solution {
public:
    class DSU{
        public:
        vector<int>a;
        vector<int>size;
        vector<int>par;
        DSU(int n){
            size.resize(n+1,1);
            par.resize(n+1,1);
            a.resize(n+1,-1);
            for(int i=0; i<=n; i++){
                par[i] = i;
            }            
        }
        int findpar(int x){
            if(par[x] == x) return x;
            else return par[x] =  findpar(par[x]);
        }
        bool isset(int x, int y){
            return findpar(x) == findpar(y);
        }
        void uni(int x, int y, int w){
            int parx = findpar(x); int pary = findpar(y);
            if(a[parx] == -1) a[parx] = w;
            if(a[pary] == -1) a[pary] = w;
            if(parx == pary){
                a[parx] = a[parx] & w;
                return;
            }
            if(size[parx] > size[pary]){
                a[parx] = a[parx] & a[pary] & w;
                par[pary] = parx;
                size[pary] += size[parx];
            }
            else{
                a[pary] = a[parx] & a[pary] & w;
                par[parx] = pary;
                size[parx] += size[pary];
            }
        }
    };
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU d(n);
        for(auto edge : edges){
            d.uni(edge[0], edge[1], edge[2]);
        }
        vector<int>res;
        for(auto it: query){
            int u = it[0]; int v = it[1];
            if(!d.isset(u,v)){
                // cout<<"here ";
                res.push_back(-1);
            }
            else{
                res.push_back(d.a[d.findpar(u)]);
            }
        }
        return res;
    }
};