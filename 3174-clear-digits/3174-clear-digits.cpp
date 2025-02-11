class Solution {
public:
    bool is_char(char ch ){
        if(ch >= 'a' && ch <= 'z') return true;
        else return false;
    }
    bool is_num(char ch){
        if(ch>='0' && ch<='9') return true;
        else return false;
    }
    string clearDigits(string s) {
        stack<int>st; int n = s.length();
        for(int i=0; i<n; i++){
            if(is_char(s[i])) st.push(s[i]);
            if(is_num(s[i])) st.pop();
        }
        string res = "";
        while(!st.empty()){
            res+= st.top(); st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};