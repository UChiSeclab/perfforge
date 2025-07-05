#include <bits/stdc++.h>
using namespace std;

int n;
map<pair<int, long long>, int> m;

void check_recursion_depth(int s) {
    if (s > 50) {
        cerr << "Warning: Recursion depth invariant triggered - high depth due to large s" << endl;
        abort();
    }
}

void check_cache_usage(int cacheSize, int distinctStates) {
    if (cacheSize > 50000 && distinctStates > 1000) {
        cerr << "Warning: Cache usage invariant triggered - high number of distinct states with large cache size" << endl;
        abort();
    }
}

void check_combinatorial_complexity(int n, int maxStones) {
    if (n > 500 && maxStones > 50) {
        cerr << "Warning: Combinatorial complexity invariant triggered - large n and high stone counts" << endl;
        abort();
    }
}

int f(int s, long long mask) {
    check_recursion_depth(s);  // Check recursion depth before proceeding

    if (s == 0) {
        return 0;
    }
    pair<int, long long> node = make_pair(s, mask);
    if (m.count(node)) {
        return m[node];
    }
    vector<bool> v(s + 1, false);
    for (int i = 1; i <= s; i++) {
        if ((1LL << (i - 1)) & mask) {
            v[f(s - i, mask ^ (1LL << (i - 1)))] = true;
        }
    }
    for (int i = 0; i <= s; i++) {
        if (!v[i]) {
            m[node] = i;
            break;
        }
    }
    return m[node];
}

int main() {
    scanf("%d", &n);
    
    int maxStones = 0;
    int ans = 0;
    int s;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &s);
        maxStones = max(maxStones, s);
        ans ^= f(s, (1LL << s) - 1);
    }
    
    // Check combinatorial complexity after input processing
    check_combinatorial_complexity(n, maxStones);
    
    // Check cache usage after the computation
    check_cache_usage(m.size(), n);
    
    printf("%s\n", ans == 0 ? "YES" : "NO");
    return 0;
}