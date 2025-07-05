#include <bits/stdc++.h>
using namespace std;

// Checker function for nested loop performance
void check_nested_loop_invariant(int n1) {
    if (n1 > 190) {
        cerr << "Warning: Performance bottleneck due to large string length triggering nested loop iterations!" << endl;
        abort();
    }
}

// Checker function for subsequence performance
void check_subsequence_invariant(int n1, int n2) {
    if (n1 > 1.5 * n2) {
        cerr << "Warning: Performance bottleneck due to extensive subsequence checks!" << endl;
        abort();
    }
}

// Checker function for substring construction performance
void check_substring_construction_invariant(int n1, int n2) {
    if (n1 - n2 > 100) {
        cerr << "Warning: Performance bottleneck due to repeated substring construction!" << endl;
        abort();
    }
}

void solve() {
    string s, t;
    cin >> s >> t;
    int n1 = s.size(), n2 = t.size();
    
    // Performance checks before entering the main algorithm
    check_nested_loop_invariant(n1);
    check_subsequence_invariant(n1, n2);
    check_substring_construction_invariant(n1, n2);

    auto has_subseq = [&](string cs) {
        int j = 0;
        for (int i = 0; i < (int)cs.size(); i++) {
            if (cs[i] == t[j]) j++;
        }
        return (j == n2);
    };

    int ans = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = i; j < n1; j++) {
            string temp = "";
            for (int k = 0; k < i; k++) {
                temp += s[k];
            }
            for (int k = j + 1; k < n1; k++) {
                temp += s[k];
            }
            if (has_subseq(temp)) {
                ans = max(ans, j - i + 1);
            } else
                break;
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}