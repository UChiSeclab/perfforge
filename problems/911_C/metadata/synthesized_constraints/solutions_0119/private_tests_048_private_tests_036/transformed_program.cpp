#include <bits/stdc++.h>
using namespace std;
const int N = 1000, M = 100;
int k[3], kmax, lit[N];

void check_closeness_invariant(int* k) {
    if ((k[2] - k[0]) <= 2) {  // Arbitrary threshold for closeness
        cerr << "Warning: Closeness invariant triggered - intervals are very close!" << endl;
        abort();
    }
}

#include <numeric> // for std::gcd
void check_common_factor_invariant(int* k) {
    int gcd12 = std::gcd(k[0], k[1]);
    int gcd123 = std::gcd(gcd12, k[2]);
    if (gcd123 > 1) {
        cerr << "Warning: Common factor invariant triggered - intervals have a common factor!" << endl;
        abort();
    }
}

void check_ineffective_max_invariant(int* k) {
    if (k[2] > 2 * (k[0] + k[1])) {  // Arbitrary ratio threshold
        cerr << "Warning: Ineffective max invariant triggered - maximum interval is too large!" << endl;
        abort();
    }
}

bool check(int n = 0, int xmax = 0) {
    if (n == 3) {
        for (int y = xmax; y < N; y++)
            if (!lit[y]) return false;
        return true;
    }
    for (int p = n + 1, q = k[n], x = 0; x < M; x++) {
        for (int y = x; y < N; y += q) lit[y]++;
        if (check(p, max(x, xmax))) return true;
        for (int y = x; y < N; y += q) lit[y]--;
    }
    return false;
}

int main() {
    for (int i = 0; i < 3; i++) cin >> k[i];
    sort(k, k + 3), kmax = k[2];

    // Perform checks for potential performance bottlenecks
    check_closeness_invariant(k);
    check_common_factor_invariant(k);
    check_ineffective_max_invariant(k);

    if (check())
        cout << "YES";
    else
        cout << "NO";
}