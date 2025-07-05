#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const long long int N = 200043;
const long long int MOD = 1000000007;

// Checker function for high divisor count
void check_high_divisor_count_invariant(long long int x, int divisorCount) {
    if (divisorCount > 100 && x > 10000) {
        cerr << "Warning: High divisor count invariant triggered!" << endl;
        abort();
    }
}

// Checker function for frequent range lookups
void check_frequent_range_lookups_invariant(int lookupCount) {
    if (lookupCount > 50) {
        cerr << "Warning: Frequent range lookups invariant triggered!" << endl;
        abort();
    }
}

// Checker function for large data structure usage
void check_large_data_structure_usage_invariant(long long int x, size_t mapSize) {
    if (mapSize > 500 && x > 10000) {
        cerr << "Warning: Large data structure usage invariant triggered!" << endl;
        abort();
    }
}

long long int add(long long int x, long long int y) {
    x = ((x % MOD) + (y % MOD)) % MOD;
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
    return x;
}

long long int mul(long long int x, long long int y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

long long int binpow(long long int x, long long int y) {
    long long int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

long long int inv(long long int x) { return binpow(x, MOD - 2); }

long long int divide(long long int x, long long int y) {
    return mul(x, inv(y));
}

unordered_map<long long int, vector<long long int>> m;

int lowerIndex(long long int ind, int n, int x) {
    int l = 0, h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (m[ind][mid] >= x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int upperIndex(long long int ind, int n, int y) {
    int l = 0, h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (m[ind][mid] <= y)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}

int countInRange(long long int ind, int n, int x, int y) {
    int lookupCount = 0;
    lookupCount = upperIndex(ind, n, y) - lowerIndex(ind, n, x) + 1;
    check_frequent_range_lookups_invariant(lookupCount);
    return lookupCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t, i, j;
    t = 1;
    while (t--) {
        long long int n;
        cin >> n;
        for (i = 1; i <= n; i++) {
            long long int x, y;
            cin >> x >> y;
            long long int ans = 0;
            int divisorCount = 0;
            for (j = 1; j * j <= x; j++) {
                if (x % j == 0) {
                    long long int a = x / j;
                    long long int b = x / a;
                    if (y != 0) {
                        long long int ctr = countInRange(a, m[a].size(), i - y, i - 1);
                        if (ctr == 0) ans++;
                        if (a != b) {
                            ctr = countInRange(b, m[b].size(), i - y, i - 1);
                            if (ctr == 0) ans++;
                        }
                    } else {
                        if (a != b) {
                            ans += 2;
                        } else {
                            ans++;
                        }
                    }
                    m[a].push_back(i);
                    if (a != b) m[b].push_back(i);
                    divisorCount += (a != b) ? 2 : 1;
                }
            }
            check_high_divisor_count_invariant(x, divisorCount);
            check_large_data_structure_usage_invariant(x, m.size());
            cout << ans << endl;
        }
    }
}