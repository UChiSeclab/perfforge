#include <bits/stdc++.h>
using namespace std;

long long n, k;
const long long mod = 1e9 + 7;
long long p[9], used[9];
vector<long long> r[9];
long long tt = 0;

// Permutation generation invariant checker
void check_permutation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: permutation_invariant triggered - high k value causing excessive permutations" << endl;
        abort();
    }
}

// Graph traversal invariant checker
void check_bfs_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: bfs_invariant triggered - high iteration count in BFS due to dense connections" << endl;
        abort();
    }
}

bool check() {
    for (long long i = 1; i <= k; i++) r[i].clear();
    for (long long i = 1; i <= k; i++) r[p[i]].push_back(i);
    for (long long i = 1; i <= k; i++) used[i] = 0;
    long long q[11], h = 1, t = 1;
    q[1] = 1;
    used[1] = true;
    while (h <= t) {
        long long u = q[h];
        h++;
        for (long long i = 0; i < r[u].size(); i++) {
            if (!used[r[u][i]]) used[r[u][i]] = true, q[++t] = r[u][i];
            tt++;
        }
    }

    // Check BFS invariant for high iteration due to dense connections
    check_bfs_invariant(tt > 50000); // Example threshold for BFS iterations

    for (long long i = 1; i <= k; i++)
        if (!used[i]) return false;
    return true;
}

long long ksm(long long x, long long t) {
    long long res = 1;
    while (t) {
        if (t & 1) res = res * x % mod;
        x = x * x % mod;
        t /= 2;
    }
    return res;
}

signed main() {
    cin >> n >> k;

    // Check permutation invariant for high k value
    check_permutation_invariant(k > 7); // Check if k is causing excessive permutations

    p[1] = 1;
    for (long long i = 2; i <= k; i++) p[i] = 1;
    long long ans = 0;
    long long tim = 0;

    do {
        ans += check();
        long long t = k;
        while (p[t] == k) p[t--] = 1;
        p[t]++;
    } while (p[0] == 0);

    cout << ans * ksm(n - k, n - k) % mod;
    return 0;
}