#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_sort_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: sort_invariant triggered - repeatedly sorting large data" << endl;
        abort();
    }
}

void check_iteration_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: iteration_invariant triggered - high iteration count for calculations" << endl;
        abort();
    }
}

void check_conditional_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: conditional_invariant triggered - intensive conditional checks within loops" << endl;
        abort();
    }
}

long long n, a[400005], b[400005];

long long cnt(long long l, long long r) {
    return upper_bound(b, b + n, r) - lower_bound(b, b + n, l);
}

int main(int argc, char const *argv[]) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Check for potential performance issues based on input size and operations
    check_sort_invariant(n > 100000);  // Example threshold for large data
    check_iteration_invariant(n > 100000);  // Assume high iteration count could be problematic
    
    long long ans = 0;
    for (long long j = 0; j <= 30; ++j) {
        long long c = 0;
        for (int i = 0; i < n; ++i) {
            b[i] = a[i] % (1ll << (j + 1));
        }
        sort(b, b + n);
        
        // Check conditionals inside performance critical loops
        check_conditional_invariant(n > 100000);  // Example of intensive conditional checks
        
        for (int i = 0; i < n; ++i) {
            c += cnt((1ll << j) - b[i], (1ll << (j + 1)) - 1 - b[i]);
            c += cnt((1ll << (j + 1)) + (1ll << j) - b[i],
                     (1ll << (j + 2)) - 2 - b[i]);
            if (2 * b[i] >= (1ll << j) && 2 * b[i] < (1ll << (j + 1))) c--;
            if (2 * b[i] >= (1ll << (j + 1)) + (1ll << j) &&
                2 * b[i] <= (1ll << (j + 2)) - 2)
                c--;
        }
        c >>= 1;
        if (c & 1) ans |= (1ll << j);
    }
    cout << ans;
    return 0;
}