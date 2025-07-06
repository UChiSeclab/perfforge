#include <bits/stdc++.h>
using namespace std;

void check_outer_loop_invariant(long long m, int i) {
    if (i > m) {
        cerr << "Warning: Performance bottleneck condition in outer loop - excessive iterations!" << endl;
        abort();
    }
}

void check_inner_loop_bit_invariant(long long m) {
    int bitCount = 0;
    for (int j = 0; j < 40; ++j) {
        if ((m >> j) & 1) bitCount++;
    }
    if (bitCount > 20) {
        cerr << "Warning: Performance bottleneck condition in inner loop - high bit count in m!" << endl;
        abort();
    }
}

void check_m_value_invariant(long long m, long long n, long long p, int i) {
    if (m < 0 || m > n) {
        cerr << "Warning: Performance bottleneck due to unfavorable m value!" << endl;
        abort();
    }
}

const int max_iterations = 2000000;

void solve() {
    long long n, p;
    cin >> n >> p;
    for (int i = 1; i <= max_iterations; i++) {
        long long m = n - p * i;
        
        // Insert checks before entering the inner loop
        check_outer_loop_invariant(m, i);
        check_m_value_invariant(m, n, p, i);

        long long value = 0;
        for (int j = 0; j < 40; j++) {
            if ((m >> j) & 1) value += 1;
        }

        // Insert check after calculating the bit value
        check_inner_loop_bit_invariant(m);

        if (value <= i && i <= m) {
            cout << i;
            return;
        }
    }
    cout << -1;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
}