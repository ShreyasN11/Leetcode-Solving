class Solution {
public:
    bool isvowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') ? true : false;
    }
    bool valid(string &s){
        if(isvowel(s[0]) && isvowel(s[s.length()-1])) return true; 
        else return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>prefix(n+1,0);
        for(int i=1; i<=n; i++){
            prefix[i] = prefix[i-1] + valid(words[i-1]);
        }
        //for(auto it: prefix) cout<<it<<" ";
        vector<int>res;
        for(auto it: queries){
            int l=it[0]; int r=it[1];
            res.push_back(prefix[r+1]-prefix[l]);
        }
        return res;
    }
};