#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;

// Checker functions
void check_factorization_overhead(long long n, long long k) {
    if (n > 450000 && k > 450000) {
        cerr << "Warning: Performance bottleneck condition triggered: Factorization Overhead" << endl;
        abort();
    }
}

void check_nested_loop_complexity(long long k, long long n) {
    if (k > n - 50000) {
        cerr << "Warning: Performance bottleneck condition triggered: Nested Loop Complexity" << endl;
        abort();
    }
}

void check_factorization_repetition(long long n) {
    if (n > 450000) {
        cerr << "Warning: Performance bottleneck condition triggered: Factorization Repetition" << endl;
        abort();
    }
}

void check_extensive_fact_usage(long long n, long long k) {
    if (k == n) {
        cerr << "Warning: Performance bottleneck condition triggered: Extensive Use of `fact` Function" << endl;
        abort();
    }
}

void fact(long long x, long long zn, vector<long long> &p) {
    for (long long i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            p[i] += zn;
        }
    }
    if (x > 1) p[x] += zn;
}

long long f(long long many, long long from) {
    long long i, j;
    if (many > from) return 0;
    vector<long long> p(from + 2, 0);
    for (i = from; i > from - many; i--) fact(i, 1, p);
    for (i = 1; i <= many; i++) fact(i, -1, p);
    long long ans = 1;
    for (i = 2; i < p.size(); i++) {
        for (j = 0; j < p[i]; j++) {
            ans *= i;
            ans %= MOD;
        }
    }
    return ans;
}

int main() {
    long long ans = 0;
    long long n, k;
    cin >> n >> k;

    // Insert performance checkers
    check_factorization_overhead(n, k);
    check_nested_loop_complexity(k, n);
    check_factorization_repetition(n);
    check_extensive_fact_usage(n, k);

    long long answer = 0;
    for (long long i = 1; i <= n; i++) {
        long long minimal = i;
        long long rest = n - i;
        long long places = rest / minimal;
        answer += f(k - 1, places);
        answer %= MOD;
    }
    cout << answer;
    return 0;
}