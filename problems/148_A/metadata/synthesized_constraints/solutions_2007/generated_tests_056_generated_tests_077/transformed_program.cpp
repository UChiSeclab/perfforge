#include <bits/stdc++.h>
using namespace std;

// Checker function to detect high loop iterations
void check_large_iterations_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high loop iterations due to large d!" << endl;
        abort();
    }
}

// Checker function to detect numerous unique insertions
void check_unique_insertions_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - numerous unique insertions due to gcd!" << endl;
        abort();
    }
}

int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    // Check for potential performance bottlenecks
    check_large_iterations_invariant(!(k == 1 || l == 1 || m == 1 || n == 1) && d > 50000);
    check_unique_insertions_invariant(!(k == 1 || l == 1 || m == 1 || n == 1) && gcd(gcd(k, l), gcd(m, n)) == 1);

    if (k == 1 || m == 1 || n == 1 || l == 1) {
        cout << d;
    } else {
        set<int> s;
        for (int i = k; i <= d; i += k) {
            s.insert(i);
        }
        for (int i = l; i <= d; i += l) {
            s.insert(i);
        }
        for (int i = m; i <= d; i += m) {
            s.insert(i);
        }
        for (int i = n; i <= d; i += n) {
            s.insert(i);
        }
        cout << s.size();
    }
    return 0;
}