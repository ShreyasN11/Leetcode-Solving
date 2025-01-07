class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int>pre(n+1,0);
        for(auto it: shifts){
            int start = it[0];
            int end = it[1];
            int dir = it[2];
            if(dir){
                pre[start]++;
                pre[end+1]--;
            }
            else{
                pre[start]--;
                pre[end+1]++;
            }
        }
        vector<int>shift(n,0);
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=pre[i];
            shift[i]=sum;
        }

        string res = "";

        for(int i=0; i<n; i++){
            int move = shift[i];
            int a = (s[i] - 'a' + move % 26 + 26) % 26;
            res += char('a' + a);
        }
        return res;
    }
};