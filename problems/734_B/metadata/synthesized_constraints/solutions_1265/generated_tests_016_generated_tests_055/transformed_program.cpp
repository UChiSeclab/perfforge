#include <bits/stdc++.h>
using namespace std;

// Checker for large minv value
void check_large_minv_invariant(long long minv) {
    if (minv > 1000000) { // Arbitrary threshold for large minv
        cerr << "Warning: Performance bottleneck due to large minv value!" << endl;
        abort();
    }
}

// Checker for imbalance in digit distribution
void check_imbalance_invariant(long long k2, long long k3, long long k5, long long k6) {
    if (k3 > max(k2, max(k5, k6)) * 10) { // Arbitrary factor indicating imbalance
        cerr << "Warning: Performance bottleneck due to imbalance in digit distribution!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int ara[4];
    for (int i = 0; i < 4; i++) cin >> ara[i];
    long long int k2 = ara[0];
    long long int k3 = ara[1];
    long long int k5 = ara[2];
    long long int k6 = ara[3];

    // Check for potential performance bottlenecks
    check_imbalance_invariant(k2, k3, k5, k6);

    long long int sum = -1;
    long long minv = min(k2, min(k5, k6));

    // Check after calculating minv
    check_large_minv_invariant(minv);

    for (int i = 0; i <= minv; i++) {
        long long a = 256LL * i + 32LL * min(ara[0] - i, ara[1]);
        sum = max(sum, a);
    }
    cout << sum;
}