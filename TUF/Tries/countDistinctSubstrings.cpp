// #include<bits/stdc++.h>
// using namespace std;

// class Node {
//   public:
//     array<Node *, 26> link {nullptr};
//     bool endofWord = false;

//     bool isContains (char letter) {
//       int index = letter - 'a';
//       return link[index] != nullptr;
//     }

//     void setNode (char letter) {
//       int index = letter - 'a';
//       link[index] = new Node();
//     }

//     Node* getNext (char letter) {
//       int index = letter - 'a';
//       return link[index];
//     }

//     void setEndWordFlag () {
//       endofWord = true;
//     }

//     bool getEndWordFlag () {
//       return endofWord;
//     }
// };

// class Trie {
//   private:
//     Node* root = nullptr;

//   public:
//     Trie() {
//       root = new Node();
//     }

//     void insert (string& word) {
//       Node* node = root;
//       for (int i = 0; i < word.size(); ++i) {
//         if (!node->isContains(word[i])) {
//             node->setNode(word[i]);
//         }
//         node = node->getNext(word[i]);
//       }
//       node->setEndWordFlag();
//     }

//     int countDistinctSubstringHelper(Node* node) {
//         if(node == NULL) return 0;

//         int total_substr = 0;

//         for (int i = 0; i < 26; ++i) {
//             char ch = 'a' + i;
//             if(node->getNext(ch) && node->getNext(ch)->endofWord) {
//                 total_substr += countDistinctSubstringHelper(node->getNext(ch)) + 1;
//             }
//         }
//         return total_substr;
//     }

//     int countDistinctSubstring() {
//         return countDistinctSubstringHelper(root);
//     }
// };

// int countDistinctSubstrings(string &s) {
//     Trie* trie = new Trie();
//     for (int i = 0; i < s.size(); ++i) {
//         for(int j = 0; j < s.size(); ++j) {
//             string sub_str = s.substr(i, j - i + 1);
//             trie->insert(sub_str);
//         }
//     }
//     return trie->countDistinctSubstring() + 1;
// }

/* 
    Optimal approach, we don't need to check word end and all, just iterate using n^2 and check if exists then duplicate else
    unique, this approach only helps with the space complexity, as if you use set then we'll have to keep each strimng seperately
    but using tries we can avoid that space
*/
#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    array<Node *, 26> link {nullptr};

    bool isContains (char letter) {
      int index = letter - 'a';
      return link[index] != nullptr;
    }

    void setNode (char letter) {
      int index = letter - 'a';
      link[index] = new Node();
    }

    Node* getNext (char letter) {
      int index = letter - 'a';
      return link[index];
    }
};

class Trie {
  private:
    Node* root = nullptr;

  public:
    int distinctSubstring;
    Trie() {
      root = new Node();
      distinctSubstring = 0;
    }

    void insert (string& word) {
      Node* node = root;
      for (int i = 0; i < word.size(); ++i) {
        if (!node->isContains(word[i])) {
            node->setNode(word[i]);
            distinctSubstring += 1;
        }
        node = node->getNext(word[i]);
      }
    }

};

int countDistinctSubstrings(string &s) {
    Trie* trie = new Trie();
    for (int i = 0; i < s.size(); ++i) {
        for(int j = 0; j < s.size(); ++j) {
            string sub_str = s.substr(i, j - i + 1);
            trie->insert(sub_str);
        }
    }
    return trie->distinctSubstring + 1;
}