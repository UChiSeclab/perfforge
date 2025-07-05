#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFLL = 1e18;
const int MOD = 1e9 + 9;
const long double PI = atan(1.0) * 4L;
const int MAXINT = 1e5 + 1;

long long gcd(long long a, long long b) {
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

// Checker functions
void check_gcd_iterations_invariant(long long GCD) {
    if (sqrtl(GCD) > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered due to high number of divisor checks!" << endl;
        abort();
    }
}

void check_large_gcd_invariant(long long GCD) {
    if (GCD > 1e9) {
        cerr << "Warning: Large GCD detected, potential performance impact!" << endl;
        abort();
    }
}

void check_large_coordinate_span_invariant(long long min_coord, long long max_coord) {
    if ((max_coord - min_coord) > 1e9) {
        cerr << "Warning: Large coordinate span detected, potential performance impact!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    long long min_coord = a[0], max_coord = a[n - 1];
    check_large_coordinate_span_invariant(min_coord, max_coord);  // Check large coordinate spans

    long long sum = 0, GCD = 0;
    for (int i = 1; i < n; i++)
        sum += a[i] - a[i - 1], GCD = gcd(GCD, a[i] - a[i - 1]);
    
    check_large_gcd_invariant(GCD);  // Check large GCD impact

    long long ans = INFLL;
    check_gcd_iterations_invariant(GCD);  // Check for potential slowdown due to GCD divisor checks

    for (int i = 1; i < sqrtl(GCD) + 1; i++)
        if (GCD % i == 0) {
            int p = i;
            ans = min(ans, sum / p - (n - 1));
            p = GCD / i;
            ans = min(ans, sum / p - (n - 1));
        }

    cout << ans << '\n';
    return 0;
}