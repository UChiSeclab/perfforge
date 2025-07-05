#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_sorting_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive re-sorting due to x <= y and low initial durabilities!" << endl;
        abort();
    }
}

void check_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - inefficient loop execution due to x <= y and low initial durabilities!" << endl;
        abort();
    }
}

int main() {
    long long n, temp = 0;
    long long x, y;
    cin >> n >> x >> y;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Insert checks after reading inputs
    bool isAllDurabilityLow = true;
    for (int j = 0; j < n; j++) {
        if (a[j] > x) {
            isAllDurabilityLow = false;
            break;
        }
    }
    check_sorting_invariant((x <= y) && isAllDurabilityLow);

    int lowDurabilityCount = 0;
    for (int j = 0; j < n; j++) {
        if (a[j] <= x) {
            lowDurabilityCount++;
        }
    }
    check_loop_invariant((x <= y) && (lowDurabilityCount > n / 2));

    long long i = 0, z = 0;
    if (x > y) {
        cout << n;
        return 0;
    } else {
        sort(a, a + n);
        bool isthere = true;
        int t = 0;
        while (isthere) {
            sort(a, a + n);
            isthere = false;
            for (int j = i; j < n; j++) {
                if (x >= a[j]) {
                    isthere = true;
                    t = i;
                }
            }
            a[t] = max(temp, a[t] - x);
            if (a[i] != 0) {
                a[i] = a[i] + y;
            } else {
                z++;
                a[i + 1] = a[i + 1] + y;
            }
            i++;
        }
    }
    cout << z;
    return 0;
}