#include <bits/stdc++.h>
using namespace std;

map<pair<long long, int>, int> memo;
int n, s, Xor;

void check_recursive_depth(int x) {
    if (x > 50) {  // Arbitrary threshold based on maximum si and problem understanding
        cerr << "Warning: Performance bottleneck condition triggered - excessive recursion depth!" << endl;
        abort();
    }
}

void check_mask_size(long long mask) {
    if (__builtin_popcountll(mask) > 55) {  // Threshold based on large mask state space
        cerr << "Warning: Performance bottleneck condition triggered - large mask state space!" << endl;
        abort();
    }
}

void check_memo_efficiency(int memoSize) {
    if (memoSize > 50000) {  // Arbitrary large number indicating inefficiency
        cerr << "Warning: Performance bottleneck condition triggered - inefficient memoization!" << endl;
        abort();
    }
}

int solve(int x, long long mask) {
    check_recursive_depth(x);  // Check for deep recursion
    check_mask_size(mask);     // Check for large mask

    if (memo.count({mask, x})) return memo[{mask, x}];

    if (x == 0) {
        memo[{mask, x}] = 0;
        return 0;
    }

    int grundy = 0;
    vector<int> mark(65, 0);
    for (int i = 1; i <= x; i++) {
        if (mask & (1ll << i)) continue;
        mark[solve(x - i, mask | (1ll << i))] = 1;
        while (mark[grundy]) grundy++;
    }
    memo[{mask, x}] = grundy;

    check_memo_efficiency(memo.size());  // Check for memoization efficiency

    return grundy;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &s);
        Xor ^= solve(s, 0);
    }
    printf((Xor) ? "NO" : "YES");
    return 0;
}