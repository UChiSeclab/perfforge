#include <bits/stdc++.h>
using namespace std;

void check_capacity_invariant(int summ, int n) {
    if (summ >= n && n > 1000000) { // Assuming a large threshold for n
        cerr << "Warning: Capacity invariant triggered - high matchbox capacity handling detected!" << endl;
        abort();
    }
}

void check_matchbox_handling_invariant(int m, int* b) {
    int similarMatchCount = 0;
    for (int i = 0; i < m - 1; i++) {
        if (b[i] == b[i + 1]) { // Simple condition for detecting similar match counts
            similarMatchCount++;
        }
    }
    if (similarMatchCount > m / 2) { // If more than half have similar counts
        cerr << "Warning: Matchbox handling invariant triggered - similar match counts detected!" << endl;
        abort();
    }
}

void check_sorting_invariant(int m, int* a) {
    int largeContainerThreshold = 100000; // Arbitrary threshold for large container
    for (int i = 0; i < m; i++) {
        if (a[i] > largeContainerThreshold) {
            cerr << "Warning: Sorting invariant triggered - large container size detected!" << endl;
            abort();
        }
    }
}

int main() {
    int n, m, sum(0), summ(0);
    cin >> n >> m;
    int c[m][2];
    for (int i = 0; i < m; i++) {
        cin >> c[i][0];
        cin >> c[i][1];
    }

    // Insert checkers after input reading
    check_capacity_invariant(summ, n);
    int b[m];
    for (int i = 0; i < m; i++) b[i] = c[i][1];
    check_matchbox_handling_invariant(m, b);
    int a[m];
    for (int i = 0; i < m; i++) a[i] = c[i][0];
    check_sorting_invariant(m, a);

    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            if (c[j][1] > c[i][1]) {
                swap(c[j], c[i]);
            }
        }
        summ += c[i][0];
    }
    if (summ >= n) {
        int k(0);
        while (n) {
            while (c[k][0] && n) {
                sum += c[k][1];
                c[k][0] -= 1;
                n--;
            }
            k++;
        }
    } else {
        int k(0);
        while (summ) {
            while (c[k][0] && summ) {
                sum += c[k][1];
                c[k][0] -= 1;
                summ--;
            }
            k++;
        }
    }
    cout << sum;
    return 0;
}