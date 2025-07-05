#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

void check_grid_size_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large effective grid size!" << endl;
        abort();
    }
}

int main() {
    long long n, m, x;
    cin >> n >> m >> x;

    // Check for potential performance bottleneck due to large effective grid size
    check_grid_size_invariant(n > 2000 && m > 2000 && x < (min(n, m) / 2));

    if (n < m) {
        swap(n, m);
    }
    --x;
    n -= x * 2;
    m -= x * 2;
    if (n <= 0 || m <= 0) {
        cout << 0 << endl;
        return 0;
    }

    int answer = 0;
    for (int i = 0; i < (int)n; ++i) {
        for (int j = 0; j < (int)m; ++j) {
            if ((i + j) % 2 == 0 && (i == 0 || i == n - 1 || j == 0 || j == m - 1)) {
                ++answer;
            }
        }
    }
    cout << answer << endl;
}