#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int a[N];

// Checkers for performance invariants
void check_n_invariant(int n) {
    if (n >= 100) {
        cerr << "Warning: Performance bottleneck condition triggered - large value of n causing nested loop overhead!" << endl;
        abort();
    }
}

void check_sort_invariant(int sortCount, int n) {
    if (sortCount > 1 && n >= 100) {
        cerr << "Warning: Performance bottleneck condition triggered - repeated sorting with large n!" << endl;
        abort();
    }
}

void check_binary_search_invariant(int searchCalls, int n) {
    if (searchCalls > n * log2(n) && n >= 100) { // Assuming a typical log2(n) search depth
        cerr << "Warning: Performance bottleneck condition triggered - excessive binary search calls!" << endl;
        abort();
    }
}

int sea(int x, int l, int r) {
    int searchCalls = 0;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
        searchCalls++;
    }
    return l;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Check value of n
    check_n_invariant(n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    int sortCount = 0; // Track number of sorts

    for (int i = 24; i >= 0; i--) {
        int searchCalls = 0; // Track number of binary search calls
        for (int j = 1; j <= n; j++) {
            a[j] %= (int)pow(2, i + 1);
        }
        sort(a + 1, a + n + 1);
        sortCount++;
        
        int cnt = 0;
        for (int j = 1; j < n; j++) {
            cnt += max(0, sea((int)pow(2, i + 1) - a[j], j + 1, n + 1) - 1 -
                              sea((int)pow(2, i) - a[j], j + 1, n + 1) + 1);
            cnt += max(
                0, sea((int)pow(2, i + 2) - 1 - a[j], j + 1, n + 1) - 1 -
                       sea((int)pow(2, i) + (int)pow(2, i + 1) - a[j], j + 1, n + 1) +
                       1);
            searchCalls += 2; // Each pair of calls increases the search call count
        }

        // Check number of binary search calls
        check_binary_search_invariant(searchCalls, n);
        
        if (cnt % 2 == 1) ans += (int)pow(2, i);
    }

    // Check the sort invariant after the loop
    check_sort_invariant(sortCount, n);

    printf("%d\n", ans);
    return 0;
}