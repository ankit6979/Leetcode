#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        array<Node*, 26> link {nullptr};
        bool isWordEnd = false;

        bool isContains(char letter) {
            int index = letter - 'a';
            if(link[index]) {
                return true;
            }
            return false;
        }

        void setNode(char letter) {
            int index = letter - 'a';
            link[index] = new Node();
        }

        Node* getNext(char letter) {
            int index = letter - 'a';
            return link[index];
        }

        void setWordEndFlag() {
            isWordEnd = true;
        }

        bool getWordEndFlag() {
            return isWordEnd;
        }

};

class Trie {
    private:
        Node* root = nullptr;
    public:
        Trie() {
            root = new Node();
        }
        void insert(string word) {
            Node* node = root;
            for(int i = 0; i < word.size(); ++i) {
                if(!node->isContains(word[i])) {
                    node->setNode(word[i]);
                }
                node = node->getNext(word[i]);
            }
            node->setWordEndFlag();
        }
    
        bool search(string word) {
            Node* node = root;
            for(int i = 0; i < word.size(); ++i) {
                if(!node->isContains(word[i])) {
                    return false;
                }
                node = node->getNext(word[i]);
            }
            return node->getWordEndFlag();
        }
    
        bool startsWith(string prefix) {
            Node* node = root;
            for(int i = 0; i < prefix.size(); ++i) {
                if(!node->isContains(prefix[i])) {
                    return false;
                }
                node = node->getNext(prefix[i]);
            }
            return true;
        }
};
