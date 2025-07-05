#include <bits/stdc++.h>
using namespace std;

int i;

// Check for large n with small a, b, c
void check_large_n_small_abc(int n, int a, int b, int c) {
    if (n > 1000 && (a < 10 || b < 10 || c < 10)) {
        cerr << "Warning: Performance bottleneck condition triggered - large n and small a, b, c!" << endl;
        abort();
    }
}

// Check for potential combinatorial explosion
void check_combinatorial_explosion(int n, int a, int b, int c) {
    if (n > 1000 && (n % a == 0 || n % b == 0 || n % c == 0)) {
        cerr << "Warning: Performance bottleneck condition triggered - potential combinatorial explosion!" << endl;
        abort();
    }
}

int main() {
    int n, a, b, c, best = 0;
    cin >> n >> a >> b >> c;

    // Place checks after input to avoid overhead in loops
    check_large_n_small_abc(n, a, b, c);
    check_combinatorial_explosion(n, a, b, c);

    for (i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int x, y, z;
            x = a * i, y = j * b, z = n - x - y;
            if (z % c == 0 && z > 0) {
                best = max(best, i + j + (z / c));
            }
            if ((a * i + b * j) == n) best = max(best, i + j);
        }
    }
    cout << best;
}