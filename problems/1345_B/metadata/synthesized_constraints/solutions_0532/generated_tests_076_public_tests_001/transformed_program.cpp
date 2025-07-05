#include <bits/stdc++.h>
using namespace std;
const long long mxn = 100000;
long long c[mxn];

// Function to check for unnecessary repeated initialization
void check_initialization_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - unnecessary repeated initialization!" << endl;
        abort();
    }
}

// Function to check for excessive iterations in the pyramid calculation loop
void check_pyramid_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations in pyramid calculation loop!" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;

    // Initialize c array only once
    c[1] = 2;
    for (int i = 2; i < mxn; i++) {
        c[i] = ((i - 1) * 3) + 2 + c[i - 1];
    }
    
    // Check initialization invariant only once
    check_initialization_invariant(false); // Initialization is done only once, so condition is false.

    while (t--) {
        long long n, ans = 0;
        cin >> n;

        // Check the pyramid loop invariant before entering the loop
        check_pyramid_loop_invariant(n < 10); // Arbitrarily checking if n is very small for demonstration

        for (int i = mxn - 1; i >= 1; i--) {
            if (n >= c[i]) {
                ans += n / c[i];
                n = n % c[i];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}