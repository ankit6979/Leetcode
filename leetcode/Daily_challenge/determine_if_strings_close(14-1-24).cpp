class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq_word1(26, 0);
        vector<int> freq_word2(26, 0);
        if(word1.length()!=word2.length()){
            return false;
        }
        for(int i=0; i<word1.length(); i++){
            freq_word1[word1[i]-'a']+=1;
        }
        for(int i=0; i<word2.length(); i++){
            freq_word2[word2[i]-'a']+=1;
        }
        for (int i=0; i<26; i++){
            //checking for same characters in both strings
            if(freq_word1[i]==0 && freq_word2[i] != 0){
                return false;
            }
        }
        sort(freq_word1.begin(), freq_word1.end());
        sort(freq_word2.begin(), freq_word2.end());
        //checking for frequency
        for(int i=0; i<26; i++){
            if(freq_word1[i]!=freq_word2[i]){
                return false;
            }
        }
        return true;
    }
};