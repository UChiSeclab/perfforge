#include <bits/stdc++.h>

int A[2000009], B[2000009], C[2000009];
int a, b, k, i, j, max, last, res, cnt;

// Checker functions to monitor potential bottlenecks
void check_prime_sieve_invariant(int b) {
    if (b > 500000) {
        cerr << "Warning: prime_sieve_invariant triggered - unnecessary sieving range!" << endl;
        abort();
    }
}

void check_large_range_invariant(int a, int b) {
    if (b - a > 800000) {
        cerr << "Warning: large_range_invariant triggered - large range processing!" << endl;
        abort();
    }
}

void check_high_prime_count_invariant(int a, int b, int k) {
    if (k > (b - a) / 2) {
        cerr << "Warning: high_prime_count_invariant triggered - high k relative to range!" << endl;
        abort();
    }
}

void check_prime_counting_invariant(int a, int b) {
    if (b - a > 800000) {
        cerr << "Warning: prime_counting_invariant triggered - inefficient range processing!" << endl;
        abort();
    }
}

int main() {
    while (scanf("%d %d %d", &a, &b, &k) == 3) {
        // Apply checkers after input has been read
        check_prime_sieve_invariant(b);
        check_large_range_invariant(a, b);
        check_high_prime_count_invariant(a, b, k);
        check_prime_counting_invariant(a, b);

        A[0] = 1;
        A[1] = 1;
        for (i = 3;; i = i + 2) {
            if (i * i > 2 * b) break;
            if (A[i] == 0)
                for (j = i * i; j <= 2 * b; j = j + i + i) A[j] = 1;
        }
        for (i = 2 * b; i >= 0; i--) B[i] = 0;
        cnt = 0;
        last = 2 * b;
        for (i = 2 * b; i >= 0; i--) {
            if ((i % 2 != 0 && A[i] == 0) || i == 2) {
                if (cnt == 0) last = i;
                cnt++;
            }
            if (cnt > k) {
                cnt--;
                for (j = last - 1;; j--)
                    if ((j % 2 != 0 && A[j] == 0) || j == 2) {
                        last = j;
                        break;
                    }
            }
            if (cnt >= k) B[i] = last;
        }
        for (i = a; i <= b; i++) C[i] = 0;
        max = -1;
        for (i = a; i <= b; i++) {
            if (B[i] != 0) {
                if (max == -1 || B[i] - i > max) max = B[i] - i;
            }
            C[i] = max;
        }
        res = -1;
        for (i = 1; i <= b - a + 1; i++) {
            if (b - i + 1 >= a) {
                if (C[b - i + 1] != -1 && C[b - i + 1] < i) {
                    res = i;
                    break;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}