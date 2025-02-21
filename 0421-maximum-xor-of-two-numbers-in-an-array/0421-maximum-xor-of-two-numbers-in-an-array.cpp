struct Node{
    Node *links[2];
    bool contains_key(int bit){
        return links[bit] != NULL;
    }
    Node* get_link(int bit){
        return links[bit];
    }
    void put_link(Node *x, int bit){
        links[bit] = x;
    }
};

class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->contains_key(bit)){
                node=node->get_link(bit);
            }
            else{
                node->put_link(new Node(),bit);
                node=node->get_link(bit);
            }
        }
    }

    int get_max(int num){
        Node*node = root;
        int maxi = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->contains_key(1-bit)){
                maxi = maxi | (1<<i);
                node=node->get_link(1-bit);
            }
            else{
                node=node->get_link(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto it:nums){
            t.insert(it);
        }
        int maxi = 0;
        for(auto it:nums){
            maxi = max(t.get_max(it),maxi);
        }
        return maxi;
    }
};