#include <bits/stdc++.h>
using namespace std;

long long n, a[1000005], m, sum, ans;

void check_high_stack_values(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high stack values causing frequent updates!" << endl;
        abort();
    }
}

void check_large_variations(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large variations in stack heights!" << endl;
        abort();
    }
}

void check_many_stacks(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - many stacks with diverse heights!" << endl;
        abort();
    }
}

signed main() {
    cin >> n >> m;
    
    // Check for many stacks and diverse heights
    check_many_stacks(n > 50000);

    // Read the stack heights and calculate sum
    for (long long i = 1; i <= n; i++) {
        scanf("%I64d", &a[i]);
        sum += a[i];
    }
    
    // Sort the array
    sort(a + 1, a + 1 + n);

    // Check for large variations in stack heights
    long long max_height = a[n];
    long long min_height = a[1];
    check_large_variations(max_height - min_height > (m / 2));

    long long now = 0;
    for (long long i = 1; i <= n; i++) {
        now++;
        if (now > a[i]) now = a[i];
        ans++;
    }
    
    // Check for high stack values after loop
    check_high_stack_values(a[n] > (m / 2));

    ans += max(0ll, a[n] - now);
    cout << sum - ans << endl;
    return 0;
}