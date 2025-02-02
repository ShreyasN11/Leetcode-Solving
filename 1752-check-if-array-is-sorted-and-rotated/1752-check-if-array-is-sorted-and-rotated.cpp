class Solution {
public:
    bool check(vector<int>& arr) {
        bool flag = false; int n = arr.size(); int i;
        for(i=0; i<n-1; i++){
            if(!(arr[i]<=arr[i+1])){
                flag = true;
                if(arr[n-1]<=arr[0]){
                    break;
                }
                else return false;
            }
        }
        if(!flag) return true;
        if(flag){
            for(int j=i+1; j<n-1; j++){
                if(arr[j]>arr[j+1]){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};