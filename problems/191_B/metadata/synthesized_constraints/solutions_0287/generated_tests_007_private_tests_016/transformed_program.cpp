#include <bits/stdc++.h>
using namespace std;

// Checker functions
void check_sort_invariant(int n) {
    if (n > 10000) {
        cerr << "Warning: sort_invariant triggered - large input size for sorting" << endl;
        abort();
    }
}

void check_budget_invariant(long long atteignable, long long total) {
    if (atteignable > total) {
        cerr << "Warning: budget_invariant triggered - atteignable exceeds budget" << endl;
        abort();
    }
}

void check_search_invariant(int n) {
    if (n > 10000) {
        cerr << "Warning: search_invariant triggered - excessive elements to search" << endl;
        abort();
    }
}

int comparer(const void* a, const void* b) { return *(int*)b - *(int*)a; }

int main() {
    int n, k, i;
    long long int total;
    long long int atteignable = 0;
    int p[100000];
    int q[100000];
    int dernier, reponse;
    long long int pluspetit;

    cin >> n >> k;
    cin >> total;

    // Apply invariant checks
    check_sort_invariant(n);
    check_search_invariant(n);

    for (i = 0; i < n; i++) {
        cin >> p[i];
        q[i] = p[i];
    }

    qsort(p, n - 1, sizeof(int), comparer);

    for (i = 0; i < k; i++) {
        atteignable += (long long int)p[i];
    }

    // Check budget invariant
    check_budget_invariant(atteignable, total);

    dernier = p[k - 1];
    if (atteignable <= total) {
        printf("%d\n", n);
    } else {
        pluspetit = (long long int)dernier + total - atteignable + 1;
        for (i = 0; i < n; i++) {
            if (q[i] >= pluspetit) {
                reponse = i + 1;
                i = n + 10;
            }
        }
        if (i > n + 5)
            printf("%d\n", reponse);
        else
            printf("%d\n", n);
    }

    return 0;
}