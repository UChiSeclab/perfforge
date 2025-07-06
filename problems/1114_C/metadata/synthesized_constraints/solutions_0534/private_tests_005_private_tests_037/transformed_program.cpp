#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using D = double;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

void check_prime_factorization_cost(ull n, ull b) {
    int prime_factor_count = 0;
    ull original_b = b;
    for (ull i = 2; i <= sqrt(b); ++i) {
        while (b % i == 0) {
            b /= i;
            prime_factor_count++;
        }
    }
    if (b > 1) {
        prime_factor_count++;
    }
    if (prime_factor_count > 10) {
        cerr << "Warning: High prime factorization cost detected for base " << original_b << endl;
        abort();
    }
}

void check_complex_factorization(ull b) {
    ull factors = 0;
    ull original_b = b;
    for (ull i = 2; i <= sqrt(b); ++i) {
        while (b % i == 0) {
            b /= i;
            factors++;
        }
    }
    if (b > 1) {
        factors++;
    }
    if (factors > 20) {
        cerr << "Warning: Complex factorization detected for base " << original_b << endl;
        abort();
    }
}

void check_large_factor_base(ull b) {
    bool large_divisor_detected = false;
    for (ull i = 2; i <= sqrt(b); ++i) {
        if (b % i == 0 && b / i > 10) {
            large_divisor_detected = true;
            break;
        }
    }
    if (large_divisor_detected) {
        cerr << "Warning: Large factor impact detected for base " << b << endl;
        abort();
    }
}

ull f1(ull n, ull m) {
    vector<pair<ull, ull>> t;
    ull sr = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        sr = 0;
        while (n % i == 0) {
            n /= i;
            sr++;
        }
        if (sr != 0) {
            t.push_back(make_pair(i, sr));
        }
    }
    if (n != 1) {
        t.push_back(make_pair(n, 1));
    }
    ull ans1 = 18e18;
    for (int i = 0; i < t.size(); i++) {
        ull temp = 0;
        ull s = 1;
        while (s <= m / t[i].first) {
            s *= t[i].first;
            temp += (m / s);
        }
        ans1 = min(ans1, temp / t[i].second);
    }
    return ans1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
    ull n, m;
    cin >> n >> m;

    // Insert performance checkers before main computations
    check_prime_factorization_cost(n, m);
    check_complex_factorization(m);
    check_large_factor_base(m);

    cout << f1(m, n);
    return 0;
}