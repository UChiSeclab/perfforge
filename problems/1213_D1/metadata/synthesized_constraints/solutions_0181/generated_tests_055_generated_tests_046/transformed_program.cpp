#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 998244353;
long long int hash1[400005];
long long int a[400005];

void check_excessive_halving(bool condition) {
    if (condition) {
        cerr << "Warning: Excessive halving operations needed for majority of elements!" << endl;
        abort();
    }
}

void check_sparse_frequencies(bool condition) {
    if (condition) {
        cerr << "Warning: Sparse frequency of reachable numbers leading to excessive iterations!" << endl;
        abort();
    }
}

void check_high_k_relative_to_n(bool condition) {
    if (condition) {
        cerr << "Warning: High target k relative to n with diverse elements causing slowdown!" << endl;
        abort();
    }
}

void check_significant_power_diff(bool condition) {
    if (condition) {
        cerr << "Warning: Significant power of 2 differences causing repeated doubling operations!" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    long long int n, k;
    cin >> n >> k;

    for (long long int i = 1; i <= n; i++) {
        cin >> a[i];
        hash1[a[i]]++;
    }

    // Check for high target k relative to n with diverse elements
    check_high_k_relative_to_n((k > n / 2) && (unique(a + 1, a + n + 1) > n / 2));

    // Precompute cumulative frequencies
    for (long long int i = 1; i <= 400000; i++) {
        hash1[i] += hash1[i - 1];
    }

    long long int ans = INT_MAX;
    for (long long int i = 1; i <= 200000; i++) {
        long long int ck = 0;
        long long int j = i;
        long long int tt = hash1[j] - hash1[j - 1];
        
        // Check for sparse frequencies
        check_sparse_frequencies((tt < k) && (j < 200000));

        if (tt >= k) {
            ans = min(ans, 0LL);
            break;
        }
        j *= 2;
        long long int cur = 0;
        long long int ok = 2;

        // Check for significant power of 2 differences
        check_significant_power_diff((j > 1) && ((j & (j - 1)) > 0));

        while (j <= 200000) {
            long long int freq = hash1[j + ok - 1] - hash1[j - 1];
            if (tt + freq > k) {
                freq = k - tt;
            }
            tt += freq;
            ck++;
            cur = cur + ck * freq;
            j *= 2;
            ok *= 2;
            if (tt >= k) break;
        }
        if (tt >= k) ans = min(ans, cur);
    }

    cout << ans << endl;
    return 0;
}