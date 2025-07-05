#include <bits/stdc++.h>
using namespace std;
long long int Mod = 1000000000 + 7;

void check_prime_factorization_invariant(long long x, const vector<long long>& dels) {
    if (dels.size() > sqrt(x)) {
        cerr << "Warning: Performance bottleneck due to excessive prime factors!" << endl;
        abort();
    }
}

void check_power_calculation_invariant(long long curr, long long dels_i) {
    if (curr / dels_i > 0) {
        cerr << "Warning: Performance bottleneck due to repeated divisions in power calculation!" << endl;
        abort();
    }
}

void check_binpow_invariant(long long power) {
    if (power > 1000000) { // Arbitrary large threshold showing excessive computation
        cerr << "Warning: Performance bottleneck due to large power computation in binpow!" << endl;
        abort();
    }
}

long long int binpow(long long int a, long long int n) {
    long long int res = 1;
    while (n) {
        if (n & 1) res *= a, res %= Mod;
        a *= a;
        a %= Mod;
        n >>= 1;
    }
    return res;
}

int main() {
    long long int x, n;
    cin >> x >> n;
    long long int get = x;
    vector<long long int> dels;
    for (int i = 2; i <= sqrt(x); i++) {
        if (get % i == 0) {
            dels.push_back(i);
            while (get % i == 0) get /= i;
        }
    }
    if (get > 1) dels.push_back(get);

    // Check for excessive prime factors
    check_prime_factorization_invariant(x, dels);

    long long int ans = 1;
    for (int i = 0; i < dels.size(); i++) {
        long long int power = 0, curr = n;
        do {
            power += curr / dels[i];
            curr /= dels[i];

            // Check for repeated divisions causing slowdown
            check_power_calculation_invariant(curr, dels[i]);

        } while (curr);

        // Check for large powers causing excessive computation
        check_binpow_invariant(power);

        ans *= binpow(dels[i] % Mod, power);
        ans %= Mod;
    }
    cout << ans;
}