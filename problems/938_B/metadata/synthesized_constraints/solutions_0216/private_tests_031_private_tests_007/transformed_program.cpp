#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
int a[M];

// Checkers for performance invariants
void check_long_distance_invariant(int firstPrize, int lastPrize) {
    if (firstPrize > 100 && lastPrize < 1e6 - 100) {
        cerr << "Warning: Performance bottleneck condition triggered - long distance between starting positions and prizes!" << endl;
        abort();
    }
}

void check_centralized_distribution_invariant(int firstPrize, int lastPrize) {
    if (lastPrize - firstPrize < 50000) {
        cerr << "Warning: Performance bottleneck condition triggered - centralized prize distribution!" << endl;
        abort();
    }
}

void check_equal_division_invariant(int n, int my, int fr) {
    if (fr - my > 500000) {
        cerr << "Warning: Performance bottleneck condition triggered - equal division of prize collection!" << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n;
    int firstPrize, lastPrize;
    
    for (int i = 0; i < n; i++) {
        cin >> m;
        a[m] = 1;
        if (i == 0) {
            firstPrize = m;
        }
        if (i == n - 1) {
            lastPrize = m;
        }
    }
    
    // Insert checks for performance bottlenecks
    check_long_distance_invariant(firstPrize, lastPrize);
    check_centralized_distribution_invariant(firstPrize, lastPrize);

    int my = 1, fr = 1e6, cnt = 0, time = 0;
    check_equal_division_invariant(n, my, fr);
    
    while (cnt != n) {
        my++;
        fr--;
        if (a[my]) {
            cnt++;
        }
        if (my != fr && a[fr]) {
            cnt++;
        }
        time++;
    }

    cout << time << endl;
    return 0;
}