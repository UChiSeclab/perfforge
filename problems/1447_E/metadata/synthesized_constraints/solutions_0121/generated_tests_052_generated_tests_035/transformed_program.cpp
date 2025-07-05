#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_recursion_depth(int currentDepth, int maxDepth) {
    if (currentDepth > maxDepth) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth!" << endl;
        abort();
    }
}

void check_imbalance(size_t size1, size_t size2) {
    if (size1 > 2 * size2 || size2 > 2 * size1) {
        cerr << "Warning: Performance bottleneck condition triggered - imbalanced set partitions!" << endl;
        abort();
    }
}

void check_dense_bits(size_t denseCount, size_t threshold) {
    if (denseCount > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - dense bit pattern distribution!" << endl;
        abort();
    }
}

int dfs(set<int> s, int t, int currentDepth) {
    // Check for recursion depth
    check_recursion_depth(currentDepth, 30);

    if (s.empty()) return 0;
    if (s.size() == 1) return 1;

    set<int> sd[2];
    for (int si : s) {
        sd[si >> t & 1].insert(si);
    }

    // Check for set imbalance
    check_imbalance(sd[0].size(), sd[1].size());

    return max(dfs(sd[0], t - 1, currentDepth + 1) + min((int)sd[1].size(), 1),
               dfs(sd[1], t - 1, currentDepth + 1) + min((int)sd[0].size(), 1));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        s.insert(b);
    }

    // Check for dense bit distribution in the input set
    size_t denseCount = 0;
    for (int b : s) {
        if (__builtin_popcount(b) > 15) {
            ++denseCount;
        }
    }
    check_dense_bits(denseCount, n / 4);

    cout << n - dfs(s, 29, 0) << "\n";
    return 0;
}