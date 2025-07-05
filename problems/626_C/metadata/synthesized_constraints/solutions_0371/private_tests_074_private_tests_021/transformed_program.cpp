#include <bits/stdc++.h>
using namespace std;

bool vis[10000000];
int MX = 10000000;

// Checker functions for performance bottleneck conditions
void check_large_sum_invariant(int n, int m) {
    if (n + m > 1000000 - 10) { // close to maximum range
        cerr << "Warning: Performance bottleneck condition triggered - large sum of n and m!" << endl;
        abort();
    }
}

void check_arithmetic_invariant(int n, int m, int n2, int n3) {
    if ((n > n2 || m > n3) && (n2 + n3 < 1000000)) {
        cerr << "Warning: Performance bottleneck condition triggered - extensive arithmetic checks!" << endl;
        abort();
    }
}

void check_large_values_invariant(int n, int m) {
    if (n >= 1000000 || m >= 1000000) {
        cerr << "Warning: Performance bottleneck condition triggered - n or m is too large!" << endl;
        abort();
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Check for large sum invariant
    check_large_sum_invariant(n, m);

    int n2 = 0, n3 = 0, b = 0;
    
    if (n + m == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 2; i <= MX; i++) {
        if (i % 2 == 0 && i % 3 == 0)
            b++;
        else if (i % 3 == 0)
            n3++;
        else if (i % 2 == 0)
            n2++;

        // Check for arithmetic invariant within the loop
        check_arithmetic_invariant(n, m, n2, n3);

        int cur = b;
        cur -= max(0, n - n2);
        cur -= max(0, m - n3);

        if (cur >= 0) {
            cout << i << endl;
            return 0;
        }
    }
    
    // Check for large value invariant after processing
    check_large_values_invariant(n, m);

    return 0;
}