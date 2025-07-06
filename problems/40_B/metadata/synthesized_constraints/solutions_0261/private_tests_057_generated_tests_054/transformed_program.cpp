#include <bits/stdc++.h>
using namespace std;

// Function to check for large effective dimensions
void check_large_dimensions(int stx, int sty) {
    if (stx > 5000 || sty > 5000) { // Assume a threshold based on problem constraints
        cerr << "Warning: Performance bottleneck due to large effective dimensions!" << endl;
        abort();
    }
}

// Function to check input parameter thresholds
void check_input_thresholds(int m, int x) {
    if (m > 2 * x + 1000) { // Arbitrarily chosen threshold
        cerr << "Warning: m is significantly larger than 2 * x, causing performance issues!" << endl;
        abort();
    }
}

// Function to check for excessive iterations in nested loops
void check_excessive_iterations(int stx, int sty) {
    if ((stx * sty) > 10000000) { // Threshold based on empirical findings
        cerr << "Warning: Excessive iterations in nested loops detected!" << endl;
        abort();
    }
}

int n, m, x;
int ans(int x) {
    int summ = 0;
    int stx = n;
    int sty = m;
    stx -= 2 * x;
    sty -= 2 * x;
    
    // Check for large effective dimensions
    check_large_dimensions(stx, sty);
    
    // Check for excessive iterations
    check_excessive_iterations(stx, sty);

    for (int i = 0; i < stx; i++)
        for (int j = 0; j < sty; j++)
            if ((i + j) % 2 == 0) summ++;
    return summ;
}

int main() {
    cin >> n >> m >> x;
    
    // Check input parameter thresholds
    check_input_thresholds(m, x);

    x--;
    cout << ans(x) - ans(x + 1);
    return 0;
}