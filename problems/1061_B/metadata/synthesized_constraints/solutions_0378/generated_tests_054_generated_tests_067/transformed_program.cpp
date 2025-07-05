#include <bits/stdc++.h>
using namespace std;
long long int a[100001];

// Check if n is large enough to potentially cause sorting overhead
void check_sorting_invariant(long long n) {
    if (n > 10000) {
        cerr << "Warning: Performance bottleneck condition triggered - large n may cause sorting overhead!" << endl;
        abort();
    }
}

// Check for high variation in stack heights
void check_loop_invariant(long long n, const long long a[]) {
    long long max_stack = *max_element(a, a + n);
    long long min_stack = *min_element(a, a + n);
    if (n > 5000 && (max_stack - min_stack) > n / 10) {
        cerr << "Warning: Performance bottleneck condition triggered - high variation in stack heights!" << endl;
        abort();
    }
}

// Check for frequent conditional evaluations in loops
void check_conditional_invariant(long long n) {
    if (n > 50000) {
        cerr << "Warning: Performance bottleneck condition triggered - frequent conditional evaluations!" << endl;
        abort();
    }
}

int main() {
    long long int n, m, i, Ans = 0, sum = 0, cnt;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        scanf("%I64d", &a[i]);
        sum += a[i];
    }
    
    check_sorting_invariant(n);         // Check before sorting
    check_loop_invariant(n, a);         // Check for stack height variability
    check_conditional_invariant(n);     // Check for potential loop evaluation issues
    
    if (n == 1) {
        cout << 0;
        return 0;
    }
    
    sort(a, a + n);
    cnt = 1;
    Ans = 1;
    for (i = 1; i < n; i++) {
        if (a[i] == cnt)
            Ans++;
        else if (a[i] > cnt && i == n - 1)
            Ans += a[i] - cnt;
        else if (a[i] > cnt && i < n - 1) {
            Ans++;
            cnt++;
        }
    }
    cout << sum - Ans << endl;
    return 0;
}