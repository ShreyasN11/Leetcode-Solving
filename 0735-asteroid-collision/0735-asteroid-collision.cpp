class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        int lo=0; bool is_pos;
       while (lo < a.size()-1 && a.size()>1){
            is_pos = a[lo] < 0 ? false : true;
            if(is_pos && a[lo+1] <0){
                if(a[lo] == abs(a[lo+1])){
                    a.erase(a.begin() + lo, a.begin() + lo + 2);
                }
                else{
                    int index = abs(a[lo+1]) > a[lo] ? lo : lo+1;
                    auto it = a.begin()+index;
                    a.erase(it); 
                    
                }
            }
            else if(!is_pos && a[lo+1]>=0){
                if(a[lo] == abs(a[lo+1])){
                   a.erase(a.begin() + lo, a.begin() + lo + 2);
                }
                else{
                    int index = abs(a[lo]) > a[lo+1] ? lo+1 : lo;
                    auto it = a.begin()+index;
                    a.erase(it); 
                    if(index==lo+1){
                        lo--;
                    }
                }
            }
            lo++;
        }
        return a;
    }
};