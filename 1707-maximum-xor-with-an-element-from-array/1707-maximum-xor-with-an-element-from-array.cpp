struct Node{
    Node* links[2];
    bool contains_key(int bit){
        return links[bit] != NULL;
    }
    void put_key(int bit, Node* node){
        links[bit] = node;
    }
    Node* get_key(int bit){
        return links[bit];
    }
};

class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int x){
        Node *node = root;
        for(int i=31; i>=0; i--){
            int bit = (x>>i)&1;
            if(! node->contains_key(bit)){
                node->put_key(bit, new Node());
            }
            node = node->get_key(bit);
        }
    }

    int get_max(int x){
        Node *node = root;
        int val = 0;
        if (!node->contains_key(0) && !node->contains_key(1)) {
            return -1;
        }
        for(int i=31; i>=0; i--){
            int bit = (x>>i)&1;
            if(node->contains_key(1- bit)){
                val |= 1<<i;
                node = node->get_key(1-bit);
            }
            else{
                node = node->get_key(bit);
            }
            
        }
        return val;
    }
};

class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q = queries.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<q; i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), cmp);
        // for(auto it: queries) cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        vector<int>ans(q);

        int idx = 0;
        Trie trie;

        for(int i=0; i<q; i++){
            int x = queries[i][0];
            int maxi = queries[i][1];
            int index = queries[i][2];

            while(idx<n && nums[idx] <= maxi){
                trie.insert(nums[idx]); idx++;
            }

            ans[index] = trie.get_max(x);
        }

        return ans;
    }
};