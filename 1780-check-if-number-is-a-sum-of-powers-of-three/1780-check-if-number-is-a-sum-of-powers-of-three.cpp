class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x = 1;
        while(x*3<=n){
            x*=3;
        }
        while(x>0 && n>0){
            if(n>=x){
                n-=x;
            }
            x/=3;
            cout<<x<<" "<<n<<endl;
        }
        if(n==0) return true;
        else return false;
    }
};