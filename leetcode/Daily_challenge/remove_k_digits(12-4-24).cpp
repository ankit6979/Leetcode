class Solution {
public:
    string removeLeadingZeros(const std::string& str) {
        auto it = std::find_if(str.begin(), str.end(), [](char c) { return c != '0'; });
        return std::string(it, str.end());
    }
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> s;
        s.push(num[0]);
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] >= s.top() || k == 0) {
                s.push(num[i]);
            }
            else if (k > 0) {
                while (!s.empty() && num[i] < s.top() && k > 0) {
                    s.pop();
                    --k;
                }
                s.push(num[i]);
            }
        }
        while (!s.empty()) {
            if (k > 0) {
                s.pop();
                --k;
            }
            else{
                ans += s.top();
                s.pop();
            }
        }
        reverse(ans.begin(), ans.end());
        ans = removeLeadingZeros(ans);
        return ans.size() == 0 ? "0" : ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


// Optimized //

class Solution {
public:
    string removeLeadingZeros(const std::string& str) {
        auto it = std::find_if(str.begin(), str.end(), [](char c) { return c != '0'; });
        return std::string(it, str.end());
    }
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> s;
        for (char digit : num) {
            while (!s.empty() && digit < s.top() && k > 0) {
                s.pop();
                --k;
            }
            s.push(digit);
        }
        while (!s.empty() && k > 0) {
            s.pop();
            --k;
        }
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        ans = removeLeadingZeros(ans);
        return ans.size() == 0 ? "0" : ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();