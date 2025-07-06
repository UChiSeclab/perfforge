#include <bits/stdc++.h>
using namespace std;

void check_large_k_invariant(int n, int k) {
    int max_k = (n * (n - 1)) / 2;
    if (k > 0.9 * max_k) {
        cerr << "Warning: Performance bottleneck condition triggered - k is close to maximum!" << endl;
        abort();
    }
}

void check_iteration_invariant(int n, int estimated_iterations) {
    if (estimated_iterations > 0.5 * n) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations!" << endl;
        abort();
    }
}

int main() {
    int t;
    cin >> t;
    for (int tt = 0; tt < int(t); tt++) {
        int n, k;
        cin >> n >> k;

        // Check for large k invariant
        check_large_k_invariant(n, k);

        string s(n, 'a');
        int iterations = 0;
        for (int i = n - 2; i >= 0; i--) {
            iterations++;
            if (k <= (n - i - 1)) {
                s[i] = 'b';
                s[n - k] = 'b';
                cout << s << endl;
                break;
            }
            k -= (n - i - 1);
        }

        // Check for excessive iterations invariant
        check_iteration_invariant(n, iterations);
    }
}