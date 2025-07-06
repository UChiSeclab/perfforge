#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_input_invariant(size_t inputSize) {
    if (inputSize > 100000) { // Arbitrary threshold
        cerr << "Warning: Large input invariant triggered - input size close to limit!" << endl;
        abort();
    }
}

void check_character_counting_invariant(size_t sSize) {
    if (sSize > 100000) { // Arbitrary threshold
        cerr << "Warning: Character counting invariant triggered - processing large input string!" << endl;
        abort();
    }
}

void check_large_string_construction_invariant(int len) {
    if (len > 100000) { // Arbitrary threshold
        cerr << "Warning: Large string construction invariant triggered - constructing large sequence!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(int cntSize) {
    if (cntSize > 100) { // Threshold for digit counts
        cerr << "Warning: Nested loop invariant triggered - excessive digit operations!" << endl;
        abort();
    }
}

int cnt[11];
int cnt2[11];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    // Check for large input size
    check_large_input_invariant(s.size());
    
    if (s == "01" || s == "10") {
        cout << 0 << '\n';
        return 0;
    }

    int len = 1;
    for (;; ++len) {
        stringstream ss;
        ss << len;
        string q = ss.str();
        if (len == (int)s.size() - q.size()) {
            break;
        }
    }
    
    // Check for large string construction
    check_large_string_construction_invariant(len);

    for (int i = 0; i < s.size(); ++i) {
        ++cnt[s[i] - '0'];
    }

    // Check for extensive character counting
    check_character_counting_invariant(s.size());

    stringstream ss;
    ss << len;
    string q = ss.str();
    for (int i = 0; i < q.size(); ++i) {
        --cnt[q[i] - '0'];
    }
    
    string s2;
    cin >> s2;
    for (int i = 0; i < s2.size(); ++i) {
        ++cnt2[s2[i] - '0'];
    }
    
    string ans;
    string ans2 = s2;
    if (s2[0] != '0') {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i] - cnt2[i]; ++j) ans2.push_back(i + '0');
        }
    } else {
        ans2.clear();
        for (int i = 0; i < len; ++i) {
            ans2.push_back('9');
        }
    }

    int qq = 1;
    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] != s2[0]) {
            if (s2[i] < s2[0]) {
                qq = 0;
                break;
            }
            if (s2[i] > s2[0]) {
                qq = 2;
                break;
            }
        }
    }

    if (cnt[0] > 0) {
        for (int i = 1; i < 10; ++i) {
            if (cnt[i] > cnt2[i]) {
                --cnt[i];
                ans.push_back(i + '0');
                goto ohi3;
            }
        }
        cout << ans2 << '\n';
        return 0;
    ohi3:;
    }

    if (qq == 0) {
        for (int i = 0; i < 10; ++i) {
            if (i + '0' == s2[0]) {
                for (int j = 0; j < s2.size(); ++j) {
                    ans.push_back(s2[j]);
                }
            }
            for (int j = 0; j < cnt[i] - cnt2[i]; ++j) ans.push_back(i + '0');
        }
    } else {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i] - cnt2[i]; ++j) ans.push_back(i + '0');
            if (i + '0' == s2[0]) {
                for (int j = 0; j < s2.size(); ++j) {
                    ans.push_back(s2[j]);
                }
            }
        }
    }

    ans = min(ans, ans2);
    cout << ans << '\n';
}