#include <bits/stdc++.h>
using namespace std;
long long a[5010];
vector<long long> v;

// Performance check functions
void check_single_denomination_invariant(int n) {
    if (n == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - single denomination." << endl;
        abort();
    }
}

void check_large_withdrawal_invariant(long long Q, long long max_den, int n) {
    if (Q > max_den * n) {
        cerr << "Warning: Performance bottleneck condition triggered - withdrawal amount too large compared to bill denominations." << endl;
        abort();
    }
}

void check_large_k_invariant(int k) {
    if (k > 15) { // Assuming a threshold based on problem constraints
        cerr << "Warning: Performance bottleneck condition triggered - large k value leading to extensive loops." << endl;
        abort();
    }
}

int main() {
    int n, i, k, q, j, co = 0, y, p;
    long long Q, F, Answer;
    cin >> n >> k;
    
    check_single_denomination_invariant(n);
    check_large_k_invariant(k);

    for (i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
    }

    cin >> q;
    while (q--) {
        scanf("%I64d", &Q);

        check_large_withdrawal_invariant(Q, a[n-1], n);

        Answer = -1;
        for (i = 0; i < n; i++) {
            for (j = 1; j <= k; j++) {
                if (j == 1) {
                    y = lower_bound(a, a + n, Q) - &a[0];
                    if (a[y] == Q) {
                        Answer = 1;
                    }
                }
                F = Q - (j * a[i]);
                for (p = 1; p <= k - j; p++) {
                    y = lower_bound(a, a + n, F / p) - &a[0];
                    if (p * a[y] == F && (j + p < Answer || Answer == -1)) Answer = p + j;
                }
            }
        }
        v.push_back(Answer);
    }
    
    for (j = 0; j < v.size(); j++) cout << v[j] << "\n";
    return 0;
}