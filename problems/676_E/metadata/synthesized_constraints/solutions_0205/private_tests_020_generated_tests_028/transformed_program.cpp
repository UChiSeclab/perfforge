#include <bits/stdc++.h>
using namespace std;

const int max_n = 100 * 1000;
int a[max_n + 1];
const int mod[] = {1000 * 1000 * 1000 + 7, 1000 * 10000 * 1000 + 9};
const int inf = 1e9;

int str2int(string s) {
    stringstream ss(s);
    int x;
    ss >> x;
    return x;
}

void check_large_polynomial_degree(int n) {
    if (n > 50000) { // Assuming 50,000 as a threshold for "large" based on practical observations
        cerr << "Warning: Performance bottleneck condition triggered - large polynomial degree" << endl;
        abort();
    }
}

void check_high_known_coefficient_count(int knownCoefficients, int n) {
    if (knownCoefficients > n / 2) { // Assuming a threshold of more than half coefficients known
        cerr << "Warning: Performance bottleneck condition triggered - high count of known coefficients" << endl;
        abort();
    }
}

void check_repeated_division_polynomial(int n, int modOps) {
    if (modOps > n) { // Assuming more than `n` modular operations is excessive
        cerr << "Warning: Performance bottleneck condition triggered - excessive polynomial division checks" << endl;
        abort();
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    // Check for large polynomial degree
    check_large_polynomial_degree(n);

    int cnt = 0;
    for (int i = 0; i < (n + 1); i++) {
        string s;
        cin >> s;
        if (s[0] == '?') {
            cnt++;
            a[i] = inf;
        } else {
            a[i] = str2int(s);
        }
    }

    // Check for high count of known coefficients
    check_high_known_coefficient_count(n + 1 - cnt, n);

    if (cnt) {
        if (k == 0)
            cout << ((a[0] == 0 || (a[0] == inf && (n + 1 - cnt) % 2)) ? "YES" : "NO") << endl;
        else
            cout << (n % 2 ? "YES" : "NO") << endl;
        return 0;
    }

    int modOps = 0; // Track the number of modular operations
    for (int m = 0; m < (2); m++) {
        long long sum = 0;
        for (int i = (n); i >= 0; i--) {
            sum = (sum * k + a[i]) % mod[m];
            modOps++; // Increment modular operation count
        }
        if (sum != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    // Check for excessive polynomial division checks
    check_repeated_division_polynomial(n, modOps);

    cout << "YES" << endl;
    return 0;
}