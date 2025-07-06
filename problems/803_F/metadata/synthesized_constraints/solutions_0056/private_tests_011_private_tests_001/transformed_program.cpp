#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, x, a[N], p[N], f[N], ma = 0;

// Checker for high 'ma' value
void check_high_ma_invariant(int ma) {
    if (ma > 50000) {  // Threshold based on potential dense operations
        cerr << "Warning: High 'ma' value detected - potential quadratic operations!" << endl;
        abort();
    }
}

// Checker for frequent divisor counting
void check_frequent_divisor_counting(int ma, const int* a) {
    int frequentDivisors = 0;
    for (int i = 1; i <= ma; i++) {
        if (a[i] > 0) frequentDivisors++;
    }
    if (frequentDivisors > 50000) {  // Threshold based on divisor density
        cerr << "Warning: Frequent divisor counting detected - high density of operations!" << endl;
        abort();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ma = max(ma, x);
        a[x]++;
    }
    
    // Check for high 'ma' value
    check_high_ma_invariant(ma);
    
    // Check for frequent divisor counting
    check_frequent_divisor_counting(ma, a);

    p[0] = 1;
    for (int i = 1; i <= n; i++) p[i] = 2 * p[i - 1] % MOD;
    for (int i = 1; i <= ma; i++) {
        int s = 0;
        for (int j = i; j <= ma; j += i) s += a[j];
        f[i] = (p[s] - 1 + MOD) % MOD;
    }
    for (int i = ma; i > 0; i--) {
        for (int j = 2; i * j <= ma; j++) f[i] = (f[i] - f[i * j] + MOD) % MOD;
    }
    cout << f[1];
    return 0;
}