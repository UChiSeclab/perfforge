#include <bits/stdc++.h>
using namespace std;

// Checker for balanced high counts of 2, 5, and 6
void check_balance_invariant(int k2, int k5, int k6) {
    if (k2 > 100000 && k5 > 100000 && k6 > 100000 && abs(k2 - k5) < 50000 && abs(k5 - k6) < 50000 && abs(k2 - k6) < 50000) {
        cerr << "Warning: Performance bottleneck condition triggered due to balanced high counts of 2, 5, and 6!" << endl;
        abort();
    }
}

// Checker for excess of digit 3
void check_excess_three_invariant(int k3, int k5, int k6) {
    if (k3 > 100000 && k3 > k5 * 2 && k3 > k6 * 2) {
        cerr << "Warning: Performance condition triggered due to excess of digit 3!" << endl;
        abort();
    }
}

int main() {
    int freq[4], n, sum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> n;
        freq[i] = n;
    }
    
    // Check for potential performance bottlenecks
    check_balance_invariant(freq[0], freq[2], freq[3]);
    check_excess_three_invariant(freq[1], freq[2], freq[3]);
    
    while (freq[0] > 0 && freq[2] > 0 && freq[3] > 0) {
        sum += 256;
        freq[0]--;
        freq[2]--;
        freq[3]--;
    }
    while (freq[0] > 0 && freq[1] > 0) {
        sum += 32;
        freq[0]--;
        freq[1]--;
    }
    cout << sum;
    return 0;
}