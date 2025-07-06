#include <bits/stdc++.h>
using namespace std;

// Checker for nested loop overhead
void check_nested_loop_invariant(int s_len, int t_len) {
    if (s_len > 150 && t_len < 50) {
        cerr << "Warning: Performance bottleneck due to excessive iterations in nested loops!" << endl;
        abort();
    }
}

// Checker for character matching sparsity
void check_character_matching_invariant(int s_len, int t_len, const string &s, const string &t) {
    int count = 0;
    for (char ch : t) {
        if (s.find(ch) == string::npos) {
            count++;
        }
    }
    if (t_len < s_len / 4 && count > (s_len - t_len) / 2) {
        cerr << "Warning: Performance bottleneck due to sparse distribution of t's characters in s!" << endl;
        abort();
    }
}

// Checker for subsequence verification overhead
void check_subsequence_verification_invariant(int s_len, const string &s, const string &t) {
    int t_index = 0;
    int gaps = 0;
    for (char ch : s) {
        if (t_index < t.size() && ch == t[t_index]) {
            t_index++;
        } else {
            gaps++;
        }
    }
    if (gaps > s_len - t.size()) {
        cerr << "Warning: Performance bottleneck due to excessive non-matching segments in s!" << endl;
        abort();
    }
}

void solve() {
    long long int i, j, k, c, ans = 0;
    string s, t;
    cin >> s >> t;
    
    // Get sizes of s and t
    long long int l = s.size();
    int t_len = t.size();
    
    // Insert Invariants Check before starting heavy computation
    check_nested_loop_invariant(l, t_len);
    check_character_matching_invariant(l, t_len, s, t);
    check_subsequence_verification_invariant(l, s, t);

    for (i = 0; i < l; i++) {
        for (j = i; j < l; j++) {
            c = 0;
            for (k = 0; k < l; k++) {
                if (k >= i && k <= j) continue;
                if (s[k] == t[c]) c++;
            }
            if (c == t.size()) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
    return;
}

int main() {
    long long int q = 1;
    while (q--) {
        solve();
    }
    return 0;
}