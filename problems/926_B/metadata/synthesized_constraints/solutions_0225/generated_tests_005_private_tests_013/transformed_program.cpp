#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
long long a[N];

bool go(long long n, long long m) {
    long long i, l = (a[n - 1] - a[0]) / m;
    for (i = 1; i < n; i++) {
        if (((a[i] - a[0]) % l) != 0) return false;
    }
    return true;
}

void check_large_range_invariant(long long range) {
    if (range > 1e9) {
        cerr << "Warning: large_range_invariant triggered - large coordinate range" << endl;
        abort();
    }
}

void check_divisor_iterations_invariant(long long iterations) {
    if (iterations > 1e5) {
        cerr << "Warning: divisor_iterations_invariant triggered - excessive divisor checks" << endl;
        abort();
    }
}

void check_function_calls_invariant(int calls) {
    if (calls > 1000) {
        cerr << "Warning: function_calls_invariant triggered - excessive function calls" << endl;
        abort();
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t, i, j, n, m, l, r, ans = -1;
    scanf("%lld", &n);
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    l = a[n - 1] - a[0];
    
    // Check for large coordinate range
    check_large_range_invariant(l);

    vector<long long> v;
    long long divisor_iterations = 0;
    for (i = 1; i <= (l / i); i++) {
        divisor_iterations++;
        if (l % i == 0) {
            if (i >= (n - 1)) v.push_back(i);
            if (i != (l / i) && (l / i) >= (n - 1)) v.push_back(l / i);
        }
    }

    // Check for excessive divisor iterations
    check_divisor_iterations_invariant(divisor_iterations);

    sort(v.begin(), v.end());
    r = 0;
    int function_calls = 0;
    while (ans == -1) {
        function_calls++;
        if (go(n, v[r]) == true) ans = v[r] - n + 1;
        r++;
    }

    // Check for excessive function calls
    check_function_calls_invariant(function_calls);

    printf("%lld\n", ans);
    return 0;
}