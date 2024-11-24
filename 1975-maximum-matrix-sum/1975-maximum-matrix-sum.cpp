class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long n = matrix.size();
        long long mini = LLONG_MAX;
        long long count = 0;
        long long sum = 0;
        for(long long i=0; i<n; i++){
            for(long long j=0; j<n; j++){
                mini = min(mini,(long long)abs(matrix[i][j]));
                count += matrix[i][j] < 0 ? 1 : 0;
                sum+= abs(matrix[i][j]);
            }
        }
        if(count%2 == 0){
            return sum;
        }
        else return sum - 2*mini;
    }
};