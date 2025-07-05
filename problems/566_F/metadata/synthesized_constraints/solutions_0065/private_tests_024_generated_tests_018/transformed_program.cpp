#include <bits/stdc++.h>
using namespace std;

int a[2000000];
int dp[2000000];

// Function to check if the input has a small divisor that might cause performance issues
void check_small_divisor_invariant(int smallestElement) {
    if (smallestElement == 1) {
        cerr << "Warning: Performance bottleneck condition triggered due to small divisor (1)!" << endl;
        abort();
    }
}

// Function to check if the input has a small element causing many multiples to be processed
void check_divisor_multiples_invariant(int smallestElement) {
    if (smallestElement <= 10) {
        cerr << "Warning: Performance bottleneck condition triggered due to many multiples processing!" << endl;
        abort();
    }
}

int main() {
    int n, i, j, num, ans = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dp[a[i]] = 1;
    }

    // Place the checks after reading the input to catch potential performance bottlenecks early
    check_small_divisor_invariant(a[0]);
    check_divisor_multiples_invariant(a[0]);

    for (i = 0; i < n; i++) {
        num = a[i];
        for (j = 2 * num; j <= 1000000; j += num) {
            dp[j] = max(dp[j], 1 + dp[num]);
        }
        ans = max(ans, dp[num]);
    }
    
    printf("%d", ans);
    return 0;
}