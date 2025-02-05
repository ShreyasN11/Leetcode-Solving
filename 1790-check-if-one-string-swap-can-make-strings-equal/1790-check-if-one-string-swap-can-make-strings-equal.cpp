class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        vector<int>inc;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                inc.push_back(i);
            }
        }
        if(inc.size() == 0) return true;
        if(inc.size() == 2 && s1[inc[0]] == s2[inc[1]] && s2[inc[0]] == s1[inc[1]]) return true;
        return false;
    }
};