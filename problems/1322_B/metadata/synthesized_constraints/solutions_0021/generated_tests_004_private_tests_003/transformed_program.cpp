#include <bits/stdc++.h>
using namespace std;

int bits;
bool cmp(int a, int b) {
    a = ((1 << bits) - 1) & a;
    b = ((1 << bits) - 1) & b;
    return a < b;
}

void check_sorting_overhead_invariant(int n, int timesSorted, int maxAllowedSize) {
    if (n > maxAllowedSize && timesSorted > 1) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive sorting detected for large array size!" << endl;
        abort();
    }
}

void check_comparator_overhead_invariant(int comparatorCalls, int threshold) {
    if (comparatorCalls > threshold) {
        cerr << "Warning: Performance bottleneck condition triggered - excessive calls to comparator function!" << endl;
        abort();
    }
}

void check_quadratic_growth_invariant(int n, int iterations, int maxAllowedIterations) {
    if (n * iterations > maxAllowedIterations) {
        cerr << "Warning: Performance bottleneck condition triggered - quadratic growth pattern detected!" << endl;
        abort();
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int vec[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }

    int ans = 0;
    int pot = 1;
    int comparatorCallCount = 0;

    for (int i = 1; i <= 25; i++) {
        bits = i;
        
        // Check for excessive sorting
        check_sorting_overhead_invariant(n, i, 100); // Max size set to 100 for demonstration

        sort(vec, vec + n, [&](int a, int b) {
            comparatorCallCount++;
            return cmp(a, b);
        });

        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int num = (((1 << bits) - 1) & vec[j]);
            int aux = (1 << (bits - 1));
            int ini = j + 1, fin;

            if (aux - num >= 0)
                ini = max(ini, (int)(lower_bound(vec, vec + n, aux - num, cmp) - vec));
            aux = (1 << bits) - 1;
            fin = upper_bound(vec, vec + n, aux - num, cmp) - vec;
            if (ini < fin) cnt += fin - ini;
            aux = (1 << (bits - 1)) + (1 << bits);
            if (aux - num >= (1 << bits))
                ini = n;
            else
                ini = max(j + 1, (int)(lower_bound(vec, vec + n, aux - num, cmp) - vec));
            fin = n;
            if (ini < fin) cnt += fin - ini;
        }

        // Check for quadratic growth
        check_quadratic_growth_invariant(n, 25, 10000); // Arbitrary threshold for demonstration

        if (cnt % 2 == 1) ans += pot;
        pot <<= 1;
    }

    // Check for excessive comparator calls
    check_comparator_overhead_invariant(comparatorCallCount, 50000); // Arbitrary threshold for demonstration

    printf("%d\n", ans);
    return 0;
}