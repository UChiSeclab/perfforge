#include <bits/stdc++.h>
using namespace std;

// Function to check high iteration invariant
void check_high_iteration_invariant(int n, int m) {
    if (n > 900 && m < 5) {  // Example thresholds based on problem constraints
        cerr << "Warning: High iteration count due to large n and small m!" << endl;
        abort();
    }
}

// Function to check frequent modular inversion invariant
void check_frequent_modular_inversion_invariant(int n, int m) {
    if (n > 900 && m < 3) {  // Example thresholds for excessive modular inversion calls
        cerr << "Warning: Frequent modular inversions due to high combinatorial activity!" << endl;
        abort();
    }
}

long long minv(long long a) {
    long long tmp = 1000000007 - 2, sol = 1, pw = a;
    while (tmp) {
        if (tmp % 2) sol = (sol * pw) % 1000000007;
        pw = (pw * pw) % 1000000007;
        tmp /= 2;
    }
    return sol;
}

long long comb(long long a, long long b) {
    if (a < b) return 1;
    long long sol = 1;
    for (long long i = 1; i <= b; i++, a--) {
        sol = (((sol * a) % 1000000007) * minv(i)) % 1000000007;
    }
    return sol;
}

int main() {
    int t = 1;
    while (t--) {
        long long n, m, sol = 0;
        cin >> n >> m;
        
        // Check performance-characterizing invariants after reading input
        check_high_iteration_invariant(n, m);
        check_frequent_modular_inversion_invariant(n, m);

        for (int i = n; i >= 1; i--) {
            long long ar = i, br = n - i + 1;
            sol = (sol + (comb(m + ar - 2, ar - 1) * comb(br + m - 1, br - 1)) %
                           1000000007) %
                  1000000007;
        }
        cout << sol << endl;
    }
    return 0;
}