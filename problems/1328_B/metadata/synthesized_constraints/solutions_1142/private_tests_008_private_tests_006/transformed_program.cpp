#include <bits/stdc++.h>
using namespace std;

void check_loop_invariant(long long k, long long n) {
    // Check if k is large relative to n, potentially causing a slow loop
    if (k > n * (n - 1) / 4) { // Example threshold to trigger the invariant
        cerr << "Warning: Performance bottleneck condition triggered in loop - k is large relative to n!" << endl;
        abort();
    }
}

void check_output_invariant(long long n, long long i) {
    // Check for extensive output operations due to large n and calculated i values
    if (i > n / 2) { // Example threshold to consider excessive output
        cerr << "Warning: Performance bottleneck condition triggered in output operations - extensive string construction!" << endl;
        abort();
    }
}

void solve() {
    long long n, k, i = 1;
    cin >> n >> k;
    
    // Check for potential loop bottleneck
    check_loop_invariant(k, n);

    string s(n - 2, 'a');
    s = s + "bb";
    if (k == 1) {
        cout << s << endl;
        return;
    }
    while (k >= 0) {
        k = k - i;
        i++;
        if (k - i <= 0) break;
    }
    
    // Check for potential output bottleneck
    check_output_invariant(n, i);

    long long y = n - i - 1, a = y;
    while (y--) cout << "a";
    cout << "b";
    long long x = i - k, b = x;
    while (x--) cout << "a";
    cout << "b";
    long long c = n - a - b - 2;
    while (c--) cout << "a";
    cout << "\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}