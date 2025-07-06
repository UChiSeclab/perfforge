#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance bottlenecks
void check_expansion_invariant(size_t currentSize, size_t requiredSize) {
    if (requiredSize > currentSize + 100) { // Arbitrary threshold for expansion detection
        cerr << "Warning: Performance bottleneck condition triggered - frequent string expansion!" << endl;
        abort();
    }
}

void check_set_invariant(size_t setSize) {
    if (setSize > 1000) { // Threshold for large set operations
        cerr << "Warning: Performance bottleneck condition triggered - large set operations!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(size_t stringCount, size_t maxSubstringLength) {
    if (stringCount > 100 && maxSubstringLength > 100) { // Thresholds for nested loop processing
        cerr << "Warning: Performance bottleneck condition triggered - extensive nested loop processing!" << endl;
        abort();
    }
}

void solve() {
    set<int> pos;
    string ans;
    int n;
    scanf("%d\n", &n);
    
    size_t maxSubstringLength = 0; // To track maximum length of substrings
    check_nested_loop_invariant(n, maxSubstringLength); // Initial check for nested loop processing

    for (int i(0), _l((int)(n)-1); i <= _l; ++i) {
        string s;
        getline(cin, s, ' ');

        maxSubstringLength = max(maxSubstringLength, s.size()); // Update max substring length
        
        int k;
        scanf("%d", &k);

        for (int j(0), _l((int)(k)-1); j <= _l; ++j) {
            int x;
            scanf("%d", &x);
            x -= 1;
            
            check_expansion_invariant(ans.size(), x + s.size()); // Check for string expansion
            
            while (x + ((int)s.size()) > ((int)ans.size())) {
                pos.insert(((int)ans.size()));
                ans += 'a';
            }

            check_set_invariant(pos.size()); // Check for large set operations
            
            int now(x);
            while (true) {
                auto it(pos.lower_bound(now));
                if (it == pos.end()) {
                    break;
                }
                int nxt(*it);
                if (nxt - x + 1 > ((int)s.size())) {
                    break;
                }
                ans[nxt] = s[nxt - x];
                pos.erase(nxt);
            }
        }
        scanf("\n");
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}