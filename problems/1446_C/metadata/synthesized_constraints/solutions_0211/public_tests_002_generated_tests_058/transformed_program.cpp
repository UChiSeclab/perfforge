#include <bits/stdc++.h>
using namespace std;

// Checker function for balanced splits
void check_balanced_split_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: balanced_split_invariant triggered - likely to cause deep recursion with balanced subsets!" << endl;
        abort();
    }
}

// Checker function for bit diversity
void check_bit_diversity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: bit_diversity_invariant triggered - elements result in high diversity of high-order bits!" << endl;
        abort();
    }
}

// Recursive solve function
long long solve(set<long long> a, long long bit) {
    if (bit < 0) return 0;

    set<long long> on, of;
    for (auto v : a) {
        if (v & (1 << bit))
            on.insert(v);
        else
            of.insert(v);
    }

    // Check for balanced split invariant
    check_balanced_split_invariant(on.size() > 1 && of.size() > 1);

    // Check for bit diversity invariant
    check_bit_diversity_invariant((on.size() > a.size() / 2) && (of.size() > a.size() / 2));

    if ((long long)(on.size()) <= 1) return solve(of, bit - 1);
    if ((long long)(of.size()) <= 1) return solve(on, bit - 1);
    return min(solve(on, bit - 1) + max(0LL, (long long)(of.size()) - 1),
               solve(of, bit - 1) + max(0LL, (long long)(on.size()) - 1));
}

void solve() {
    long long n;
    cin >> n;
    set<long long> a;
    for (long long _ = 0; _ < (n); _++) {
        long long x;
        cin >> x;
        a.insert(x);
    }
    cout << solve(a, 31) << '\n';
}

signed main() {
    if (0) {
        freopen("a.in", "r", stdin);
        freopen("a.out", "w", stdout);
    }
    srand(time(NULL));
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long t = 1;
    for (long long _ = 0; _ < (t); _++) solve();
}