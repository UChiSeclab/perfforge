#include <bits/stdc++.h>
using namespace std;

// Check for large inputs that might cause many iterations.
void check_large_input_invariant(int n, int a, int b, int c) {
    if (n > 8000 && a > 4000 && b > 4000 && c > 4000) {
        cerr << "Warning: Performance bottleneck condition triggered (large inputs)!" << endl;
        abort();
    }
}

// Check for cases where n is not easily divisible causing inefficient searches.
void check_divisibility_invariant(int n, int b, int c) {
    if (b > 4000 && c > 4000 && (n % 2 != 0 || n % 1 != 0.5)) {
        cerr << "Warning: Performance bottleneck condition triggered (non-divisible n)!" << endl;
        abort();
    }
}

// Check for cases with even n and large a that lead to slow convergence.
void check_even_n_large_a_invariant(int n, int a) {
    if (a > 4000 && n % 2 == 0) {
        cerr << "Warning: Performance bottleneck condition triggered (even n with large a)!" << endl;
        abort();
    }
}

void solve() {
    int n, a, b, c, cnt = 0;
    scanf("%d %d %d %d", &n, &a, &b, &c);

    // Invariant checks placed after input reading
    check_large_input_invariant(n, a, b, c);
    check_divisibility_invariant(n, b, c);
    check_even_n_large_a_invariant(n, a);

    for (int i = 0; i <= a; i += 2) {
        int vol = 0;
        vol += i / 2;
        if (vol == n) {
            cnt++;
            break;
        }
        for (int j = 0; j <= b; j++) {
            int vol1 = vol;
            vol1 += j;
            if (vol1 == n) {
                cnt++;
                break;
            }
            if (vol1 % 2 == n % 2) {
                if (vol1 + 2 * c >= n) {
                    cnt++;
                }
            }
        }
    }
    printf("%d", cnt);
    return;
}

int main() {
    solve();
    return 0;
}