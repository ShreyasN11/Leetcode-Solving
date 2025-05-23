class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string>res;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j!=i){
                    if(words[j].find(words[i]) != string::npos){
                        res.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return res;
    }
};