#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 

class Node {
    public:
        array<Node*, 26> link {nullptr};
        bool isWordEnd = false;
        int cnt = 0;

        bool isContains(char letter) {
            return link[letter - 'a'] != nullptr;
        }

        void setNode(char letter) {
            int index = letter - 'a';
            link[index] = new Node();
        }

        Node* getNext(char letter) {
            int index = letter - 'a';
            return link[index];
        }

        void setWordEndFlag(bool valToSet) {
            isWordEnd = valToSet;
        }

        bool getWordEndFlag() {
            return isWordEnd;
        }

        void incWordCount() {
            cnt += 1;
        }

        void decWordCount() {
            cnt -= 1;
        }

        int getWordCount() {
            return cnt;
        }

};

class Trie {
    private:
        Node* root = nullptr;
    public:
        Trie() {
            root = new Node();
        }
        int countWordsStartingWithHelper(Node* node) {
            if(node == NULL) {
                return 0;
            }
            int word_cnt = 0;
            for(int i = 0; i < 26; ++i) {
                word_cnt += countWordsStartingWithHelper(node->getNext('a' + i));
            }
            return word_cnt + node->getWordCount();
        }
        void insert(string& word) {
            Node* node = root;
            for(int i = 0; i < word.size(); ++i) {
                if(!node->isContains(word[i])) {
                    node->setNode(word[i]);
                }
                node = node->getNext(word[i]);
            }
            node->setWordEndFlag(true);
            node->incWordCount();
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

        int countWordsEqualTo(string &word){
            Node* node = root;
            for(int i = 0; i < word.size(); ++i) {
                if(!node->isContains(word[i])) {
                    return 0;
                }
                node = node->getNext(word[i]);
            }
            return node->getWordCount();
        }

        int countWordsStartingWith(string &word){
            Node* node = root;
            for(int i = 0; i < word.size(); ++i) {
                if(!node->isContains(word[i])) {
                    return 0;
                }
                node = node->getNext(word[i]);
            }
            return countWordsStartingWithHelper(node);
        }

        void erase(string &word){
            Node* node = root;
            for(int i = 0; i < word.size(); ++i) {
                node = node->getNext(word[i]);
            }
            node->decWordCount();
            if(node->getWordCount() == 0) {
                node->setWordEndFlag(false);
            }
        }
};