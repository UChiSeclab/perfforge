#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
int N, K, A[10], B[10];

// Checker functions
void check_recursive_depth_invariant(int K, int N) {
    if (K >= N) {
        cerr << "Warning: Recursive depth and branching factor are high due to K being close to N!" << endl;
        abort();
    }
}

void check_exhaustive_validity_invariant(int K) {
    if (K > 7) { // Assuming K close to 8 creates heavy checks
        cerr << "Warning: Exhaustive validity checks due to large K!" << endl;
        abort();
    }
}

void check_high_call_frequency_invariant(int K, int N) {
    if (K >= N - 1) {
        cerr << "Warning: High frequency of recursive calls!" << endl;
        abort();
    }
}

long long mod_pow(long long n, long long x) {
    long long res = 1;
    while (x) {
        if (x & 1) res = res * n % MOD;
        x >>= 1, n = n * n % MOD;
    }
    return res;
}

int is_valid(int pos, int cnt) {
    if (pos == 0) return B[pos] = 1;
    if (cnt == K) {
        return B[pos] = 0;
    }
    if (B[pos] > -1) return B[pos];
    return B[pos] = is_valid(A[pos], cnt + 1);
}

long long dfs(int x) {
    if (x == K) {
        for (int i = 0; i < K; i++) B[i] = -1;
        bool ok = true;
        for (int i = 0; i < K; i++) {
            ok &= is_valid(i, 0);
        }
        if (ok) return 1;
        return 0;
    }
    long long res = 0;
    for (int i = 0; i < K; i++) {
        A[x] = i;
        res += dfs(x + 1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;

    // Insert checks after input is taken, before any heavy computation
    check_recursive_depth_invariant(K, N);
    check_exhaustive_validity_invariant(K);
    check_high_call_frequency_invariant(K, N);

    cout << dfs(0) * mod_pow(N - K, N - K) % MOD << endl;
    return 0;
}