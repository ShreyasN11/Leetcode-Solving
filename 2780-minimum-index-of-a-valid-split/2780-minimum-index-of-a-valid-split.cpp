class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        int maxi = -1;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(mp[maxi] < mp[nums[i]]){
                maxi = nums[i];
            }
        }
        if(mp[maxi] <= (n+1)/2){
            return -1;
        }
        int right = mp[maxi];
        int left = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == maxi){
                left++; right--;
            } 
            cout<<left<<" "<<right<<endl;
            if(i>0 && i<n-1 && left > (i+1)/2 && right > (n-i-1)/2){
                return i;
            }
        }
        return -1;
    }
};