#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, maxN = 1005, maxK = 10;

// Function to check recursion depth and branching factor invariant
void check_recursion_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Recursion depth and branching factor too high with large k!" << endl;
        abort();
    }
}

// Function to check excessive path checking invariant
void check_reachability_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Excessive checks for reachability to house number 1!" << endl;
        abort();
    }
}

// Function to check combinatorial explosion invariant
void check_combinatorial_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Combinatorial explosion due to large k!" << endl;
        abort();
    }
}

int power(const int n, const int k) {
    if (!k) return 1;
    int res = power(n, k >> 1);
    res = (1LL * (res) * (res) % MOD);
    if (k & 1) res = (1LL * (res) * (n) % MOD);
    return res;
}

int n, res, k, p[maxK];

void rec(const int i) {
    static function<bool(const int)> can = [&](const int x) -> bool {
        static int cnt = 0, vis[maxN];
        ++cnt;
        static function<bool(const int)> walk = [&](const int x) -> bool {
            if (x == 1) return true;
            if (vis[x] == cnt) return false;
            vis[x] = cnt;
            return walk(p[x]);
        };
        return walk(x);
    };

    if (i < 1) {
        for (int i = (2), _b = (k); i <= _b; ++i)
            if (!can(i)) return;
        res = (((res) + (1)) % MOD);
        return;
    }

    for (p[i] = 1; p[i] <= k; ++p[i]) rec(i - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;

    // Check the combinatorial explosion and recursion depth
    check_combinatorial_invariant(k == 8);
    check_recursion_invariant(k == 8);

    rec(k);

    // Check excessive path checking before executing the power function
    check_reachability_invariant(k == 8);

    res = (1LL * (res) * (power(n - k, n - k)) % MOD);
    cout << res << '\n';
    return 0;
}