class Solution {
public:
    bool check(string &part, stack<char>st){
        stack<char>stt;
        for(int i=part.size()-1; i>=0; i--){
            if(st.top() != part[i]) return false;
            st.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<char>st;
        int j=0; int n = s.length(); int m = part.length();
        for(int i=0; i<n; i++){
            st.push(s[i]);
            if(st.size() >= m && check(part,st)){
                for(int i=0; i<m; i++){
                    st.pop();
                }
            }
        }
        string res = "";
        while(!st.empty()){
            res += st.top(); st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};