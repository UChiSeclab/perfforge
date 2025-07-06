#include <bits/stdc++.h>
using namespace std;

// Checker functions to detect performance bottlenecks
void check_non_combinable_invariant(int n) {
    if (n % 3 == 1 || n % 3 == 2) {
        cerr << "Warning: Non-combinable number invariant triggered!" << endl;
        abort();
    }
}

void check_repeated_non_combinable_invariant(int count) {
    if (count > 5) {
        cerr << "Warning: Repeated non-combinable number invariant triggered!" << endl;
        abort();
    }
}

int main() {
    iostream::sync_with_stdio(0);
    
    int x;
    cin >> x;
    int non_combinable_count = 0; // Track non-combinable numbers
    
    for (int i = 0; i < x; i++) {
        int n;
        cin >> n;
        
        // Check for non-combinable number invariant
        check_non_combinable_invariant(n);
        
        bool r = true;
        for (int a = 0; a <= 100; a++) {
            for (int b = 0; b <= 100; b++) {
                if (a * 3 + b * 7 == n && r) {
                    cout << "YES" << endl;
                    r = false;
                    break;
                }
            }
        }
        if (r) {
            cout << "NO" << endl;
            non_combinable_count++;
        }
    }
    
    // Check for repeated non-combinable numbers invariant
    check_repeated_non_combinable_invariant(non_combinable_count);
    
    return 0;
}