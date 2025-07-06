#include <bits/stdc++.h>
using namespace std;

// Checker function for the first performance invariant
void check_bottleneck_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered!" << endl;
        abort();
    }
}

// Checker function for the second performance invariant
void check_large_difference_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Large difference invariant triggered - potential for many loop iterations!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long a, b, c = 10000000;
    bool found = false;
    cin >> a >> b;
    
    // Check the first invariant before entering the loop
    check_bottleneck_invariant(a < b && a % b != 0);
    
    // Check the second invariant also before entering the loop
    check_large_difference_invariant(abs(a - b) > (b / 2) && a % b != 0);
    
    while (c--) {
        if (a % b == 0) {
            found = true;
            break;
        }
        a += (a % b);
    }
    
    if (found)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}