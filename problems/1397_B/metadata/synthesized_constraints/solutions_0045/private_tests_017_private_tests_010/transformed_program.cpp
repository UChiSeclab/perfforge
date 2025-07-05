#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_high_exponentiation(long long maxElement, int n) {
    if (n <= 32 && maxElement > 1e9 / 10) {  // Estimate threshold based on large input value
        cerr << "Warning: Performance bottleneck condition triggered - high exponentiation cost!" << endl;
        abort();
    }
}

void check_high_loop_iterations(int n, long long maxElement) {
    if (n <= 32 && maxElement > 1e9 / 10) {  // Same condition for detection
        cerr << "Warning: Performance bottleneck condition triggered - high loop iterations with small n!" << endl;
        abort();
    }
}

void check_inefficient_power_calculation(int n, long long maxElement) {
    if (n <= 32 && maxElement > 1e9 / 10) {  // Similar detection condition
        cerr << "Warning: Performance bottleneck condition triggered - inefficient power calculation!" << endl;
        abort();
    }
}

void solve() {
    long long n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());
    
    // Determine the maximum element to use in checkers
    long long maxElement = arr[n - 1];
    
    // Check conditions for performance bottlenecks
    check_high_exponentiation(maxElement, n);
    check_high_loop_iterations(n, maxElement);
    check_inefficient_power_calculation(n, maxElement);
    
    if (n > 32) {
        unsigned long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans + arr[i] - 1;
        }
        cout << ans << "\n";
    } else {
        unsigned long long ans = 1e16;
        unsigned long long a1 = 0;
        for (int i = 1; i <= sqrt(arr[n - 1]) + 1; i++) {
            a1 = 0;
            for (int j = 0; j < n; j++) {
                a1 = a1 + (long long)abs((long long)pow(i, j) - arr[j]);
                a1 = min((unsigned long long)1e16, a1);
            }
            ans = min(ans, a1);
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long t = 1;
    while (t--) solve();
}