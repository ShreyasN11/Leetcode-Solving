class ProductOfNumbers {
public:
    vector<long long>pref;
    int last_zero;
    int n;
    ProductOfNumbers() {
        n=1;
        pref.push_back(1);
        last_zero = -1;
    }
    
    void add(int num) {
        if(num == 0){
            last_zero = pref.size();
            pref.push_back(n);
            n++;
        }
        else{
            pref.push_back((long long)(pref[n-1]*(long long)num));
            n++;
        }
    }
    
    int getProduct(int k) {
        if(n-k <= last_zero){
            return 0;
        }
        else{
            long long left = pref[n-k-1];
            long long right = pref[n-1];
            return right/left;
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */