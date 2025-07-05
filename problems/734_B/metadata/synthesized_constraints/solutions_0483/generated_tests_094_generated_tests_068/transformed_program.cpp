#include <bits/stdc++.h>
using namespace std;

// Check for useless iterations and early termination
void check_useless_iterations(int k2, int k3, int k5, int k6) {
    if (k2 > 1000 && k5 == 0 && k6 == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - large k2 with insufficient k5 and k6" << endl;
        abort();
    }
    if (k2 > 1000 && k3 == 0) {
        cerr << "Warning: Performance bottleneck condition triggered - large k2 with insufficient k3" << endl;
        abort();
    }
}

int main() {
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    
    // Insert checks after reading inputs
    check_useless_iterations(k2, k3, k5, k6);

    int sum = 0;
    int j = k2;
    for (int i = 0; i < j; i++) {
        if (k2 > 0 && k5 > 0 && k6 > 0) {
            sum = sum + 256;
            k2 = k2 - 1;
            k5 = k5 - 1;
            k6 = k6 - 1;
        }
        if (k2 > 0 && k3 > 0 && (k5 <= 0 || k6 <= 0)) {
            sum = sum + 32;
            k2 = k2 - 1;
            k3 = k3 - 1;
        }
        if (k2 == 0) {
            break;
        }
    }
    cout << sum;
    return 0;
}