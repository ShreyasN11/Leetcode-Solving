class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[1] == b[1]) return a[0] < b[0];
        else return a[1] < b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>>res;
        int lo = intervals[0][0]; int hi = intervals[0][1];
        int i=1;
        while(i<n){
            if(intervals[i][0] <= hi){
                hi = max(hi,intervals[i][1]);
                lo = min(lo,intervals[i][0]);
                i++;
            }
            else{
                res.push_back({lo,hi});
                lo=intervals[i][0];
                hi=intervals[i][1];
                i++;
            }
        }
        res.push_back({lo,hi});
        return res;
    }
};