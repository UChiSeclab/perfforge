#include <bits/stdc++.h>
using namespace std;

int n, k;
int go[100];
int chega[100];

void check_high_recursion_invariant(int k) {
    if (k > 7) { // Given k <= 8, a high value triggers potential deep recursion
        cerr << "Warning: high_recursion_invariant triggered - high recursion depth or branching factor" << endl;
        abort();
    }
}

void check_exponential_growth_invariant(int k) {
    if (k > 6) { // Trigger if k is large, leading to exponential path exploration
        cerr << "Warning: exponential_growth_invariant triggered - exponential growth in recursive calls" << endl;
        abort();
    }
}

int dfs(int v) {
    if (v == 0) return chega[v] = 1;
    if (chega[v] == 0) return 0;
    chega[v] = 0;
    return chega[v] = dfs(go[v]);
}

bool check() {
    for (int i = 0; i < k; i++) chega[i] = -1;
    for (int i = 0; i < k; i++)
        if (chega[i] == -1) {
            chega[i] = dfs(i);
        }
    for (int i = 0; i < k; i++)
        if (!chega[i]) return 0;
    return 1;
}

long long solve(int pos) {
    if (pos == k) {
        if (check()) return 1;
        return 0;
    }
    long long ret = 0;
    for (int i = 0; i < k; i++) {
        go[pos] = i;
        ret += solve(pos + 1);
        if (ret >= 1000000007) ret -= 1000000007;
    }
    return ret;
}

int main() {
    cin >> n >> k;
    
    check_high_recursion_invariant(k); // Check for high recursion depth
    check_exponential_growth_invariant(k); // Check for exponential growth potential

    long long ans = 1;
    long long m = (n - k);
    for (int i = 0; i < n - k; i++) {
        ans *= m;
        ans %= 1000000007;
    }
    ans *= solve(0);
    ans %= 1000000007;
    cout << ans << endl;
    return 0;
}