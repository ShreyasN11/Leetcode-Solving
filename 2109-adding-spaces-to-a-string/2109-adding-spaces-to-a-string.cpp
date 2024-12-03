class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int i =0; int n = s.size(); int idx = 0;
        for(int i=0; i<n; i++){
            if(idx<spaces.size() && i == spaces[idx]){
                res+= " ";
                idx++;
            }
            res += s[i];
        }
        return res;
    }

};