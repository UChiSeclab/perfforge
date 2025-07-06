#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int a[maxn], n;
map<int, int> mp;

void check_multiset_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large multiset size with frequent operations!" << endl;
        abort();
    }
}

void check_large_n_invariant(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large number of boxers!" << endl;
        abort();
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i = i * 2) mp[i] = 1;
    
    // Check if n is close to the upper limit
    check_large_n_invariant(n >= (1 << 17)); // Use a threshold close to 2^18

    long long ans = 0;
    multiset<int> s;
    for (int i = n; i >= 1; i--) {
        if (a[i] == -1) break;
        s.insert(a[i]);
        
        // Check multiset size only if it's a stage where comparisons happen
        if (mp[i]) {
            ans += *s.begin();
            s.erase(s.begin());
            
            // Check if multiset size is large
            check_multiset_invariant(s.size() > (n / 4)); // Threshold based on tournament stage
        }
    }
    cout << ans << endl;
    return 0;
}