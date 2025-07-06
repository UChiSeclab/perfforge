#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
int dp[maxN][2 * maxN];
int w[maxN], q[maxN], v[maxN];
int a[maxN];
int n;

void check_large_input_binary_search(int n) {
    if (n > 500) {
        cerr << "Warning: Performance bottleneck due to large input size and extensive binary search!" << endl;
        abort();
    }
}

void check_variability_in_stops(const vector<int>& stops) {
    int variance_count = 0;
    for (size_t i = 2; i < stops.size(); ++i) {
        if ((stops[i] - stops[i - 1]) != (stops[i - 1] - stops[i - 2])) {
            variance_count++;
        }
    }
    if (variance_count > stops.size() / 2) {
        cerr << "Warning: Performance bottleneck due to high variability in stop sequence!" << endl;
        abort();
    }
}

void check_expensive_check_function_call(int n, int iterations) {
    if (n * iterations > 100000) {
        cerr << "Warning: Performance bottleneck due to excessive check function calls!" << endl;
        abort();
    }
}

int check(double t) {
    for (int i = 0; i < n; i++) {
        int ps = double(i + 1) * t / 10.0;
        if (ps < a[i]) return -1;
        if (ps > a[i]) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    // Insert check for large input and binary search criterion
    check_large_input_binary_search(n);

    // Insert check for variability in stops
    vector<int> stops(a, a + n);
    check_variability_in_stops(stops);

    double lo1 = 0, hi1 = 1000 * 1000 * 10;
    for (int z = 0; z < 400; z++) {
        double mid = (lo1 + hi1) / 2;
        if (check(mid) == -1)
            lo1 = mid;
        else
            hi1 = mid;
    }
    
    double lo2 = 0, hi2 = 1000 * 1000 * 10;
    for (int z = 0; z < 400; z++) {
        double mid = (lo2 + hi2) / 2;
        if (check(mid) < 1)
            lo2 = mid;
        else
            hi2 = mid;
    }

    // Insert check for excessive function calls
    check_expensive_check_function_call(n, 400 * 2); // 400 iterations for each of the two loops

    lo1 += 1e-6;
    int ps1 = lo1 * double(n + 1) / 10.0;
    int ps2 = lo2 * double(n + 1) / 10.0;
    if (ps1 == ps2) {
        cout << "unique" << endl << ps1 << endl;
    } else
        cout << "not unique" << endl;
    return 0;
}