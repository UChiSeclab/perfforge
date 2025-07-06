#include <bits/stdc++.h>
using namespace std;

void check_high_limiting_factor(long long p, long long y) {
    if (p > 100000000 && y > 100000000) {
        cerr << "Warning: High limiting factor triggered - large divisor checks expected!" << endl;
        abort();
    }
}

void check_divisibility_testing(long long y, long long i, long long p) {
    if (y - i <= p + 100) { // Allow a small buffer beyond p to trigger the invariant
        cerr << "Warning: Extensive divisibility testing triggered!" << endl;
        abort();
    }
}

void check_large_loop_boundary(long long y) {
    if (y > 100000000) {
        cerr << "Warning: Large loop boundary triggered - excessive iterations expected!" << endl;
        abort();
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long p, y;
    cin >> p >> y;

    // Check for high limiting factor
    check_high_limiting_factor(p, y);

    long long lim = min(p, (long long)sqrt(y));
    long long limi = min(1000LL, y - 1);

    // Check for large loop boundary before loop starts
    check_large_loop_boundary(y);

    for (long long i = 0; i < limi; i++) {
        bool ok = 1;
        
        // Check for extensive divisibility testing
        check_divisibility_testing(y, i, p);

        if (y - i <= p) ok = 0;
        for (long long j = 2; j <= lim; j++) {
            if ((y - i) % j == 0) ok = 0;
        }
        if (ok) {
            cout << y - i;
            return 0;
        }
    }
    cout << -1 << endl;
}