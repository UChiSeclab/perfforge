#include <bits/stdc++.h>
using namespace std;

// Checker function for high iteration impact
void check_high_iteration_impact(long long n, long long m) {
    if (m > n * 1000) {  // Arbitrary threshold for disparity leading to high iterations
        cerr << "Warning: Performance bottleneck condition triggered due to high iteration impact!" << endl;
        abort();
    }
}

// Checker function for block type ratio disparity
void check_block_type_ratio(long long n, long long m) {
    if (m > n * 1000) {  // Similar condition for large disparity
        cerr << "Warning: Performance bottleneck condition triggered due to block type ratio disparity!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, m;
    cin >> n >> m;

    // Inserted checker for detecting potential performance bottleneck
    check_high_iteration_impact(n, m);
    check_block_type_ratio(n, m);

    long long i = 1;
    while (true) {
        long long num1 = i / 2;
        long long num2 = i / 3;
        long long num3 = i / 6;
        num1 -= i / 6;
        num2 -= i / 6;
        if (max(n - num1, (long long)0) + max(m - num2, (long long)0) <= num3) {
            cout << i;
            return 0;
        }
        i++;
    }
    
    return 0;
}