/* Soln 1 - using hashmap with o(n) time complexity but with extra space*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;
        map<char, int> cnt;
        for(int i=0; i<s.size(); i++){
            cnt[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            if(cnt[t[i]]==0){
                ans= t[i];
                break;
            }
            else{
                cnt[t[i]]--;
            }
        }
        return ans;
    }
};

/* Soln 2: Idea;

All letters persent in s is present in t.
There is just one extra letter in t.
Every character can be represented as an ASCII .
ASCII value of the extra letter in t is derived as follows:
Sum of all ASCII values of charcters in s -> sSum
Sum of all ASCII values of charcters in t -> tSum
Return the difference (tSum-sSum)
Instead of storing the diff at each point, passing it over to the next element
would do the trick. We do this till the last element of t. Remember, t has one
letter more than s always :)
Order of characters does not affect it as we are more focused on the difference
of overall sum of ASCII of each letter in each arrray, s and t.*/
class Solution {
public:
    char findTheDifference(string s, string t) 
    {
      for(int i=0;i<s.size();i++)
		t[i+1]+=t[i]-s[i]; //Passing the diff: (t[i]-s[i]) to t[i+1]
      return t[t.size()-1]; //The diff will be carried over to the last element eventually
    }
};