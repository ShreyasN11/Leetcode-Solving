class Solution {
public:
    int isPrefixOfWord(string sentence, string sw) {
        vector<string>s;
        string word;
        stringstream ss(sentence);
        while (ss >> word){
            s.push_back(word);
        }
        int n = sw.length();
        int count = 0;
        for(auto it: s){
            count++;
            if(it.length() < n) continue;
            else if(it.substr(0,n) == sw) return count;
        }
        return -1;

    }
};