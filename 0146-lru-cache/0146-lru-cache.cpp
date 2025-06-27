class LRUCache {
public:
    class node{
        public:
        int key,val;
        node* prv;
        node* next;

        node(int k,int v)
        {
            key=k;
            val=v;
            prv=next=NULL;
        }
    };
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    unordered_map<int,node*>m;
    int limit;
    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prv=head; 
    }
    void addNode(node* newNode)
    {
        node*oldNext=head->next;
        head->next=newNode;
        oldNext->prv=newNode;
        newNode->next=oldNext;
        newNode->prv=head;
    }
    void delNode(node* oldNode)
    {
        node* oldPrv=oldNode->prv;
        node* oldNext=oldNode->next;

        oldPrv->next=oldNext;
        oldNext->prv=oldPrv;
    }
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        node* ansNode=m[key];
        int ans=ansNode->val;

        m.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        m[key]=ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node* oldNode=m[key];
            delNode(oldNode);
            m.erase(key);
        }
        if(m.size()==limit)
        {
            m.erase(tail->prv->key);
            delNode(tail->prv);
        }
        node*newNode=new node(key,value);
        addNode(newNode);
        m[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */