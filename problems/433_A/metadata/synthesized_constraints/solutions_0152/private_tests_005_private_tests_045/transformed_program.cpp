#include <bits/stdc++.h>
using namespace std;

// Checker functions for performance-characterizing invariants
void check_combination_invariant(int cont1, int cont2) {
    if (cont1 * cont2 > 2500) { // Example threshold
        cerr << "Warning: Combination invariant triggered - excessive potential combinations" << endl;
        abort();
    }
}

void check_weight_invariant(int total) {
    if (total % 2 != 0) {
        cerr << "Warning: Weight invariant triggered - odd total weight, cannot split evenly" << endl;
        abort();
    }
}

void check_early_termination_invariant(bool flag, int max_iter) {
    if (!flag && max_iter > 2500) { // Example iteration limit
        cerr << "Warning: Early termination invariant triggered - no solution found early" << endl;
        abort();
    }
}

int main() {
    int n, w, v1, v2, cont1, cont2, q, total;
    bool flag = 0;
    cin >> n;
    cont1 = cont2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> w;
        if (w == 100)
            cont1++;
        else
            cont2++;
    }

    // Check weight invariant
    total = (cont1 * 100) + (cont2 * 200);
    check_weight_invariant(total);

    if (n == 1)
        cout << "NO";
    else {
        if ((cont1 * 100) == (cont2 * 200))
            cout << "YES";
        else {
            q = total / 2;

            // Check combination invariant before entering nested loops
            check_combination_invariant(cont1, cont2);

            int iteration_count = 0;
            for (int i = 0; i <= cont1 and !flag; i++) {
                for (int j = 0; j <= cont2 and !flag; j++) {
                    iteration_count++;
                    v1 = (i * 100) + (j * 200);
                    v2 = total - v1;
                    if (v1 == v2) flag = 1;
                }
            }

            // Check early termination invariant after the nested loops
            check_early_termination_invariant(flag, iteration_count);

            if (flag)
                cout << "YES";
            else
                cout << "NO";
        }
    }
    cout << endl;
    return 0;
}