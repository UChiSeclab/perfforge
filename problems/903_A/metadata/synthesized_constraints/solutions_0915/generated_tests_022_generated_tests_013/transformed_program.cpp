#include <bits/stdc++.h>
using namespace std;

void check_divisibility_invariant(int x) {
    // Check for indivisibility by 3, 7, or 10 as a potential bottleneck
    if (x % 3 != 0 && x % 7 != 0 && x % 10 != 0) {
        cerr << "Warning: Performance bottleneck condition triggered due to indivisibility by 3, 7, or 10!" << endl;
        abort();
    }
}

void check_near_multiple_invariant(int x) {
    // Check if x is large and not a multiple of 3 or 7, indicating potential slow path
    if (x > 50 && (x % 3 != 0 && x % 7 != 0)) {
        cerr << "Warning: Performance bottleneck triggered - high recursion due to large number not a multiple of 3 or 7!" << endl;
        abort();
    }
}

void check_recursive_exploration_invariant(int x) {
    // Check if x is likely to cause recursive exploration issues
    if (x > 20 && x % 10 == 1) {
        cerr << "Warning: Performance degradation likely due to recursive exploration without early termination!" << endl;
        abort();
    }
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
long long powmod(long long a, long long b, long long MOD) {
    long long ans = 1;
    while (b) {
        if (b % 2) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

int bj, aa;

void dfs(int a) {
    if (!a) {
        bj = 1;
        return;
    }
    if (a >= 3) dfs(a - 3);
    if (a >= 7) dfs(a - 7);
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t--) {
        cin >> aa;

        // Check performance-characterizing invariants before running DFS
        check_divisibility_invariant(aa);
        check_near_multiple_invariant(aa);
        check_recursive_exploration_invariant(aa);

        bj = 0;
        dfs(aa);
        if (!bj)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}