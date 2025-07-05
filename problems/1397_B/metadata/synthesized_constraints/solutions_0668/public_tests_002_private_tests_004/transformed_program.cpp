#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance invariants
void check_power_recursion_depth(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to high recursion depth in power calculation!" << endl;
        abort();
    }
}

void check_transformation_cost(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to large number of base trials for transformation cost!" << endl;
        abort();
    }
}

void check_large_values_few_elements(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to few elements with large values!" << endl;
        abort();
    }
}

void check_high_maximum_base(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered due to high maximum base!" << endl;
        abort();
    }
}

long long int powe(long long int n, long long int m) {
    if (m == 0) return 1;
    long long int t = powe(n, m / 2);
    // Check for recursion depth, assuming large m can indicate a deep recursion
    check_power_recursion_depth(m > 1000);  // Arbitrary threshold for deep recursion
    if (m % 2 == 0) return (t * t);
    return (((t * t)) * n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n, i, j, f = 0;
    cin >> n;
    
    long long int sum = 0, ans = 1e18, temp, x;
    double y;
    long long int a[n];
    for (long long int i = 0; i < n; i++) cin >> a[i];
    
    sort(a, a + n);
    
    // Checking for few elements with very large values
    check_large_values_few_elements(n < 10 && *max_element(a, a + n) > 1e8);  // Arbitrary threshold
    
    if (n >= 63)
        x = 1;
    else {
        y = 18.0000 / (n - 1);
        y = pow(10, y);
        x = (int)y;
        if (n == 3) x = 10000000;
    }
    
    // Check if maximum possible base is excessively high
    check_high_maximum_base(x > 1000000);  // Arbitrary threshold
    
    for (i = 1; i <= x; i++) {
        sum = 0;
        for (j = 0; j < n; j++) {
            sum += abs(a[j] - powe(i, j));
        }
        ans = min(ans, sum);
    }
    
    // Check if the transformation cost calculation has too many trials
    check_transformation_cost(x > 100000);  // Arbitrary threshold
    
    cout << ans;
    return 0;
}