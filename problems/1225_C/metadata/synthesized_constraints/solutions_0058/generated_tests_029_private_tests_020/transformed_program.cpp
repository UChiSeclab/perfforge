#include <bits/stdc++.h>
using namespace std;

void check_large_loop_iterations(int n, int p, int i) {
    if (i > 0 && n - p * i > 0 && n / p <= i) {
        cerr << "Warning: Performance bottleneck condition triggered - large loop iterations due to input parameters!" << endl;
        abort();
    }
}

void check_high_bit_count(int tmp) {
    int bitCount = 0;
    int temp = tmp;
    while (temp) {
        bitCount += temp % 2;
        temp /= 2;
    }
    if (bitCount > 30) { // Arbitrary threshold for excessive bit count
        cerr << "Warning: Performance bottleneck condition triggered - high bit count computation repetitions!" << endl;
        abort();
    }
}

void check_lack_of_early_termination(int cnt, int i, int n, int p) {
    if (cnt > i || i > n - p * i) {
        cerr << "Warning: Performance bottleneck condition triggered - lack of early termination in loop!" << endl;
        abort();
    }
}

int main() {
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 0; i <= 1000000; i++) {
        check_large_loop_iterations(n, p, i); // Check for large loop iterations

        int tmp = n - p * i;
        int cnt = 0;
        while (tmp) {
            cnt += tmp % 2;
            tmp /= 2;
        }

        check_high_bit_count(n - p * i); // Check for high bit count computation

        if (cnt <= i && i <= n - p * i) {
            printf("%d\n", i);
            return 0;
        }

        check_lack_of_early_termination(cnt, i, n, p); // Check for lack of early termination
    }
    printf("-1\n");
    return 0;
}