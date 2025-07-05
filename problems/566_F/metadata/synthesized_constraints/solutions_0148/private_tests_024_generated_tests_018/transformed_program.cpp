#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int cnt[maxn + 10];

// Function to check performance invariants
void check_smallest_number_invariant(int val) {
    if (val == 1) {
        cerr << "Warning: Performance bottleneck condition triggered due to smallest number being 1!" << endl;
        abort();
    }
}

void check_divisor_invariant(int val) {
    if (val <= 10) {  // Using 10 as a threshold for demonstrating potential divisibility impact
        cerr << "Warning: Performance bottleneck condition triggered due to low divisor value!" << endl;
        abort();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        
        // Integrate checks before any processing with the number
        if (i == 0) {  // Only need to check for the first (smallest) number
            check_smallest_number_invariant(val);
        }
        check_divisor_invariant(val);
        
        cnt[val] = max(cnt[val], 1);
        for (int tmp = val * 2; tmp <= maxn; tmp += val) {
            cnt[tmp] = max(cnt[tmp], cnt[val] + 1);
        }
        ans = max(ans, cnt[val]);
    }
    
    cout << ans << '\n';
    return 0;
}