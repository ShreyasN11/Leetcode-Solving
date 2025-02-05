class Solution {
public:
    // bool checkmap(map<char,int>mp, map<char,int>mpp){
    //     bool flag = true;
    //     for(auto it: mp){
    //         if(it.second > mpp[it.first]) flag = false;
    //     }
    //     return flag;
    // }

    string minWindow(string s, string t) {
        int n = s.length(); int m = t.length();
        if(n<m) return "";
        int l=-1; int mini = INT_MAX;
        map<char,int>mp;
        //map<char,int>mpp;

        for(auto it: t) mp[it]++;
        int count = t.length();
        int lo=0; int hi = 0;

        while(hi<n){
           char x = s[hi];
           if(mp[x] > 0) count--;
           mp[x]--;
           hi++; 
           if(count == 0){
                while(lo<hi){
                    if(mini > hi-lo+1){
                        mini = hi-lo+1; l=lo;
                    }
                    char y = s[lo];
                    mp[y]++; lo++;
                    if(mp[y] > 0) break;    
                }
                count++;
           }
           //hi++;       
        }
        if(mini == INT_MAX) return "";
        return s.substr(l,mini);
    }
};