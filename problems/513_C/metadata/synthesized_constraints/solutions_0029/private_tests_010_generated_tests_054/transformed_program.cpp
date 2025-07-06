#include <bits/stdc++.h>
using namespace std;

int v[8], n, L[8], R[8], aux[8];
double soma;

void check_large_bid_ranges(int *L, int *R, int n) {
    for (int i = 0; i < n; i++) {
        if (R[i] - L[i] > 8000) { // threshold chosen to indicate "wide" range
            cerr << "Warning: Performance bottleneck condition triggered - large bid range!" << endl;
            abort();
        }
    }
}

void check_recursion_with_sorting(int currentRecursionLevel, int threshold) {
    if (currentRecursionLevel > threshold) { // threshold for recursion depth
        cerr << "Warning: Performance bottleneck condition triggered - deep recursion with sorting!" << endl;
        abort();
    }
}

void check_bid_range_overlap(int *L, int *R, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!(R[i] < L[j] || R[j] < L[i])) { // checks for overlap
                cerr << "Warning: Performance bottleneck condition triggered - overlapping bid ranges!" << endl;
                abort();
            }
        }
    }
}

void vai(int num, int u, double chance, int depth) {
    check_recursion_with_sorting(depth, 10); // check recursion depth

    if (u == n) {
        for (int i = 0; i < n; i++) {
            if (v[i] == 0)
                aux[i] = num - 16;
            else if (v[i] == 1)
                aux[i] = num + 16;
            else
                aux[i] = num;
        }
        sort(aux, aux + n);
        if (aux[n - 2] == num) soma += chance;
        return;
    }
    if (L[u] < num) {
        v[u] = 0;
        vai(num, u + 1,
            chance * ((double)(min(R[u] - L[u] + 1, num - L[u])) /
                      (double)(R[u] - L[u] + 1)), depth + 1);
    }
    if (num < R[u]) {
        v[u] = 1;
        vai(num, u + 1,
            chance * ((double)(min(R[u] - L[u] + 1, R[u] - num)) /
                      (double)(R[u] - L[u] + 1)), depth + 1);
    }
    if (L[u] <= num && num <= R[u]) {
        v[u] = 2;
        vai(num, u + 1, chance * 1.0 / ((double)(R[u] - L[u] + 1)), depth + 1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d %d", L + i, R + i);

    // Insert performance checkers
    check_large_bid_ranges(L, R, n);
    check_bid_range_overlap(L, R, n);

    double total = 0.0;
    for (int i = 1; i <= 10003; i++) {
        soma = 0.0;
        vai(i, 0, 1.0, 0); // start recursion with depth 0
        total += soma * i;
    }
    printf("%.12lf\n", total);
    return 0;
}