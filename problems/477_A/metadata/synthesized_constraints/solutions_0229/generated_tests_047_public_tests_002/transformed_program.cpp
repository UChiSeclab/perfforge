#include <bits/stdc++.h>
using namespace std;

int add(int a, int b) {
    a += b;
    return a % 1000000007;
}

int mlp(long long a, int b) {
    a *= b;
    return a % 1000000007;
}

void check_large_b_invariant(int b) {
    // Check for large value of b triggering performance bottleneck
    if (b > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - large b value!" << endl;
        abort();
    }
}

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);

    // Insert check for large b
    check_large_b_invariant(b);

    int ans(0);
    for (int i(1), _l(b - 1); i <= _l; ++i) {
        int smth(mlp(add(mlp(b, i) + i, add(mlp(a, mlp(b, i)), i)), a));
        smth = mlp(smth, 500000004);
        ans = add(ans, smth);
    }
    printf("%d\n", ans);
}

int main() {
    clock_t tm = clock();
    solve();
    cerr << setprecision(3);
    cerr << (clock() - tm) / 1000000. << endl;
    return 0;
}