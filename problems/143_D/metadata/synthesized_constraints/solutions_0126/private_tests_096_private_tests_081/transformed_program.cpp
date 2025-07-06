#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
int n, m, a[N][N];

bool check(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == 0)
        return 1;
    else
        return 0;
}

void check_large_dimensions(bool condition) {
    if (condition) {
        cerr << "Warning: Large dimensions leading to excessive checks!" << endl;
        abort();
    }
}

void check_large_iteration_count(bool condition) {
    if (condition) {
        cerr << "Warning: Large iteration count due to high n and m!" << endl;
        abort();
    }
}

void check_intensive_checks(bool condition) {
    if (condition) {
        cerr << "Warning: Intensive checks due to dense placement patterns!" << endl;
        abort();
    }
}

int main() {
    cin >> n >> m;

    // Performance-checking conditions
    check_large_dimensions(n > 800 && m > 800); // Check 1
    check_large_iteration_count(n * m > 700000); // Check 2

    if (n == 1 || m == 1) {
        cout << max(n, m);
        return 0;
    }
    if (n == 2 || m == 2) {
        int ans = max(n, m) / 2;
        if (ans % 2 == 0)
            ans = (ans / 2) * 4 + (max(n, m) % 2) * 2;
        else
            ans = (ans / 2 + 1) * 4;
        cout << ans;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                a[i][j] = 1;
                ans++;
            } else {
                a[i][j] = 0;
            }
        }
    }

    check_intensive_checks(n > 30 && m > 30 && n * m > 500000); // Check 3, placed here after initial setup
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && check(i + 1, j + 2) && check(i - 1, j + 2) &&
                check(i + 1, j - 2) && check(i - 1, j - 2) && check(i + 2, j + 1) &&
                check(i - 2, j + 1) && check(i + 2, j - 1) && check(i - 2, j - 1)) {
                ans++;
            }
        }
    }
    
    cout << ans;
}