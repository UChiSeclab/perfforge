#include <bits/stdc++.h>
using namespace std;

bool sc[10000007];
vector<long long int> pr;

void sieve() {
    for (long long int i = 2; i * i < 10000007; i++) {
        if (!sc[i]) {
            for (long long int j = i * i; j < 10000007; j += i) sc[j] = 1;
        }
    }
    pr.push_back(2);
    for (long long int i = 3; i < 10000007; i += 2)
        if (!sc[i]) pr.push_back(i);
}

pair<long long int, long long int> pf[10000007];

void pri_fact(long long int n) {
    long long int i, u = 0;
    for (i = 0; i < pr.size() && n != 1; i++) {
        long long int c = 0;
        while (!(n % pr[i])) {
            n /= pr[i];
            c++;
        }
        if (c) {
            pf[u].first = pr[i];
            pf[u].second = c;
            u++;
        }
    }
    if (n > 1) {
        pf[u].first = n;
        pf[u].second = 1;
    }
}

// Checker functions based on performance invariants

void check_large_prime_factorization(bool condition) {
    if (condition) {
        cerr << "Warning: Large prime factorization detected, potential performance bottleneck!" << endl;
        abort();
    }
}

void check_high_exponentiation(bool condition) {
    if (condition) {
        cerr << "Warning: High exponentiation computation detected, potential performance slowdown!" << endl;
        abort();
    }
}

void check_sieve_calculation(bool condition) {
    if (condition) {
        cerr << "Warning: Extensive sieve calculations detected, potential performance bottleneck!" << endl;
        abort();
    }
}

int main() {
    long long int x, y;
    cin >> x >> y;

    if (y % x != 0) {
        cout << -1;
        return 0;
    }

    if (x == y) {
        cout << 0;
        return 0;
    }

    // Check for potential sieve bottleneck
    check_sieve_calculation(y / x > 1000000);  // Arbitrary threshold for extensive sieve

    sieve();

    long long int z = y / x;
    pri_fact(z);

    // Check for large prime factorization before further processing
    check_large_prime_factorization(pf[0].first > 100000);  // Arbitrary large prime threshold

    long long int s = pf[0].second + pf[1].second;

    // Check for high exponentiation
    check_high_exponentiation(s > 20);  // Arbitrary threshold for high exponentiation

    if ((long long int)(pow(pf[0].first, pf[0].second) * 
                        pow(pf[1].first, pf[1].second)) == z) {
        long long int ct = 0, tc = 0, i;
        for (i = 0; pf[i].first != 0; i++) {
            ct++;
            if (pf[i].first == 2) {
                tc = 0;
            } else if (pf[i].first == 3) {
                tc = 0;
            } else {
                tc = 1;
            }
        }
        if (ct > 2) {
            cout << -1;
            return 0;
        } else if (tc == 1) {
            cout << -1;
            return 0;
        }
        cout << s;
        return 0;
    } else
        cout << -1;
    return 0;
}