class Solution {
public:
    struct TrieNode {
        TrieNode* childNode[26];
        bool wordEnd;
        TrieNode() {
            wordEnd = false;
            for (int i = 0; i < 26; ++i) {
                childNode[i] = NULL;
            }
        }
    };
    void insertKey(TrieNode* root, string& key) {
        TrieNode* currNode = root;
        for (auto c : key) {
            if (currNode->childNode[c - 'a'] == NULL) {
                TrieNode* newNode = new TrieNode();
                currNode->childNode[c - 'a'] = newNode;
            }
            currNode = currNode->childNode[c - 'a'];
        }
        currNode->wordEnd = 1;
    }
    string searchKey (TrieNode* root, string& key) {
        string rootWord = "";
        TrieNode* currNode = root;
        for (auto c : key) {
            if (currNode->wordEnd == true) {
                return rootWord;
            }
            else if (currNode->childNode[c - 'a'] == NULL) {
                return "";
            }
            rootWord += c;
            currNode = currNode->childNode[c - 'a'];
        }
        return "";
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        string currWord = "";
        string ans = "";
        string rootWord;
        TrieNode* root = new TrieNode();
        for (int i = 0; i < dictionary.size(); ++i) {
            insertKey (root, dictionary[i]);
        }
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                rootWord = searchKey(root, currWord);
                if (rootWord == "") {
                    ans += currWord;
                    ans += " ";
                }
                else {
                    ans += rootWord;
                    ans += " ";
                }
                currWord = "";
            }
            else {
                currWord += sentence[i];
            }
        }
        rootWord = searchKey(root, currWord);
        if (rootWord == "") {
            ans += currWord;
        }
        else {
            ans += rootWord;
        }
        return ans;
    }
};