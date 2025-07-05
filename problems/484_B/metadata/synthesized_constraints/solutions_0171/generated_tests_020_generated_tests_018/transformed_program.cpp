#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int MAX = 1000006;
int a[maxn];
int n;

// Checker functions based on derived invariants
void check_small_elements_invariant(int element) {
    if (element < 10) { // Assume small elements are those less than a threshold like 10
        cerr << "Warning: small_elements_invariant triggered - small elements causing long iterations" << endl;
        abort();
    }
}

void check_repeated_searches_invariant(int n) {
    if (n > 100) { // Threshold for number of elements in array
        cerr << "Warning: repeated_searches_invariant triggered - repeated searches on large data" << endl;
        abort();
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    // Check for repeated searches invariant after reading input
    check_repeated_searches_invariant(n);
    
    sort(a, a + n);
    n = unique(a, a + n) - a;
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        // Check for small elements invariant before processing
        check_small_elements_invariant(a[i]);
        
        for (int j = 2 * a[i]; j < MAX; j += a[i]) {
            ans = max(ans, *(lower_bound(a, a + n, j) - 1) % a[i]);
        }
        ans = max(ans, a[n - 1] % a[i]);
    }
    cout << ans << endl;
    return 0;
}