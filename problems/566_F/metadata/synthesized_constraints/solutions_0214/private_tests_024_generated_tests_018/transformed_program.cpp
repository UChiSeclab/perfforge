#include <bits/stdc++.h>
using namespace std;

int a[1111111];
int dp[1111111], ans = 0;

// Checker function for the first invariant
void check_smallest_value_invariant(int smallestValue) {
    if (smallestValue == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - smallest value is 1!" << endl;
        abort();
    }
}

// Checker function for the second invariant
void check_excessive_iterations_invariant(int smallestValue) {
    if (smallestValue <= 10) {  // using 10 as a broad threshold for small numbers
        cerr << "Warning: Performance bottleneck condition triggered - small number causing excessive iterations!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[a[i]] = 1;
    }
    
    // Add check after reading inputs to prevent excessive iterations
    int smallestValue = a[0];
    check_smallest_value_invariant(smallestValue);
    check_excessive_iterations_invariant(smallestValue);

    for (int i = 0; i < n; i++) {
        for (int k = a[i] * 2; k <= 1000000; k += a[i]) {
            dp[k] = max(dp[k], dp[a[i]] + 1);
        }
        ans = max(ans, dp[a[i]]);
    }
    cout << ans;
    return 0;
}