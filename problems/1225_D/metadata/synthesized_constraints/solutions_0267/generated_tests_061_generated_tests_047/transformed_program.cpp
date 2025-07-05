#include <bits/stdc++.h>
using namespace std;

long long n, k, a, ans, to[100005], arr[100005], cnt, A;
int tmp;

// Check functions
void check_power_computation_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered! Excessive power computation." << endl;
        abort();
    }
}

void check_nested_loop_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered! Excessive iterations over divisors." << endl;
        abort();
    }
}

void check_multiplicative_combinations_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered! Numerous multiplicative combinations." << endl;
        abort();
    }
}

long long pang(long long x, long long y) {
    if (y == 0) return 1;
    long long ret;
    ret = pang(x, y / 2);
    if (ret > 1e5) return 1e10 + 1;
    ret *= ret;
    if (y % 2 == 1) {
        ret *= x;
    }
    if (ret > 1e10) return 1e10 + 1;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    ans = 0;

    // Check power computation invariant
    check_power_computation_invariant(k > 50);  // Arbitrary threshold for demonstration

    for (long long i = 1; i <= 1e5 + 1; i++) {
        if (pang(i, k) > 1e10) {
            tmp = i - 1;
            break;
        }
        to[i] = pang(i, k);
    }

    for (long long i = 1; i <= n; i++) {
        cin >> a;
        A = a;
        cnt = 1;
        
        // Check nested loop over divisors invariant
        check_nested_loop_invariant(n > 10000);  // Arbitrary threshold for demonstration

        for (int j = 2; j <= sqrt(A); j++) {
            if (A % j == 0) cnt *= j;
            while (A % j == 0) A /= j;
        }
        if (A > 1) {
            cnt *= A;
        }

        for (int j = cnt; j <= tmp; j += cnt) {
            if (to[j] / a > 1e5) break;
            if (to[j] % a == 0 && to[j] / a <= 1e5) {
                ans += arr[to[j] / a];
            }
        }

        // Check multiplicative combinations invariant
        check_multiplicative_combinations_invariant(cnt > 1000);  // Arbitrary threshold for demonstration

        arr[a]++;
    }

    cout << ans << endl;
}