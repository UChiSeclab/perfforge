#include <bits/stdc++.h>
using namespace std;

#include <cstdlib> // for abort
#include <numeric> // for gcd

void check_gcd_invariant(int a, int b, int c) {
    int gcd_ab = std::gcd(a, b);
    if (gcd_ab > 1 && c % gcd_ab != 0) {
        cerr << "Warning: GCD invariant triggered - solution impossible without unnecessary iterations" << endl;
        abort();
    }
}

void check_multiplier_invariant(int a, int b, int c) {
    if (c % a == 0 || c % b == 0) {
        cerr << "Warning: Multiplier invariant triggered - direct solution available" << endl;
        abort();
    }
}

int main() {
    int a, b, c, i, j;
    cin >> a >> b >> c;

    // Checker for potential performance bottlenecks
    check_gcd_invariant(a, b, c);
    check_multiplier_invariant(a, b, c);

    bool flag = true;
    for (i = 0; i <= 10000 && flag == true; i++) {
        for (j = 0; j <= 10000 && flag == true; j++) {
            if ((i * a + j * b) == c) {
                cout << "Yes" << endl;
                flag = false;
            }
        }
    }
    if (flag == true) cout << "No" << endl;
    return 0;
}