class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n= boxes.size();
        vector<int>res(n,0);
        vector<int>l(n,0);
        vector<int>r(n,0);

        int count = boxes[0] == '1' ? 1 : 0;

        for(int i=1; i<n; i++){
            l[i] = l[i-1] + count;
            count += boxes[i] == '1' ? 1 : 0;
        }

        count = boxes[n-1] == '1' ? 1 : 0;

        for(int i=n-2; i>=0; i--){
            r[i] = r[i+1] + count;
            count += boxes[i] == '1' ? 1 : 0;
        }

        for(int i=0; i<n; i++){
            res[i] = r[i] + l[i];
        }

        return res;        

        return res;
    }
};

/*

    cost of getting all balls to adjacent + number of ball

*/