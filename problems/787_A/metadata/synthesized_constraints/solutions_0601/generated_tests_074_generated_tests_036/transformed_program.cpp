#include <bits/stdc++.h>
using namespace std;

// Checker function for common factor in intervals
void check_common_factor_invariant(int a, int c) {
    if (std::__gcd(a, c) > 1) {
        cerr << "Warning: Performance bottleneck due to common factor in intervals!" << endl;
        abort();
    }
}

// Checker function for high LCM of intervals
void check_lcm_invariant(int a, int c) {
    if (std::lcm(a, c) > 10000) {  // Arbitrary threshold to detect high LCM
        cerr << "Warning: Performance bottleneck due to high LCM of intervals!" << endl;
        abort();
    }
}

// Checker function for equal increments with non-converging start
void check_equal_increments_invariant(int a, int b, int c, int d) {
    if (a == c && b != d) {
        cerr << "Warning: Performance bottleneck due to equal increments but different starts!" << endl;
        abort();
    }
}

int main() {
    long long int a, b, c, d, i, j;
    cin >> a >> b >> c >> d;

    // Integrate checkers after reading input
    check_common_factor_invariant(a, c);
    check_lcm_invariant(a, c);
    check_equal_increments_invariant(a, b, c, d);

    map<long long int, long long int> mp;
    for (i = 0; i <= 1000000; i++) { // Main iteration loop
        long long int ret = b + i * a;
        if (mp[ret] != 0) {
            cout << ret << endl;
            return 0;
        }
        mp[ret]++;
        ret = d + i * c;
        if (mp[ret] != 0) {
            cout << ret << endl;
            return 0;
        }
        mp[ret]++;
    }
    cout << -1 << endl;
    return 0;
}