#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
const int INF = 1000 * 1000 * 1000;
const int NMAX = 1000 * 1000;
long ans, i, j, k, l, n, m, x, y;
double mx, cur, c;
bool first = true;
long a[1000];
long long mn;

// Checker functions to detect performance bottlenecks
void check_fine_granularity_invariant(double start, double end, double increment) {
    if ((end - start) / increment > 10000000) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive iterations due to fine granularity!" << endl;
        abort();
    }
}

void check_frequent_breaks_invariant(int breakCount, int n) {
    if (breakCount > n / 2) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent inner loop breaks!" << endl;
        abort();
    }
}

void check_non_unique_invariant(bool first, int x, int y) {
    if (!first && x != y) {
        cerr << "Warning: Performance bottleneck condition triggered - non-unique solution space!" << endl;
        abort();
    }
}

int main() {
    freopen("out.deb", "w", stderr);
    scanf("%d", &n);
    for ((i) = (0); (i) < (n); (i)++) scanf("%d", &a[i]);
    mx = 10 + (a[1] - a[0]) * 10;

    // Check for excessive iterations due to fine granularity
    check_fine_granularity_invariant(a[0] * 10, a[0] * 10 + 10, 0.000001);

    int breakCount = 0;
    for (cur = a[0] * 10; cur <= a[0] * 10 + 10; cur += 0.000001) {
        c = cur - a[0] * 10;
        if (c > 10) break;
        for ((i) = (1); (i) < (n); (i)++) {
            c += cur;
            c -= (a[i] - a[i - 1]) * 10;
            if (c > 10) {
                printf("unique\n%d", x);
                return 0;
            }
            if (c < 0) {
                breakCount++;
                break;
            }
        }
        // Check for frequent inner loop breaks
        check_frequent_breaks_invariant(breakCount, n);

        if (c + cur > 0 && i == n) {
            y = (c + cur) / 10 + a[n - 1];
            if (first) {
                x = y;
                first = false;
            }
            // Check for non-unique solution space
            check_non_unique_invariant(first, x, y);

            if (x != y) {
                printf("not unique");
                return 0;
            }
        }
    }
    printf("unique\n%d", x);
    return 0;
}