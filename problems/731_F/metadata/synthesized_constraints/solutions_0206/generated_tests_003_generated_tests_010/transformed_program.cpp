#include <bits/stdc++.h>
using namespace std;

int sum[400007];
int A[200007];

void check_small_leading_value(int smallest, int frequency) {
    if (smallest > 1 && frequency > 10) {
        cerr << "Warning: small leading value with high frequency of common divisors - performance may degrade!" << endl;
        abort();
    }
}

void check_high_frequency(int frequency) {
    if (frequency > 10) {
        cerr << "Warning: high frequency of a value causing repeated configurations - potential slowdown!" << endl;
        abort();
    }
}

void check_excessive_iterations(int iterations) {
    if (iterations > 100000) {
        cerr << "Warning: excessive iterations due to high frequency multiples - performance bottleneck!" << endl;
        abort();
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n + 5; i++) {
        sum[i] = 0;
        A[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        sum[A[i]]++;
    }

    sort(A + 1, A + n + 1);

    // Check for high frequency of smallest element
    check_small_leading_value(A[1], sum[A[1]]);
    
    for (int i = 1; i <= 400002; i++) {
        sum[i] += sum[i - 1];
    }

    long long ans = 0, ans1 = 0;
    if (A[1] == 1) {
        for (int i = 1; i <= n; i++) {
            ans += A[i];
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (A[i] != A[i - 1]) {
                ans1 = 0;
                int iterations = 0;

                for (int j = A[i]; j <= 200000; j += A[i]) {
                    ans1 += (1LL) * (sum[min(200000, A[i] + j - 1)] - sum[j - 1]) * j;
                    iterations += sum[min(200000, A[i] + j - 1)] - sum[j - 1];
                }

                // Check for excessive iterations due to multiples
                check_excessive_iterations(iterations);

                ans = max(ans, ans1);
            }
        }
    }
    printf("%lld\n", ans);
}