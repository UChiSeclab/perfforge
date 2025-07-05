#include <bits/stdc++.h>
using namespace std;

long long n, b, key, k, num[10005][2], ans, cnt, step;

void check_large_prime_factor_search(long long b) {
    long long count_iterations = 0;
    long long temp_key = b;
    for (long long i = 2; i <= sqrt(b); i++) {
        while (temp_key % i == 0) {
            temp_key /= i;
            count_iterations++;
        }
    }
    if (temp_key != 1) {
        count_iterations++;
    }
    if (count_iterations > 10000) { // Arbitrary threshold for illustration
        cerr << "Warning: Large prime factor search triggered - high iteration count in factorization" << endl;
        abort();
    }
}

void check_expensive_division_operations(long long b) {
    long long division_count = 0;
    long long temp_key = b;
    for (long long i = 2; i <= sqrt(b); i++) {
        while (temp_key % i == 0) {
            temp_key /= i;
            division_count++;
        }
    }
    if (division_count > 10000) { // Arbitrary threshold for excessive division
        cerr << "Warning: Expensive division operations triggered - excessive divisions during factorization" << endl;
        abort();
    }
}

void check_high_iteration_count(long long b) {
    long long iteration_estimate = sqrt(b);
    if (iteration_estimate > 1000000) { // Arbitrary threshold for high loop iteration
        cerr << "Warning: High iteration count triggered due to base complexity" << endl;
        abort();
    }
}

int main() {
    while (cin >> n >> b) {
        check_large_prime_factor_search(b); // Check for large prime factor search
        check_expensive_division_operations(b); // Check for expensive division operations
        check_high_iteration_count(b); // Check for high iteration counts due to base complexity

        memset(num, 0, sizeof(num));
        key = b;
        k = 0;
        int flag;
        for (long long i = 2; i <= sqrt(b); i++) {
            flag = 0;
            while (key % i == 0) {
                num[k][0] = i;
                num[k][1]++;
                key = key / i;
                flag = 1;
            }
            if (flag) {
                k++;
            }
        }
        if (key != 1) {
            num[k][0] = key;
            num[k][1] = 1;
            k++;
        }
        ans = 1;
        ans = ans << 60;
        for (long long i = 0; i < k; i++) {
            step = n;
            cnt = 0;
            while (step) {
                step = step / num[i][0];
                cnt = cnt + step;
            }
            ans = min(ans, cnt / num[i][1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}