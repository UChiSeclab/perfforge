#include <bits/stdc++.h>
using namespace std;

int a[110];
int b[110];

void check_combinatorial_pairs_invariant(int n) {
    if (n > 40) {
        cerr << "Warning: combinatorial_pairs_invariant triggered - excessive combinations leading to sort operations" << endl;
        abort();
    }
}

void check_nested_loop_sort_invariant(int numSorts) {
    if (numSorts > 5000) {
        cerr << "Warning: nested_loop_sort_invariant triggered - high number of nested loops with sorting" << endl;
        abort();
    }
}

void check_redundant_sort_invariant(int redundantSorts) {
    if (redundantSorts > 1000) {
        cerr << "Warning: redundant_sort_invariant triggered - excessive redundant sorting operations" << endl;
        abort();
    }
}

void check_large_sublist_removal_invariant(int n) {
    if (n > 45) {
        cerr << "Warning: large_sublist_removal_invariant triggered - removal and sorting of large sublists" << endl;
        abort();
    }
}

int main() {
    int n;
    cin >> n;
    n *= 2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    // Check the invariant related to combinatorial pair calculations
    check_combinatorial_pairs_invariant(n / 2);
    
    int ans = 10000005;
    int numSorts = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            memset(b, 0, sizeof(b));
            int num = 0;
            for (int k = 1; k <= n; k++)
                if (k != i && k != j) b[num++] = a[k];
            
            sort(b, b + num);
            numSorts++;  // Increment sorting counter
            
            int sum = 0;
            for (int k = 0; k < num; k += 2) sum += b[k + 1] - b[k];
            ans = min(sum, ans);
        }
    }

    // Check for nested loop sort invariant
    check_nested_loop_sort_invariant(numSorts);

    // Check for redundant sorting
    check_redundant_sort_invariant(numSorts);

    // Check for large sublist removal and sort
    check_large_sublist_removal_invariant(n / 2);

    cout << ans << endl;
    return 0;
}