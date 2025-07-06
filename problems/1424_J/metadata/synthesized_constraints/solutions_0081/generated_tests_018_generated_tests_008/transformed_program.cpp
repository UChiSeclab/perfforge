#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;

// Function to check the sieve invariant
void check_sieve_invariant(int maxNumber) {
    if (maxNumber >= 1000000) {  // Check if maxNumber is close to the upper constraint
        cerr << "Warning: sieve_invariant triggered - large maxNumber causing performance bottleneck in sieve." << endl;
        abort();
    }
}

// Function to check the prefix sum invariant
void check_prefix_sum_invariant(int maxNumber) {
    if (maxNumber >= 1000000) {  // Condition as maxNumber is near the constraint
        cerr << "Warning: prefix_sum_invariant triggered - large maxNumber impacting prefix sum performance." << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, i, j;
    cin >> n;
    int a[n];
    for (i = 0; i < n; i++) cin >> a[i];
    int ma = *max_element(a, a + n);

    // Insert check after determining max element
    check_sieve_invariant(ma);
    check_prefix_sum_invariant(ma);

    vector<int> p(ma + 1, 1);
    for (int i = 2; i * i <= ma; i++) {
        if (p[i]) {
            for (int j = i * i; j <= ma; j += i) p[j] = 0;
        }
    }
    for (i = 2; i <= ma; i++) p[i] += p[i - 1];
    for (int i : a) {
        cout << p[i] - p[(int)ceil((float)sqrt(i + 1)) - 1] + 1 << "\n";
    }
    return 0;
}