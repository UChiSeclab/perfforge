#include <bits/stdc++.h>
using namespace std;
const long long Mod = 998244353;
int n, m, k;
long long dp[2010][2010];

void check_deep_recursion_invariant(int n) {
    if (n > 900) { // check for deep recursion potential due to high n
        cerr << "Warning: deep_recursion_invariant triggered - large recursion depth due to high n" << endl;
        abort();
    }
}

void check_branching_invariant(int k, int n) {
    if (k < 10 || k > n - 10) { // check for extensive branching
        cerr << "Warning: branching_invariant triggered - broad branching due to extreme k values" << endl;
        abort();
    }
}

void check_memoization_invariant(int n, int k) {
    if (n * k > 1800000) { // check for insufficient memoization efficiency
        cerr << "Warning: memoization_invariant triggered - high recomputation in recursion" << endl;
        abort();
    }
}

long long Rec(int i, int k) {
    if (i == n) return (k == 0);
    if (dp[i][k] != -1) return dp[i][k];
    long long Res1 = Rec(i + 1, k);
    long long Res2 = ((Rec(i + 1, k - 1) % Mod) * ((m - 1) % Mod)) % Mod;
    return dp[i][k] = ((Res1 % Mod) + (Res2 % Mod)) % Mod;
}

int main() {
    cin >> n >> m >> k;
    
    // Insert performance-checking invariants
    check_deep_recursion_invariant(n);
    check_branching_invariant(k, n);
    check_memoization_invariant(n, k);
    
    memset(dp, -1, sizeof(dp));
    cout << ((m % Mod) * (Rec(1, k) % Mod)) % Mod;
    return 0;
}