#include <bits/stdc++.h>
using namespace std;

long double nCr(unsigned long long n, unsigned long long r) {
    if (n < r) return 0;
    if (n == r) return 1;
    return (nCr(n - 1, r) / (n - r)) * n;
}

void check_combinatorial_invariant(int vec_h, int n) {
    if (vec_h >= n) {
        cerr << "Warning: combinatorial_invariant triggered - high combinatorial complexity due to large vec[h]" << endl;
        abort();
    }
}

void check_recursive_invariant(int nCr_calls) {
    if (nCr_calls > 5000) { // Threshold for excessive recursion
        cerr << "Warning: recursive_invariant triggered - excessive recursive calls in nCr" << endl;
        abort();
    }
}

void check_iterative_invariant(int loop_iterations) {
    if (loop_iterations > 50) { // Threshold for excessive loop iterations
        cerr << "Warning: iterative_invariant triggered - excessive loop iterations" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, h;
    cin >> n >> m >> h;
    h--;
    n--;

    int sum = 0;
    vector<int> vec(m);
    for (auto i = 0; i < (long long)(m); i++) {
        cin >> vec[i];
        sum += vec[i];
    }
    sum--;
    vec[h]--;

    // Insert combinatorial invariant check after processing input
    check_combinatorial_invariant(vec[h], n + 1);

    if (sum < n) return cout << -1, 0;

    long double res = 0;
    int nCr_calls = 0;
    for (auto i = 1; i <= (long long)(vec[h]); i++) {
        int remR = n - i;
        int remN = sum - vec[h];
        long double a = nCr(remN, remR);
        long double b = nCr(vec[h], i);
        long double d = nCr(sum, n);
        res += (a / d) * b;

        // Increment call count for nCr
        nCr_calls += 3;
    }

    // Check if excessive recursive calls were made
    check_recursive_invariant(nCr_calls);

    // Check for excessive loop iterations
    check_iterative_invariant(vec[h]);

    cout << fixed << setprecision(9) << res << '\n';
    return 0;
}