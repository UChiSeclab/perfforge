#include <bits/stdc++.h>
using namespace std;

void check_large_b_invariant(long long b) {
    if (b > 9000) { // arbitrary threshold close to upper limit of b
        cerr << "Warning: Performance bottleneck condition triggered - large b causing high iteration counts!" << endl;
        abort();
    }
}

void check_nested_loop_invariant(long long i, long long b) {
    if (i > 9000 && b > 9000) { // condition reflecting high iterations in nested loops
        cerr << "Warning: Performance bottleneck condition triggered - excessive nested loop iterations!" << endl;
        abort();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int m, b, i, x, curr, ma = 0, tot, j;
    cin >> m >> b;

    // Check for large `b` to preemptively catch potential performance issues
    check_large_b_invariant(b);

    for (i = 0; i <= b; i++) {
        // Check for excessive iterations in nested loops
        check_nested_loop_invariant(i, b);

        x = m * (b - i);
        tot = 0;
        for (j = i; j >= 0; j--) {
            curr = x * (x + 1);
            curr /= 2;
            curr += (x + 1) * j;
            tot += curr;
        }
        ma = max(tot, ma);
    }
    cout << ma;
    return 0;
}