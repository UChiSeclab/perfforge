#include <bits/stdc++.h>
using namespace std;

// Invariant check functions
void check_loop_iteration_invariant(int n) {
    if (n > 90) { // Arbitrary threshold close to the maximum allowed value of 100
        cerr << "Warning: Performance bottleneck condition triggered - high loop iterations!" << endl;
        abort();
    }
}

void check_accumulation_invariant(int n, int max_x) {
    if (n > 90 && max_x > 900) { // Thresholds indicating a likely expensive accumulation process
        cerr << "Warning: Performance bottleneck condition triggered - costly accumulation!" << endl;
        abort();
    }
}

int x = 1, n;
int main() {
    cin >> n;
    
    // Check loop iteration invariant after reading n
    check_loop_iteration_invariant(n);

    long ans = 0;
    int max_x = 0; // Track the maximum value of x for the accumulation invariant

    for (int i = 1; i <= n; i++) {
        cin >> x;
        max_x = max(max_x, x); // Update max_x with the current input value
        ans += x * i;
    }
    
    // Check accumulation invariant after processing inputs
    check_accumulation_invariant(n, max_x);

    cout << ans;
}