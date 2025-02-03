struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
};

class LRUCache {
int cap; Node *head; Node *tail; map<int,Node*>mp;     

void insert(Node * node){
    Node * temp = head->next;
    head->next = node;
    node -> next = temp;
    temp -> prev = node;
    node -> prev = head;
}

void del(Node * node){
    Node * temp = node -> prev;
    Node * temp2 = node -> next;
    temp ->next = temp2;
    temp2 -> prev = temp;    
}

public:
    LRUCache(int capacity) {
        cap = capacity;
        mp.clear();
        head = new Node; tail = new Node; 
        head->next = tail; head->prev = NULL;
        tail->next = NULL; tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node * x = mp[key];
        del(x);
        insert(x);
        return x->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) == mp.end()){
            if(mp.size() == cap){
                Node *x = tail->prev;
                mp.erase(x->key);
                del(x);                
            }
            Node *node = new Node;
            node->key = key; node->val = value;
            insert(node);
            mp[key] = node;            
        }
        else{
            Node * x = mp[key];
            x->val = value;
            del(x);
            insert(x);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */