#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int M = 1e6 + 7;

int y, k, n, t;

// Checker functions
void check_large_y_small_k(int y, int k) {
    if (y / k > 1000000) { // Arbitrary large threshold for demonstration
        cerr << "Warning: Performance bottleneck condition triggered - large y relative to small k!" << endl;
        abort();
    }
}

void check_high_iterations(int y, int k) {
    if (y / k > 1000000) { // Similar threshold to detect potential excessive iterations
        cerr << "Warning: Performance bottleneck condition triggered - high iteration count possible in loop!" << endl;
        abort();
    }
}

int main() {
    cin >> y >> k >> n;
    
    // Check for potential performance bottlenecks based on input values
    check_large_y_small_k(y, k);
    check_high_iterations(y, k);

    int c = 1;
    for (int i = 1;; ++i) {
        if (k * i > y) {
            c = k * i - y;
            break;
        }
    }
    for (int i = c;; i += k) {
        if (i + y > n) {
            break;
        }
        if ((i + y) % k == 0) {
            cout << i << ' ';
            t = 1;
        }
    }
    if (!t) {
        cout << -1;
    }
}