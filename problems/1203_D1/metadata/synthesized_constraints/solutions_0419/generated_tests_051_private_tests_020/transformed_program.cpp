#include <bits/stdc++.h>
using namespace std;

// Checker for high iteration count in nested loops
void check_iteration_invariant(int n1) {
    if (n1 > 150) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count in nested loops!" << endl;
        abort();
    }
}

// Checker for excessive string constructions
void check_string_construction_invariant(int n1, int n2) {
    if ((n1 - n2) > 100) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive string constructions!" << endl;
        abort();
    }
}

// Checker for frequent subsequence checks
void check_subsequence_invariant(int callCount) {
    if (callCount > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent subsequence checks!" << endl;
        abort();
    }
}

void solve() {
    string s, t;
    cin >> s >> t;
    int n1 = s.size(), n2 = t.size();
    
    // Insert checker for iteration invariant
    check_iteration_invariant(n1);
    
    // Insert checker for string construction invariant
    check_string_construction_invariant(n1, n2);

    auto has_subseq = [&](string cs) {
        int j = 0;
        for (int i = 0; i < (int)cs.size(); i++) {
            if (cs[i] == t[j]) j++;
        }
        return (j == n2);
    };

    int ans = 0;
    int callCount = 0; // To count subsequence checks

    for (int i = 0; i < n1; i++) {
        for (int j = i; j < n1; j++) {
            string temp = "";
            for (int k = 0; k < i; k++) {
                temp += s[k];
            }
            for (int k = j + 1; k < n1; k++) {
                temp += s[k];
            }
            callCount++; // Increment call count for each subsequence check
            if (has_subseq(temp)) {
                ans = max(ans, j - i + 1);
            } else
                break;
        }
    }

    // Insert checker for subsequence invariant
    check_subsequence_invariant(callCount);

    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}