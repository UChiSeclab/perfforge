#include <bits/stdc++.h>
using namespace std;

// Checker Functions
void check_nested_loop_invariant(int length) {
    if (length > 180) {
        cerr << "Warning: Nested loop invariant triggered - potential high cost due to string length" << endl;
        abort();
    }
}

void check_repeated_subsequence(int tLength) {
    if (tLength < 3) {
        cerr << "Warning: Repeated subsequence invariant triggered - excessive calls with short 't'" << endl;
        abort();
    }
}

void check_string_manipulation(int length) {
    if (length > 180) {
        cerr << "Warning: String manipulation invariant triggered - potential overhead for string length" << endl;
        abort();
    }
}

bool isSubsequence(string s, string t) {
    int i = 0;
    int j = 0;
    int l = t.length();
    int len = s.length();
    while (j < l && i < len) {
        if (s[i] == t[j]) {
            i++;
            j++;
        } else
            i++;
    }
    return j == l;
}

int main() {
    string s, t;
    cin >> s;
    cin >> t;

    // Check invariants before computation
    int sLength = s.length();
    int tLength = t.length();
    check_nested_loop_invariant(sLength);
    check_repeated_subsequence(tLength);
    check_string_manipulation(sLength);

    int maxlen = 0;
    for (int i = 0; i < sLength; i++) {
        for (int j = i; j < sLength; j++) {
            int len = j - i + 1;
            string s1 = s.substr(0, i) + s.substr(j + 1);
            if (isSubsequence(s1, t)) {
                maxlen = max(maxlen, len);
            }
        }
    }
    cout << maxlen << endl;
    return 0;
}