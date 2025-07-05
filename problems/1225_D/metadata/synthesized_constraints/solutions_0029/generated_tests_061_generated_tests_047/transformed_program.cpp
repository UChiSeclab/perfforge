#include <bits/stdc++.h>
using namespace std;

int power(int a, int b, int c, int ans = 1) {
    for (; b; b >>= 1, a = (long long)a * a % c)
        if (b & 1) ans = (long long)ans * a % c;
    return ans;
}

const int NN = 100100;
int a[NN], flag[NN], prime[NN], np, qf, qb, deg[111], fac[111];
long long q[NN];

void check_prime_factorization_invariant(int first, int k) {
    if (first > 1000 || k > 50) { // Example threshold values
        cerr << "Warning: Prime factorization invariant triggered - complex factorization" << endl;
        abort();
    }
}

void check_combination_invariant(int cnt) {
    if (cnt > 10) { // Example threshold value for number of prime factors
        cerr << "Warning: Combination invariant triggered - excessive combinations" << endl;
        abort();
    }
}

void check_map_lookup_invariant(int qb) {
    if (qb > 1000) { // Example threshold value for number of combinations
        cerr << "Warning: Map lookup invariant triggered - repeated checks" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    if (k > 32) {
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += a[i] == 1;
        printf("%I64d\n", (long long)cnt * (cnt - 1) / 2);
        return 0;
    }
    map<long long, int> mp;
    for (int i = 0; i < n; i++) mp[a[i]]++;
    sort(a, a + n);
    long long ans = 0;
    for (int i = 2; i < NN; i++) {
        if (!flag[i]) prime[np++] = i, flag[i] = i;
        for (int j = 0; j < np && prime[j] <= flag[i] && prime[j] * i < NN; j++)
            flag[i * prime[j]] = prime[j];
    }
    for (int first = 1;; first++) {
        check_prime_factorization_invariant(first, k); // Check for prime factorization complexity

        if (log(first) * k > log(10) * 10 + 1e-5) break;
        int cnt = 0;
        for (int u = first; u > 1;) {
            int v = flag[u];
            deg[cnt] = 0;
            while (flag[u] == v) u /= v, deg[cnt]++;
            deg[cnt] *= k;
            fac[cnt++] = v;
        }

        check_combination_invariant(cnt); // Check for excessive combinations

        qb = 0;
        q[qb++] = 1;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0, z = qb; j < z; j++) {
                long long mid = 1;
                for (int k = 0; k < deg[i]; k++) {
                    mid *= fac[i];
                    q[qb++] = q[j] * mid;
                }
            }
        }

        check_map_lookup_invariant(qb); // Check for repeated map lookups

        long long N = q[qb - 1];
        for (int i = 0; i < qb; i++)
            if (q[i] * q[i] <= N) {
                if (mp.count(q[i]) && mp.count(N / q[i])) {
                    long long t = mp[q[i]], t1 = mp[N / q[i]];
                    if (q[i] * q[i] == N)
                        ans += t * (t - 1) / 2;
                    else
                        ans += t * t1;
                }
            }
    }
    cout << ans << endl;
    return 0;
}