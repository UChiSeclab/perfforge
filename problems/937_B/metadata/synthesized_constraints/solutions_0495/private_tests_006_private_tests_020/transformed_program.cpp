#include <bits/stdc++.h>
using namespace std;

// Checker functions to detect potential performance bottlenecks
void check_large_upper_limits(int p, int y) {
    if (y > 1e8 && y > 10 * p) {
        cerr << "Warning: Performance bottleneck condition triggered due to large upper limits!" << endl;
        abort();
    }
}

void check_divisor_check_complexity(int y) {
    int max_divisor_checks = static_cast<int>(sqrt(y));
    if (max_divisor_checks > 1e4) {
        cerr << "Warning: Performance bottleneck due to excessive divisor checks!" << endl;
        abort();
    }
}

void check_inefficient_loops(int p, int y) {
    if (y > 1e8) {
        cerr << "Warning: Performance bottleneck due to inefficient loop range!" << endl;
        abort();
    }
}

int main() {
    int p, y, ans;
    cin >> p >> y;
    
    // Insert checks after reading input, before entering the main heavy loops
    check_large_upper_limits(p, y);
    check_divisor_check_complexity(y);
    check_inefficient_loops(p, y);

    for (int i = y; i >= 2; i--) {
        bool ok = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) ok &= (j > p) && (i / j > p);
        }
        if (ok) {
            ans = i;
            break;
        }
    }
    if (ans <= p) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}