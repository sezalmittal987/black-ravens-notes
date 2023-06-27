class Node{
    public:
    int key, value;
    Node* next;

    Node(int k, int v){
        key = k, value = v;
        next = NULL;
    }
};
class LRUCache {
public:
    int maxC;
    int currC;
    Node* head;

    LRUCache(int capacity) {
        maxC = capacity;
        currC = 0;
        head = NULL;
    }
    
    int get(int key) {
        Node* curr = head;
        Node* prev = NULL;
        while( curr){
            if( curr->key == key ) {
                Node* curr2;
                if( prev){
                    prev->next = curr->next;
                    curr2 = prev;
                }
                else{
                    if( curr->next) head = curr->next;
                    curr2 = curr; 
                }
                while(curr2->next){
                    curr2 = curr2->next;
                }
                curr2->next = curr;
                curr->next = NULL; 
                return curr->value;
            }
            prev = curr;
            curr = curr->next;
        }
        return -1;
    }
    
    void put(int key, int value) {
        Node* curr = head;
        if( !head) {
            head = new Node(key, value);
            return;
        }
        while(curr->next){
            if( curr->key == key ){
                curr->value = value;
                return;
            }
            curr= curr->next;
        }
        curr->next = new Node(key, value);
        if( currC < maxC){
            currC++;
        }
        else{
            head = head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */