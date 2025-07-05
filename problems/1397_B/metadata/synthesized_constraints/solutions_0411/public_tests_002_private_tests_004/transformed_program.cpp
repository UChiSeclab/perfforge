#include <bits/stdc++.h>
const long long N = 300010;
long long arr[N];
using namespace std;

bool binasea(long long arr[], long long n, long long key) {
    long long hi = n - 1, lo = 0, mid;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (arr[mid] == key)
            return true;
        else if (arr[mid] > key)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return 0;
}

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b % 2) res *= a;
        b /= 2;
        a *= a;
    }
    return res;
}

void check_upb_invariant(long long upb, long long threshold) {
    if (upb > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large `upb` value!" << endl;
        abort();
    }
}

void check_power_invariant(long long base, long long exponent, long long threshold) {
    if (exponent > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered due to large exponent in `power` function!" << endl;
        abort();
    }
}

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    long long t = 1, n;
    long long check = pow(10, 15);
    while (t--) {
        cin >> n;
        long long sum = 0;
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr, arr + n);
        long long mini = abs(sum - n);
        long long upb = 1;
        if (n < 40) {
            while (power(upb, n - 1) <= check) {
                upb++;
                // Check for large upb values
                check_upb_invariant(upb, 10000 /* example threshold */);
            }
        }
        long long k = 0;
        for (long long i = 2; i < upb + 1; i++) {
            sum = 0;
            for (long long j = 0; j < n; j++) {
                // Check for large exponents
                check_power_invariant(i, j, 1000 /* example threshold */);
                sum += abs(power(i, j) - arr[j]);
            }
            mini = min(mini, sum);
        }
        cout << mini << "\n";
    }
    return 0;
}