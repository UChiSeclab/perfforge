#include <bits/stdc++.h>
using namespace std;

// Check 1: High Iteration Count with Near Maximum `k`
void check_high_iteration_invariant(long long n, long long b, long long k) {
    if ((b > n / 2) && (k > n / 2)) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count with large k!" << endl;
        abort();
    }
}

// Check 2: Dense Range of Accessible Floors
void check_dense_range_invariant(long long n, long long a, long long b) {
    if ((b > a) && ((b - a) > n / 4)) {
        cerr << "Warning: Performance bottleneck condition triggered - dense range of accessible floors!" << endl;
        abort();
    }
}

// Check 3: Large Number of Valid Selections
void check_large_selection_invariant(long long n, long long a, long long b) {
    if ((b > a) && ((n - b) + (a - 1) > n / 4)) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of valid selections!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n, a, b, k, mod = 1e9 + 7;
    cin >> n >> a >> b >> k;

    // Inserting checks after reading inputs
    check_high_iteration_invariant(n, b, k);
    check_dense_range_invariant(n, a, b);
    check_large_selection_invariant(n, a, b);

    long long int f[n + 2], temp[n + 2];
    memset(f, 0, sizeof(f));
    memset(temp, 0, sizeof(temp));

    if (b > a) {
        for (int i = a; i < b; i++) f[i] = 1;
        for (int i = 0; i < k; i++) {
            for (int j = 1; j < b; j++) {
                long long int ind = (b + j) / 2;
                if (ind * 2 == b + j) ind--;
                temp[j] += (f[ind] - f[j] + mod) % mod;
                temp[j] += f[j - 1];
            }
            for (int j = 1; j < b; j++) f[j] = temp[j] % mod, temp[j] = 0;
            for (int j = 1; j < b; j++) f[j] = (f[j] + f[j - 1]) % mod;
        }
        cout << f[b - 1] << endl;
        return 0;
    }

    for (int i = a; i <= n; i++) f[i] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = b + 1; j <= n; j++) {
            temp[j] += (f[n] - f[j] + mod) % mod;
            long long int ind = (b + j) / 2;
            temp[j] += (f[j - 1] - f[ind] + mod) % mod;
        }
        for (int j = b + 1; j <= n; j++) f[j] = temp[j] % mod, temp[j] = 0;
        for (int j = b + 1; j <= n; j++) f[j] = (f[j] + f[j - 1]) % mod;
    }
    cout << f[n] << endl;
    return 0;
}