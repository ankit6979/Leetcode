class LFUCache {
public:
    class Node {
        public:
            int key;
            int val;
            int freq;
            Node* prev;
            Node* next;
            Node(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq), prev(NULL), next(NULL) {};

    };
    int min_freq;
    int total_capacity;
    int curr_capacity;
    map<int, pair<Node*, Node*>> data;
    map<int, Node*> data_addr;
    LFUCache(int _capacity) : total_capacity(_capacity), curr_capacity(0), min_freq(INT_MAX){
        data.clear();
        data_addr.clear();
    }
    
    void addNode(int freq, Node* new_node) {
        if(data.find(freq) == data.end()) {
            Node* head = new Node(-1, -1, 1);
            Node* tail = new Node(-1, -1, 1);
            head->next = tail;
            tail->prev = head;
            data[freq].first = head;
            data[freq].second = tail;
        }
        Node* head = data[freq].first;
        Node* temp = head->next;
        new_node->next = temp;
        new_node->prev = head;
        head->next = new_node;
        temp->prev = new_node;
    }

    void delNode(Node* del_node) {
        Node* del_prev = del_node->prev;
        Node* del_next = del_node->next;
        del_prev->next = del_next;
        del_next->prev = del_prev;
    }

    int get(int key) {
        if(data_addr.find(key) != data_addr.end()) {
            Node* get_node = data_addr[key];
            delNode(get_node);
            int curr_freq = get_node->freq;
            if(curr_freq == min_freq) {
                if(data[curr_freq].first->next == data[curr_freq].second) {
                    min_freq = curr_freq + 1;
                }
            }
            else {
                min_freq = min(min_freq, curr_freq + 1);
            }
            get_node->freq = curr_freq + 1;
            addNode(get_node->freq, get_node);
            return get_node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(data_addr.find(key) == data_addr.end()) {
            if(curr_capacity == total_capacity) {
                //delete from min
                Node* lfu_node = data[min_freq].second->prev;
                delNode(lfu_node);
                data_addr.erase(lfu_node->key);
                delete lfu_node;
            }
            else {
                curr_capacity += 1;
            }
            Node* new_node = new Node(key, value, 1);
            min_freq = 1;
            addNode(new_node->freq, new_node);
            data_addr[key] = new_node;
        }
        else {
            Node* existing_node = data_addr[key];
            delNode(existing_node);
            int curr_freq = existing_node->freq;
            if(curr_freq == min_freq) {
                if(data[curr_freq].first->next == data[curr_freq].second) {
                    min_freq = curr_freq + 1;
                }
            }
            else {
                min_freq = min(min_freq, curr_freq + 1);
            }
            existing_node->val = value;
            existing_node->freq = curr_freq + 1;
            addNode(existing_node->freq, existing_node);
        }
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */