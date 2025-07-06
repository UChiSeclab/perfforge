#include <bits/stdc++.h>
using namespace std;

int a[111111];
int b[111111];

// Checker functions
void check_large_range_invariant(int max_value, int min_value) {
    if ((max_value - min_value) > 111110) {
        cerr << "Warning: Performance bottleneck condition triggered due to large range of input values!" << endl;
        abort();
    }
}

void check_array_size_invariant(int n) {
    if (n < 111110) {
        cerr << "Warning: Unnecessary large array allocation detected!" << endl;
        abort();
    }
}

void check_redundant_iteration_invariant(int n, int non_zero_count) {
    if (n < 111110 && non_zero_count < n / 2) {
        cerr << "Warning: Performance bottleneck triggered due to redundant loop iteration over mostly zero entries!" << endl;
        abort();
    }
}

void check_conditional_complexity_invariant(int left, int n, int sum) {
    if (left < 0 || (left == 0 && sum < n)) {
        cerr << "Warning: Complex conditional logic leading to performance issues!" << endl;
        abort();
    }
}

int main() {
    int i, n;
    int themin = 1111111111;
    int themax = 0;
    int sum = 0;
    int left;
    int newleft;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        themin = min(a[i], themin);
        themax = max(a[i], themax);
    }
    
    // Check for large range in input values
    check_large_range_invariant(themax, themin);

    if (n % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    
    for (i = 0; i < 111110; i++) b[i] = 0;
    
    for (i = 0; i < n; i++) {
        a[i] -= themin;
        if (a[i] >= 111110) {
            cout << "NO" << endl;
            return 0;
        }
        b[a[i]]++;
    }
    
    sum = b[0];
    left = b[0] * 2;
    
    // Check for unnecessary large allocations
    check_array_size_invariant(n);
    
    int non_zero_count = 0;
    for (i = 0; i < 111110; i++) {
        if (b[i] > 0) {
            non_zero_count++;
        }
    }
    
    // Check for redundant iteration
    check_redundant_iteration_invariant(n, non_zero_count);
    
    for (i = 1; i < 111110; i++) {
        sum += b[i];
        newleft = b[i] * 2 - left;
        left = newleft;

        // Check for complex conditional logic
        check_conditional_complexity_invariant(left, n, sum);
        
        if (sum == n && left == 0) {
            cout << "YES" << endl;
            break;
        } else if (left < 0) {
            cout << "NO" << endl;
            break;
        } else if (left == 0 && sum < n) {
            cout << "NO" << endl;
            break;
        }
    }
    return 0;
}