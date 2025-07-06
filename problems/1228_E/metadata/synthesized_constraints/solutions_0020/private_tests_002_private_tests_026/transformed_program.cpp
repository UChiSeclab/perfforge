#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, k;
int dp[300][300];
int A[300], B[300];
int cc[300][300];

void check_deep_recursion_invariant(int n, int k) {
    if (n > 200 && k > 1000000) { // Thresholds based on problem constraints
        cerr << "Warning: Deep recursion invariant triggered - large n and k may cause slowdown" << endl;
        abort();
    }
}

void check_combinatorial_explosion_invariant(int n, int k) {
    if (n > 200 && k > 1000000) { // Similar threshold as this relates to the recursive calls
        cerr << "Warning: Combinatorial explosion invariant triggered - large n and k leading to extensive computations" << endl;
        abort();
    }
}

void check_excessive_iterations_invariant(int n, int k) {
    if (k > 1000000) { // Keeping k threshold high due to its large range
        cerr << "Warning: Excessive iterations invariant triggered - high k value leading to more iterations" << endl;
        abort();
    }
}

int ex(int a, int x) {
    if (a == k - 1) return A[x];
    return B[x];
}

int C(int n, int k) {
    if (k > n || k < 0 || n < 0) return 0;
    if (k == 0 || n == k) return 1;
    int &res = cc[n][k];
    if (res != -1) return res;
    return res = (C(n - 1, k - 1) + C(n - 1, k)) % mod;
}

int calc(int i, int x, int y) {
    if (i == n) {
        if (x == n) return 1;
        return 0;
    }
    int &res = dp[i][x];
    if (res != -1) return res;
    res = 0;
    for (int c = 1; c <= y; c++) {
        res += ex(k, x) * 1ll * C(y, c) % mod * 1ll * ex(k - 1, y - c) % mod * 1ll *
               calc(i + 1, x + c, y - c) % mod;
        if (res >= mod) res -= mod;
    }
    res += ((ex(k, x) - ex(k - 1, x) + mod) % mod) * 1ll * ex(k - 1, y) % mod *
           1ll * calc(i + 1, x, y) % mod;
    if (res >= mod) res -= mod;
    return res;
}

int main() {
    cin >> n >> k;

    // Check performance invariants after reading inputs
    check_deep_recursion_invariant(n, k);
    check_combinatorial_explosion_invariant(n, k);
    check_excessive_iterations_invariant(n, k);

    if (k == 1 || n == 1) {
        cout << 1 << endl;
        return 0;
    }
    memset(dp, -1, sizeof dp);
    memset(cc, -1, sizeof cc);
    A[0] = 1;
    for (int i = 1; i < 300; i++) A[i] = (k - 1) * 1ll * A[i - 1] % mod;
    B[0] = 1;
    for (int i = 1; i < 300; i++) B[i] = k * 1ll * B[i - 1] % mod;
    cout << calc(0, 0, n) << endl;
    return 0;
}