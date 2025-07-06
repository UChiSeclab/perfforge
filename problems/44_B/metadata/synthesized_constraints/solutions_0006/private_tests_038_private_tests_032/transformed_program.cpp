#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const double PI = (double)acos(-1.0);
const double EPS = (double)1e-9;
const int MOD = (int)1e9 + 7;
int dat[20005];

void check_large_n_and_bottles(int n, int a, int b, int c) {
    // Check if n is large and all bottle counts are also large
    if (n > 9000 && a > 4000 && b > 4000 && c > 4000) {
        cerr << "Warning: Performance bottleneck condition triggered - large n and bottle counts!" << endl;
        abort();
    }
}

void check_excessive_combination_attempts(int n, int a, int b, int c) {
    // Check if the potential combinations are excessively high
    if (n * (a + b + c) > 50000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive combination attempts!" << endl;
        abort();
    }
}

int main() {
    // Initialize data array
    for (int i = 0; i <= 20003 - 1; i += 1) dat[i] = 0;
    dat[0] = 1;

    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);

    // Check for performance bottlenecks
    check_large_n_and_bottles(n, a, b, c);
    check_excessive_combination_attempts(n, a, b, c);

    // Adjust n to consider half-liter units
    n *= 2;

    // Calculate number of ways to purchase exactly n liters of cola
    for (int i = n; i >= 1; i -= 1)
        for (int j = 1; j <= c; j += 1) {
            if (i - (j << 2) < 0) break;
            dat[i] += dat[i - (j << 2)];
        }
    for (int i = n; i >= 1; i -= 1)
        for (int j = 1; j <= b; j += 1) {
            if (i - (j << 1) < 0) break;
            dat[i] += dat[i - (j << 1)];
        }
    for (int i = n; i >= 1; i -= 1)
        for (int j = 1; j <= a; j += 1) {
            if (i - (j << 0) < 0) break;
            dat[i] += dat[i - (j << 0)];
        }

    printf("%d\n", dat[n]);
    return 0;
}