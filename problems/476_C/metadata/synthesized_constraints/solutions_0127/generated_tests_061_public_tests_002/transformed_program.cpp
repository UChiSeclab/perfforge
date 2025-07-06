#include <bits/stdc++.h>
using namespace std;
long long fst, lst, val, ans, a, b;
long long mag;

// Function for modular exponentiation
long long pw(long long a, long long b) {
    if (b == 0) return 1;
    if (b % 2) return a * pw(a, b - 1) % 1000000007;
    return pw(a * a % 1000000007, b / 2);
}

// Function to compute modular inverse
long long inv(long long x) {
    return pw(x, 1000000007 - 2);
}

// Function to check invariant for large b triggering excessive loop iterations
void check_large_b_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Large 'b' value triggering excessive loop iterations!" << endl;
        abort();
    }
}

// Function to check invariant for arithmetic overhead
void check_arithmetic_overhead_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Arithmetic overhead triggered by large 'b'!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> a >> b;

    // Check for large b value
    check_large_b_invariant(b > 1000000);

    // Check for potential arithmetic overhead
    check_arithmetic_overhead_invariant(b > 1000000);

    mag = inv(2);
    for (int rem = 1; rem < b; rem++) {
        fst = rem * b + rem;
        fst %= 1000000007;
        lst = ((rem * a) % 1000000007 * b) % 1000000007 + rem;
        lst %= 1000000007;
        val = fst + lst;
        val *= a;
        val %= 1000000007;
        val *= mag;
        val %= 1000000007;
        ans += val;
        ans %= 1000000007;
    }
    cout << ans << endl;
    cin.get();
    cin.get();
    return 0;
}