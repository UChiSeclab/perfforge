#include <bits/stdc++.h>
using namespace std;

// Check for excessive digit 2 compared to 5 and 6
void check_loop_invariant(long int k2, long int k5, long int k6) {
    if (k2 > 2 * std::min(k5, k6)) {
        cerr << "Warning: Performance bottleneck due to excess of digit 2 compared to 5 and 6!" << endl;
        abort();
    }
}

// Check for imbalance in the counts of digits
void check_imbalance_invariant(long int k2, long int k5, long int k6) {
    if (std::min(k5, k6) < k2 / 2) {
        cerr << "Warning: Imbalance in digits causing performance bottleneck!" << endl;
        abort();
    }
}

int main() {
    long int a2, a3, a5, a6, s = 0;
    cin >> a2 >> a3 >> a5 >> a6;
    
    // Insert checks after reading inputs
    check_loop_invariant(a2, a5, a6);
    check_imbalance_invariant(a2, a5, a6);

    while (1) {
        if (a2 > 0 and a5 > 0 and a6 > 0) {
            a2--;
            a5--;
            a6--;
            s += 256;
        } else
            break;
    }
    
    int mi1 = min(a2, a3);
    s += 32 * mi1;
    cout << s << endl;
    return 0;
}