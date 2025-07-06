#include <bits/stdc++.h>
using namespace std;

// Checker for loop invariant
void check_loop_invariant(int n) {
    if (n > 90) {  // Given the constraint n <= 100, 90 is a reasonable threshold for a warning.
        cerr << "Warning: Performance bottleneck condition triggered due to large number of iterations!" << endl;
        abort();
    }
}

// Checker for accumulation invariant
void check_accumulation_invariant(int i) {
    if (i > 90) {  // Checking if the loop index `i` is high, leading to expensive operations.
        cerr << "Warning: Accumulation operations may be costly due to high index values!" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    
    // Check loop invariant before potentially large operations
    check_loop_invariant(n);
    
    long long ans = 0;
    int s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        ans += s * i;
        
        // Check accumulation invariant within the loop
        check_accumulation_invariant(i);
    }
    
    cout << ans;
}