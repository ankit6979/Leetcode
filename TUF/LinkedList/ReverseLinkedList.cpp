#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }

        Node (int data, Node* next) {
            this->data = data;
            this->next = next; 
        }
};

Node* reverseLinkedList(Node* head) {
    if(head == NULL || head->next == NULL) return head;
    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main() {
    Node* head = new Node(5);
    
    head->next = new Node(10);
    head->next->next = new Node(15);
    
    Node* temp = reverseLinkedList(head);

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}