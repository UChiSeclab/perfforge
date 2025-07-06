#include <bits/stdc++.h>
using namespace std;
const int maxn = 500500;
vector<int> b[maxn];
int a[maxn], s[maxn];

// Checker function for large range iteration
void check_large_range_invariant(int mx) {
    if (mx > 400000) { // Arbitrary large threshold close to constraint
        cerr << "Warning: large_range_invariant triggered - excessive iterations due to large max value" << endl;
        abort();
    }
}

// Checker function for nested loop over large subsets
void check_nested_loop_invariant(int size, int n) {
    if (size > n / 2) { // Trigger if subset size is a significant portion of n
        cerr << "Warning: nested_loop_invariant triggered - excessive iterations over large subsets" << endl;
        abort();
    }
}

int main(void) {
    int n, c;
    scanf("%d%d", &n, &c);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[a[i]].push_back(i);
        mx = max(mx, a[i]);
    }
    
    // Check for large maximum value in the array
    check_large_range_invariant(mx);

    for (int i = 1; i <= n; i++) 
        s[i] = s[i - 1] + (a[i] == c);
    
    int ans = 0;
    for (int i = 1; i <= mx; i++) {
        int tmp = b[i].size() > 0 ? (s[b[i][0] - 1] - 0) : 0;
        
        // Check for large subsets in the auxiliary data structure
        check_nested_loop_invariant(b[i].size(), n);
        
        for (int j = 0; j < b[i].size(); j++) {
            tmp = max(tmp, s[b[i][j] - 1] - j);
            ans = max(ans, s[n] + 1 + tmp + j - s[b[i][j]]);
        }
    }
    
    printf("%d\n", ans);
    return 0;
}