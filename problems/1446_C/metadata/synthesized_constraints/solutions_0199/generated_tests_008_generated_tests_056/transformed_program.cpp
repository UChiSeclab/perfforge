#include <bits/stdc++.h>
using namespace std;

// Helper functions for performance characterization
void check_dfs_invariant(int depth, int branching_factor) {
    if (depth > 31 && branching_factor > 20) {  // Example thresholds for depth and branching
        cerr << "Warning: dfs_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

void check_inefficient_distribution(const set<int>& _0, const set<int>& _1, int dep) {
    if (_0.size() > _1.size() * 2 || _1.size() > _0.size() * 2) {  // Significant imbalance threshold
        cerr << "Warning: inefficient_distribution triggered - uneven element distribution in depth " << dep << endl;
        abort();
    }
}

void check_frequent_recursion(const set<int>& current_set, int depth) {
    if (current_set.size() > 10 && depth > 0) {  // Threshold for recursion without effective size reduction
        cerr << "Warning: frequent_recursion triggered - frequent recursive calls without effective reduction" << endl;
        abort();
    }
}

template <typename T>
inline void read(T &x) {
    x = 0;
    char c = getchar(), f = 0;
    for (; c < '0' || c > '9'; c = getchar())
        if (!(c ^ 45)) f = 1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = (x << 1) + (x << 3) + (c ^ 48);
    if (f) x = -x;
}

set<int> s;
int n;

inline int dfs(const set<int> &s, int dep = 31) {
    set<int> _0, _1;
    check_frequent_recursion(s, dep);  // Check recursion without effective size reduction
    for (set<int>::iterator i = s.begin(); i != s.end(); i++)
        if ((*i >> dep) & 1)
            _1.insert(*i);
        else
            _0.insert(*i);

    check_inefficient_distribution(_0, _1, dep);  // Check uneven distribution of elements

    if ((int)_0.size() <= 1 && (int)_1.size() <= 1) return _0.size() + _1.size();
    if ((int)_0.size() <= 1) return dfs(_1, dep - 1) + _0.size();
    if ((int)_1.size() <= 1) return dfs(_0, dep - 1) + _1.size();

    check_dfs_invariant(dep, _0.size() + _1.size());  // Check depth and branching before making recursive calls

    return 1 + max(dfs(_0, dep - 1), dfs(_1, dep - 1));
}

int main() {
    read(n);
    for (int i = 1, x; i <= n; i++) read(x), s.insert(x);
    return printf("%d\n", n - dfs(s)), 0;
}