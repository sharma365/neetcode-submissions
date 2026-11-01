class LRUCache
{
    private:
    int capacity_;
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v):key(k), val(v), prev(nullptr), next(nullptr){}
        };
    unordered_map<int, Node*> mpp;
    Node* head;
    Node* tail;

    void add_node(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void delete_node(Node* node){
        Node* prevnode = node->prev;
        Node* nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    void movetohead(Node* node){
        delete_node(node);
        add_node(node);
    }      

    public:
    LRUCache(int capacity) : capacity_(capacity){
        // capacity_=capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    ~LRUCache(){
        Node* curr = head;
        while(curr){
            Node* next = curr->next;
            delete curr;
            curr=next;
        }
    }

    int get(int key){
            if(mpp.find(key)!=mpp.end()){
                Node* node = mpp[key];
                movetohead(node);
                return node->val;
            }
            else return -1;
    }

    void put(int key, int value){
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            movetohead(node);
        }
        else{
            if(mpp.size()==capacity_){
                Node* todelete = tail->prev;
                mpp.erase(todelete->key);
                delete_node(todelete);
                delete todelete;
            }
            Node* newNode = new Node(key, value);
            mpp[key] = newNode;
            add_node(newNode);
        }
    }
};
