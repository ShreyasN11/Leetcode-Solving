class Solution {
    vector<long long>segtree;

    void build(long long i, long long lo, long long hi, long long index){ // lo,hi = tree indices // i tree indice
        if(lo == hi){
            segtree[i] +=1;
            return;
        }
        long long mid = lo + (hi-lo)/2;
        if(index<=mid){
            build(2*i+1, lo, mid, index);
        }
        else{
            build(2*i+2, mid+1, hi, index);
        }
        segtree[i] = segtree[2*i+1] + segtree[2*i+2]; 
    }

    long long query(long long i, long long l, long long r, long long left, long long right){ // left right -> target l r -> tree indices
        if(left > r || right < l) return 0;
        if(left<=l && right>=r){
            return segtree[i];
        }
        long long mid = l+ (r-l)/2;
        long long l1 = query(2*i+1,l,mid,left,right);
        long long r1 = query(2*i+2,mid+1,r,left,right);
        return l1+r1;
    }

    public:
        int goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            long long n = nums1.size();
            segtree.resize(4*n+1, 0);
            long long count = 0;
            map<long long,long long>mp;
            for(long long i=0; i<n; i++){
                mp[(long long)nums2[i]] = i;
            }
            build(0,0,n-1,mp[nums1[0]]);
            for(long long i=1; i<n-1; i++){
                long long j = mp[nums1[i]];
                long long lc = query(0,0,n-1,0,j);
                long long rc = n-j-1-i+lc;
                long long cur = lc*rc;
                count += cur;
                // cout<<lc<<" "<<rc<<" "<<endl;
                build(0,0,n-1,j);
            }
            return count;
        }
};