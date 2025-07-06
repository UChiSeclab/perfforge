#include <bits/stdc++.h>
using namespace std;
const int Nmax = 1e2 + 17, mod = 1e6;
bool a[Nmax] = {0}, b[Nmax] = {0};

// Checker functions for performance invariants
void check_high_initial_happiness_threshold(int b, int g, int n, int m) {
    if ((b > n / 2 && g > m / 2) && abs(b - g) < (n + m) / 10) {
        cerr << "Warning: Potential equilibrium in initial happiness distribution!" << endl;
        abort();
    }
}

void check_limited_happiness_propagation(int b, int g, int n, int m) {
    if ((b < n / 3 && g < m / 3) && (b + g < (n + m) / 4)) {
        cerr << "Warning: Limited initial happiness propagation detected!" << endl;
        abort();
    }
}

void check_near_modulo_restriction(int n, int m) {
    if ((n % m == 0) || (m % n == 0)) {
        cerr << "Warning: Near modulo alignment may slow happiness spread!" << endl;
        abort();
    }
}

int main(void) {
    int n, m, x, g, ans;
    scanf("%d%d", &n, &m);
    ans = n + m;
    scanf("%d", &g);
    for (int i = 0; i < g; i++) {
        scanf("%d", &x);
        a[x] = 1;
        ans--;
    }
    
    scanf("%d", &g);
    for (int i = 0; i < g; i++) {
        scanf("%d", &x);
        b[x] = 1;
        ans--;
    }

    // Performance checks
    check_high_initial_happiness_threshold(n, g, n, m);
    check_limited_happiness_propagation(n, g, n, m);
    check_near_modulo_restriction(n, m);

    int i = 0, z = 0, iter = 0;
    while (iter < mod && ans) {
        iter++;
        if (a[i] || b[z]) {
            if (a[i] == 0) ans--;
            if (b[z] == 0) ans--;
            a[i] = b[z] = 1;
        }
        i++;
        z++;
        if (i >= n) i -= n;
        if (z >= m) z -= m;
    }
    if (ans == 0)
        cout << "Yes";
    else
        cout << "No";
}