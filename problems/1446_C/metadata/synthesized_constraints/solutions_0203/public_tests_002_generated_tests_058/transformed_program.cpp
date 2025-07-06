#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_recursion_depth_invariant(size_t setSize, long long bit) {
    if (setSize > 1000 && bit > 15) { // Example threshold values for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - high recursion depth or branching factor!" << endl;
        abort();
    }
}

void check_bitmask_invariant(size_t setSize, long long uniqueBitCount) {
    if (setSize > 500 && uniqueBitCount > 20) { // Example threshold values for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - inefficient bitmask operations!" << endl;
        abort();
    }
}

void check_set_operations_invariant(size_t onSize, size_t ofSize) {
    if (onSize > 100 && ofSize > 100) { // Example threshold values for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - excessive set operations!" << endl;
        abort();
    }
}

long long solve(set<long long> a, long long bit) {
    check_recursion_depth_invariant(a.size(), bit); // Check recursion depth
    if ((long long)(a.size()) <= 1) return 0;
    if (bit <= 0) return 0;
    set<long long> on, of;
    for (auto v : a) {
        if (v & 1 << bit)
            on.insert(v ^ 1 << bit);
        else
            of.insert(v);
    }
    check_set_operations_invariant(on.size(), of.size()); // Check set operations
    if ((long long)(on.size()) <= 1) return solve(of, bit - 1);
    if ((long long)(of.size()) <= 1) return solve(on, bit - 1);
    return min((long long)(on.size()) - 1 + solve(of, bit - 1),
               (long long)(of.size()) - 1 + solve(on, bit - 1));
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
    srand(time(NULL));
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    long long t = 1;
    for (long long _ = 0; _ < (t); _++) solve();
}