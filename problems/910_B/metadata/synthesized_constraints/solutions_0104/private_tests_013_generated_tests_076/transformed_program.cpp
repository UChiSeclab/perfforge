#include <bits/stdc++.h>
using namespace std;

// Checker functions to detect performance bottlenecks
void check_high_recursion_invariant(long long a, long long n) {
    if (a >= n * 0.9) { // If the length of 'a' is close to 'n', indicating potential recursion depth issues
        cerr << "Warning: High recursion depth invariant triggered!" << endl;
        abort();
    }
}

void check_inefficient_distribution_invariant(long long totalLength, long long n) {
    if (totalLength > n * 2) { // If the total required length for sides greatly exceeds 'n'
        cerr << "Warning: Inefficient distribution invariant triggered!" << endl;
        abort();
    }
}

void check_excessive_calls_invariant(long long k, long long n) {
    if (k > 5 && k < 10) { // If too many configurations are explored due to close sums with 'n'
        cerr << "Warning: Excessive calls invariant triggered!" << endl;
        abort();
    }
}

const long long inf = 1e18 + 5LL;
const long long inf32 = INT_MAX;
const long long mod = 1e9 + 7LL;
const long long N = (1e6 + 10);
void solve(long long t);
void solve();
void ITO();
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ITO();
    long long t = 1;
    for (long long i = 0; i < t; i++) solve(i + 1);
    return 0;
}

bool check(vector<long long>& arr, long long n, vector<long long>& each, long long k, long long i) {
    if (i == 6) {
        if (*max_element(each.begin(), each.end()) <= n) return 1;
        else return 0;
    }
    for (long long j = 0; j < k; ++j) {
        each[j] += arr[i];
        if (check(arr, n, each, k, i + 1)) return 1;
        each[j] -= arr[i];
    }
    return 0;
}

void solve(long long TcNumber) {
    long long n;
    cin >> n;
    long long a, b;
    cin >> a >> b;

    // Invariant checks
    check_high_recursion_invariant(a, n); // Check for recursion depth issues
    check_inefficient_distribution_invariant(4 * a + 2 * b, n); // Check for inefficient distribution of pieces

    vector<long long> arr({a, a, a, a, b, b});
    long long res = 1;

    while (res < 6) {
        vector<long long> each(res, 0);
        if (check(arr, n, each, res, 0)) break;
        res++;
    }

    // Check for excessive call scenarios
    check_excessive_calls_invariant(res, n);

    cout << res;
    cout << "\n";
    return;
}

void solve() {}
void ITO() {}