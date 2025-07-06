#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
set<pair<float, float>> s;
float x[3010], y[3010];

void check_large_point_pairs(int n) {
    if (n > 1500) { // Arbitrary threshold chosen based on quadratic growth
        cerr << "Warning: Performance bottleneck condition triggered - large number of point pairs!" << endl;
        abort();
    }
}

void check_point_distribution(int successfulChecks, int totalChecks) {
    if (successfulChecks > totalChecks * 0.75) { // If more than 75% of checks are successful
        cerr << "Warning: Performance bottleneck condition triggered - high frequency of valid middle points!" << endl;
        abort();
    }
}

int main() {
    int n, ans = 0;
    cin >> n;

    // Check for large number of point pairs
    check_large_point_pairs(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        s.insert({x[i], y[i]});
    }

    int successfulChecks = 0;
    int totalChecks = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            float tmpx = (x[i] + x[j]) / 2, tmpy = (y[i] + y[j]) / 2;
            totalChecks++;
            if (s.find({tmpx, tmpy}) != s.end()) {
                successfulChecks++;
                ans++;
            }
        }
    }

    // Check for distribution of points
    check_point_distribution(successfulChecks, totalChecks);

    cout << ans;
}