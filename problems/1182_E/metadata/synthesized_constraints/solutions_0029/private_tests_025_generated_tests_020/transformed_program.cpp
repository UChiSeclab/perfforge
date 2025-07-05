#include <bits/stdc++.h>
const long long mod1 = 1e9 + 6;
const long long mod = 1e9 + 7;
using namespace std;

long long ar[4], mul[4][4][62], ax[4][4], ax1[4][4], ar1[4];
map<long long, long long> lis, lis1[4], xd;

long long binpow(long long x, long long y) {
    check_exponentiation_invariant(x, y); // Check for expensive exponentiation
    long long tich = 1;
    while (y) {
        if ((y & 1)) {
            tich *= x;
            tich %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return tich;
}

void check_factorization_invariant(long long num) {
    // Check for large prime factors or the number itself being a large prime
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            int factor_count = 0;
            while (num % i == 0) {
                num /= i;
                factor_count++;
            }
            if (factor_count > 10) { // Arbitrary threshold for "complex" factorization
                std::cerr << "Warning: Factorization invariant triggered - too many factors for a number!" << std::endl;
                abort();
            }
        }
    }
    if (num > 1) { // num is a prime greater than sqrt of the original number
        if (num > 1e9) { // Arbitrary threshold for large primes
            std::cerr << "Warning: Factorization invariant triggered - number has large prime factor!" << std::endl;
            abort();
        }
    }
}

void check_large_modulus_operations(long long value) {
    // Check if modulus operations are on excessively large numbers
    if (value > 1e15) { // Arbitrary large threshold for modulus base value
        std::cerr << "Warning: Modulus invariant triggered - large number in modulus operations!" << std::endl;
        abort();
    }
}

signed main() {
    long long a, b, c, d, num, i, j, k, l, tich = 1, wow, cac;
    cin >> num >> ar[1] >> ar[2] >> ar[3] >> c;
    cac = c;

    check_factorization_invariant(ar[1]);
    check_factorization_invariant(ar[2]);
    check_factorization_invariant(ar[3]);

    mul[1][3][0] = 1;
    mul[2][3][0] = 1;
    mul[3][3][0] = 1;
    mul[3][2][0] = 1;
    mul[2][1][0] = 1;
    
    for (i = 1; i <= 60; i++) {
        for (j = 1; j <= 3; j++) {
            for (k = 1; k <= 3; k++) {
                for (l = 1; l <= 3; l++) {
                    mul[j][k][i] += mul[j][l][i - 1] * mul[l][k][i - 1];
                    mul[j][k][i] %= mod1;
                }
            }
        }
    }

    check_large_modulus_operations(cac);

    for (i = 2; i * i <= cac; i++) {
        if (cac % i == 0) {
            lis[i]++;
            while (cac % i == 0) {
                cac /= i;
                xd[i]++;
            }
        }
    }

    if (cac > 1) {
        xd[cac]++;
        lis[cac]++;
    }

    for (i = 1; i <= 3; i++) {
        for (j = 2; j * j <= ar[i]; j++) {
            if (ar[i] % j == 0) {
                lis[j]++;
                while (ar[i] % j == 0) {
                    ar[i] /= j;
                    lis1[i][j]++;
                }
            }
        }
        if (ar[i] != 1) {
            lis1[i][ar[i]]++;
            lis[ar[i]]++;
        }
    }

    ax[1][1] = 1;
    ax[2][2] = 1;
    ax[3][3] = 1;
    wow = num - 3;

    for (i = 60; i >= 0; i--) {
        if (wow >= (1ll << i)) {
            wow -= (1ll << i);
            for (j = 1; j <= 3; j++) {
                for (k = 1; k <= 3; k++) {
                    ax1[j][k] = ax[j][k];
                    ax[j][k] = 0;
                }
            }
            for (j = 1; j <= 3; j++) {
                for (k = 1; k <= 3; k++) {
                    for (l = 1; l <= 3; l++) {
                        ax[j][k] += ax1[j][l] * mul[l][k][i];
                        ax[j][k] %= mod1;
                    }
                }
            }
        }
    }

    map<long long, long long>::iterator ite = lis.begin();

    while (ite != lis.end()) {
        for (i = 1; i <= 3; i++) {
            ar1[i] = xd[ite->first] * i + lis1[i][ite->first];
            ar[i] = 0;
        }
        for (i = 1; i <= 3; i++) {
            for (j = 1; j <= 3; j++) {
                ar[i] += ar1[j] * ax[j][i];
                ar[i] %= mod1;
            }
        }
        tich *= binpow(ite->first, ar[3]);
        tich %= mod;
        ite++;
    }

    cout << (tich * binpow(binpow(c, num), mod - 2)) % mod;
}