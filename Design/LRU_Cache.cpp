#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    public:
        class Node {
            public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int _key, int _val, Node* _prev = nullptr, Node* _next = nullptr)
            : key(_key), val(_val), prev(_prev), next(_next) {};
        };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* head, Node* tail, Node* new_node) {
        Node* temp = head->next;
        new_node->next = temp;
        new_node->prev = head;
        head->next = new_node;
        temp->prev = new_node;
    }

    void deleteNode (Node* del_node) {
        Node* del_prev = del_node->prev;
        Node* del_next = del_node->next;
        del_prev->next = del_next;
        del_next->prev = del_prev;
    }

    int get(int key) {
        if(mpp.find(key) != mpp.end()) {
            Node* curr_node = mpp[key];
            int val = curr_node->val;
            deleteNode(curr_node);
            addNode(head, tail, curr_node);
            return curr_node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) == mpp.end()) {
            if(mpp.size() == cap) {
                Node* lru_node = tail->prev;
                mpp.erase(lru_node->key);
                deleteNode(lru_node);
                delete lru_node;
            }
            Node* new_node = new Node(key, value);
            mpp[key] = new_node;
            addNode(head, tail, new_node);
        }
        else {
            Node* existing_node = mpp[key];
            deleteNode(existing_node);
            addNode(head, tail, existing_node);
            existing_node->val = value;
        }
    }
};

class LRUCacheList {
public:
    struct Node {
        int val;
        list<int>::iterator it;
        Node (int val, list<int>::iterator it) : val(val), it(it) {};
    };
    // unordered_map<int, Node*> nodeMap;
    unordered_map<int, unique_ptr<Node>> nodeMap;
    list<int> task_list;
    int capacity;
    LRUCache(int capacity) : capacity(capacity){
        
    }
    
    int get(int key) {
        if(nodeMap.find(key) == nodeMap.end()) {
            return -1;
        }
        // Node* node = nodeMap[key];
        Node* node = nodeMap[key].get();
        task_list.erase(node->it);
        task_list.push_back(key); 
        node->it = --task_list.end();
        return node->val;
    }
    
    void put(int key, int value) {
        if(nodeMap.find(key) == nodeMap.end()) {
            if(task_list.size() >= capacity) {
                int lru_key = task_list.front();
                task_list.pop_front();
                nodeMap.erase(lru_key);
            }
            task_list.push_back(key);
            // nodeMap[key] = new Node(value, --task_list.end());
            nodeMap[key] = make_unique<Node>(value, --task_list.end());
        }
        else {
            // Node* node = nodeMap[key];
            Node* node = nodeMap[key].get();
            task_list.erase(node->it);
            task_list.push_back(key);
            node->val = value;
            node->it = --task_list.end();
        }
    }
};

int main() {
   LRUCache* obj = new LRUCache(2);
   obj->put(1, 1);
   obj->put(2, 2);
   cout<<obj->get(1)<<endl;
   obj->put(3, 3);
   cout<<obj->get(2)<<endl;
   obj->put(4, 4);
   cout<<obj->get(1)<<endl;
   cout<<obj->get(3)<<endl;
   cout<<obj->get(4)<<endl;
   return 0;
}