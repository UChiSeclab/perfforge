#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_large_range_invariant(long long a, long long b) {
    if (b - a > 1e6) {
        cerr << "Warning: large_range_invariant triggered - Range [a, b] is too large." << endl;
        abort();
    }
}

void check_prime_check_invariant(long long range, long long k) {
    if (range > 1e6 && k > 1000) {
        cerr << "Warning: prime_check_invariant triggered - Excessive primality checks expected." << endl;
        abort();
    }
}

void check_high_k_invariant(long long a, long long b, long long k) {
    if (k >= (b - a + 1) - 1) {
        cerr << "Warning: high_k_invariant triggered - High value of k relative to range size." << endl;
        abort();
    }
}

map<long long, long long> m;
long long a, b, k, ans;
vector<long long> v;

bool ckprm(long long x) {
    if (x < 2)
        return false;
    else if (x == 2 or x == 3)
        return true;
    for (long long j = 2; j * j <= x; j++) {
        if (x % j == 0) return false;
    }
    return true;
}

int main() {
    cin >> a >> b >> k;
    
    // Apply invariants checks
    check_large_range_invariant(a, b);
    check_prime_check_invariant(b - a + 1, k);
    check_high_k_invariant(a, b, k);

    v.push_back(a - 1);
    for (long long i = a; i <= b; i++) {
        if (ckprm(i)) {
            v.push_back(i);
        }
    }
    v.push_back(b + 1);
    if (v.size() - 2 < k)
        cout << -1;
    else {
        for (long long i = 0; i <= v.size() - 1 - k; i++) {
            ans = max(ans, v[i + k] - v[i]);
        }
        cout << ans;
    }
}