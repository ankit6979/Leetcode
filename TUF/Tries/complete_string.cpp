#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        array<Node*, 26> link {};
        bool endOfWorld = false;

        bool isContains(char letter) {
            int index = letter - 'a';
            return link[index] != nullptr;
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
            endOfWorld = true;
        }

        bool getWordEndFlag() {
            return endOfWorld;
        }
};

class Trie {
    private:
        Node* root = nullptr;

    public:
        Trie() {
            root = new Node();
        }

        void insert(string& word) {
            Node* node = root;
            for (int i = 0; i < word.size(); ++i) {
                if (!node->isContains(word[i])) {
                    node->setNode(word[i]);
                }
                node = node->getNext(word[i]);
            }
            node->setWordEndFlag();
        }

        void maxCompleteStringHelper(Node* node, string& comp_str, string& max_comp_str) {
            if (node == nullptr) {
                return;
            }

            for (int i = 0; i < 26; ++i) {
                if (node->getNext('a' + i) && node->getNext('a' + i)->getWordEndFlag()) {
                    char ch = 'a' + i;

                    comp_str.push_back(ch);
                    if(comp_str.size() > max_comp_str.size()) {
                        max_comp_str = comp_str;
                    }

                    maxCompleteStringHelper(node->getNext('a' + i), comp_str, max_comp_str);

                    comp_str.pop_back();
                }
            }
        }

        string maxCompleteString() {
            string comp_str = "";
            string max_comp_str = "";

            maxCompleteStringHelper(root, comp_str, max_comp_str);

            if (!max_comp_str.empty()) {
                return max_comp_str;
            }
            return "None";
        }
};

string completeString(int n, vector<string> &a) {
    Trie* trie = new Trie();
    for (int i = 0; i < n; ++i) {
        trie->insert(a[i]);
    }
    return trie->maxCompleteString();
}