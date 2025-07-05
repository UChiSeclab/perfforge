#include <bits/stdc++.h>
using namespace std;

// Check for large imbalance in count of apples
void check_imbalance_invariant(int ca, int cb) {
    if (ca > 50 || cb > 50) {
        cerr << "Warning: Imbalance invariant triggered - large imbalance in apple counts" << endl;
        abort();
    }
}

// Check for nearing maximum input size with complex combinations
void check_complexity_invariant(int n, int ca, int cb) {
    if (n > 90 && abs(ca - cb) > 30) {
        cerr << "Warning: Complexity invariant triggered - nearing max input with complex combinations" << endl;
        abort();
    }
}

// Check for inefficient balance finding due to specific distribution
void check_distribution_invariant(int ca, int cb, int sum) {
    if ((sum % 200 == 0 && cb == 0) || (sum % 100 == 0 && ca == 0)) {
        cerr << "Warning: Distribution invariant triggered - inefficient balance due to specific distribution" << endl;
        abort();
    }
}

int main() {
    int n, sum = 0, ca = 0, cb = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 100)
            ++ca;
        else
            ++cb;
        sum += x;
    }
    
    // Place checks after collecting input data
    check_imbalance_invariant(ca, cb);
    check_complexity_invariant(n, ca, cb);
    check_distribution_invariant(ca, cb, sum);

    if (sum % 2 == 1)
        cout << "NO\n";
    else {
        bool ok = 0;
        for (int i = 0; i <= ca; ++i)
            for (int j = 0; j <= cb; ++j)
                if (i * 100 + j * 200 == sum / 2) ok = 1;
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}