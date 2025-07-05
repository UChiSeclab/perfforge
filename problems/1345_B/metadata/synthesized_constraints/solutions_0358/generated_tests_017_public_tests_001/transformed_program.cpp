#include <bits/stdc++.h>
using namespace std;

int tests;
long long high(long long n) { return (n * (3 * n + 1)) / 2; }

// Checker functions
void check_high_iteration_invariant(long long n, int i) {
    if (n > 0 && i == 1) {
        cerr << "Warning: Performance bottleneck condition triggered - high iteration counts in loop!" << endl;
        abort();
    }
}

void check_small_reductions_invariant(long long n, long long x) {
    if (n < 2 * x && n > 0) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated small reductions of n!" << endl;
        abort();
    }
}

void check_pyramid_height_threshold(int i, long long x, long long n) {
    if (i < 10 && n > 0 && x > n) {
        cerr << "Warning: Performance bottleneck condition triggered - pyramid height threshold!" << endl;
        abort();
    }
}

void check_excessive_function_calls(int highCalls) {
    if (highCalls > 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive function calls to 'high'!" << endl;
        abort();
    }
}

int main() {
    tests = 1;
    cin >> tests;
    while (tests--) {
        long long n;
        cin >> n;
        long long ans = 0;
        int highCalls = 0; // To track the number of calls to the high() function.
        
        for (int i = 100000; i > 0; i--) {
            long long x = high(i);
            highCalls++;
            
            check_excessive_function_calls(highCalls); // Check excessive high calls
            
            while (x <= n) {
                ans++;
                n = n - x;
                check_small_reductions_invariant(n, x); // Check small reductions 
            }
            
            check_high_iteration_invariant(n, i); // Check high iterations
            check_pyramid_height_threshold(i, x, n); // Check pyramid height threshold
        }
        cout << ans << '\n';
    }
    return 0;
}