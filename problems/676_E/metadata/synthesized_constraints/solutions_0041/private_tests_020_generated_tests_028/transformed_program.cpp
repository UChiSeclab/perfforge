#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int nm = 100010;
int n, k;
long long a[nm];
long long mod[30];
long long du[30], x[30];

void check_coefficient_calculation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered - high calculation overhead for polynomial coefficients." << endl;
        abort();
    }
}

void check_high_degree_complexity_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered - complexity of operations with high-degree polynomial." << endl;
        abort();
    }
}

void check_input_size_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck triggered - large input size with initialized coefficients." << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    memset(a, 0x3f, sizeof(a));
    int d = 0;
    for (int i = 0; i <= n; ++i) {
        string s;
        cin >> s;
        if (s[0] != '?') {
            stringstream ss;
            ss << s;
            ss >> a[i];
            d++;
        }
    }

    // Check for large input with initialized coefficients
    check_input_size_invariant(n > 50000 && d > n / 2);

    if (d == n + 1) {
        // Check for high degree polynomial complexity
        check_high_degree_complexity_invariant(n > 80000);

        mod[1] = 1000000007;
        for (int i = 2; i < 30; ++i)
            mod[i] = (mod[i - 1] * (long long)rand() + (long long)rand()) % mod[1];
        for (int i = 1; i < 30; ++i) x[i] = 1ll % mod[i];
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j < 30; ++j) {
                du[j] = (du[j] + a[i] * x[j]) % mod[j];
                x[j] = (x[j] * (long long)k) % mod[j];
            }
        }
        
        // Check for polynomial coefficient calculation overhead
        check_coefficient_calculation_invariant(n > 50000);

        for (int i = 1; i < 30; ++i)
            if (du[i]) {
                cout << "No\n";
                return 0;
            }
        cout << "Yes\n";
        return 0;
    }

    if (k == 0) {
        if (a[0] < inf) {
            if (a[0] == 0) {
                cout << "Yes\n";
            } else
                cout << "No\n";
            return 0;
        } else {
            if (d % 2 == 0) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
            return 0;
        }
    }

    if (n % 2 == 0)
        cout << "No\n";
    else
        cout << "Yes\n";
}