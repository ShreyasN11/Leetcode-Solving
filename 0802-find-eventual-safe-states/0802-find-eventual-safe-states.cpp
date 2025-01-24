class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int>&visited, vector<int> &path, vector<int>&check, int node){
        visited[node] = 1;
        check[node] = 0;
        path[node] = 1;
        for(auto it: graph[node]){
            if(visited[it] == 0){
                bool flag = dfs(graph,visited,path,check,it);
                if(flag) return true;
            }
            else if(path[it] == 1) return true;
        }
        check[node] = 1;
        path[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>res;
        vector<int>visited(n,0);
        vector<int>path(n,0);
        vector<int>check(n,0);

        for(int i=0; i<n; i++){
            if(! visited[i]) dfs(graph,visited,path,check,i);
        }

        for(int i=0; i<n; i++){
            if(check[i]==1) res.push_back(i);
        }

        return res;
    }
};