#include <bits/stdc++.h>
using namespace std;

// Function prototypes for performance checks
void check_large_title_length(int titleLength);
void check_common_characters(const set<string>& st, const string& s);
void check_large_search_space(const set<string>& st, const string& s);

int main() {
    set<string> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        // Check for large title length
        check_large_title_length(s.size());

        // Check for common characters
        check_common_characters(st, s);

        for (int j = 0; j < s.size(); j++) {
            for (int k = j + 1; k <= s.size(); k++) {
                string b = s.substr(j, k - j);
                st.insert(b);
            }
        }
        st.insert(s);

        // Check for large search space after processing each title
        check_large_search_space(st, s);
    }
    
    string res = "";
    for (int i = 0; i < 26; i++) {
        res = char('a' + i);
        if (st.find(res) == st.end()) {
            cout << res;
            return 0;
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            res = char('a' + i);
            res = res + char('a' + j);
            if (st.find(res) == st.end()) {
                cout << res;
                return 0;
            }
        }
    }
}

// Implementations of performance check functions
void check_large_title_length(int titleLength) {
    if (titleLength >= 15) { // Proxy threshold for near-maximum length
        cerr << "Warning: Performance bottleneck condition triggered - title length is large causing excessive substring operations!" << endl;
        abort();
    }
}

void check_common_characters(const set<string>& st, const string& s) {
    int commonCount = 0;
    for (char ch : s) {
        string singleChar(1, ch);
        if (st.find(singleChar) != st.end()) {
            commonCount++;
        }
    }
    if (commonCount > 10) { // Arbitrary threshold for commonality
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of common characters across titles!" << endl;
        abort();
    }
}

void check_large_search_space(const set<string>& st, const string& s) {
    int uniqueCount = 0;
    for (size_t j = 0; j < s.size(); j++) {
        for (size_t k = j + 1; k <= s.size(); k++) {
            string sub = s.substr(j, k - j);
            if (st.find(sub) == st.end()) {
                uniqueCount++;
            }
        }
    }
    if (uniqueCount > 200) { // Arbitrary threshold for unique substrings
        cerr << "Warning: Performance bottleneck condition triggered - large search space for uncommon substrings!" << endl;
        abort();
    }
}