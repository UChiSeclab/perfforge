#include <bits/stdc++.h>
using namespace std;

// Check for prime factorization complexity
void check_prime_factorization_complexity(int64_t tmp, int64_t sqrt_b) {
    int64_t factor_count = 0;
    for (int64_t i = 3; i <= sqrt_b; i++) {
        while (tmp % i == 0) {
            factor_count++;
            tmp = tmp / i;
        }
    }
    if (factor_count > 100000) {  // Arbitrary threshold for illustration
        cerr << "Warning: Performance bottleneck condition triggered due to high factorization complexity!" << endl;
        abort();
    }
}

int main() {
    int64_t n, b;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> b;
    map<int64_t, int64_t> mp;
    int64_t count = 0;
    int64_t tmp = b;

    if (tmp % 2 == 0) {
        while (tmp % 2 == 0) {
            count++;
            tmp = tmp / 2;
        }
        mp[2] = count;
    }

    int64_t sqrt_b = sqrt(tmp);
    check_prime_factorization_complexity(tmp, sqrt_b);

    for (int64_t i = 3; i <= sqrt_b; i++) {
        count = 0;
        while (tmp % i == 0) {
            count++;
            tmp = tmp / i;
        }
        if (count) mp[i] += count;
    }

    if (tmp > 2) mp[tmp] += 1;

    int64_t miin = 1000000000000000000;
    int64_t t1, one;
    int64_t cnt;

    for (auto kk : mp) {
        if (kk.second == 0) continue;
        one = kk.first;
        t1 = n;
        cnt = 0;
        while (t1 >= one) {
            cnt += (t1 / one);
            t1 = t1 / one;
        }
        miin = min(miin, cnt / kk.second);
    }
    cout << miin << endl;
}