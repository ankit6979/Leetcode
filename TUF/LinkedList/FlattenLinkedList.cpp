#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

class Solution {
  public:
    struct compareNode {
        bool operator () (const Node* a, const Node* b) {
            return a->data > b->data;
        }
    };
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if (root == NULL || root->next == NULL) return root;
        Node* dummyHead = new Node(-1);
        Node* dummy = dummyHead;
        priority_queue<Node*, vector<Node*>, compareNode> q;
        
        Node* temp = root;
        while (temp != NULL) {
            q.push(temp);
            temp = temp->next;
        }
        while (!q.empty()) {
            Node* currNode = q.top();
            dummy->bottom = currNode;
            dummy = dummy->bottom;
            q.pop();
            if (currNode->bottom != NULL) {
                q.push(currNode->bottom);
            }
        }
        dummy->bottom = NULL;
        return dummyHead->bottom;
    }
};