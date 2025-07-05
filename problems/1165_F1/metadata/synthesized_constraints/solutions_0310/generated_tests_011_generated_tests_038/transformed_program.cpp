#include <bits/stdc++.h>
using namespace std;

void check_large_sum_invariant(long long totalSum) {
    if (totalSum > 500) { // Example threshold
        cerr << "Warning: Performance bottleneck due to large sum of microtransactions!" << endl;
        abort();
    }
}

void check_large_mid_invariant(long long mid, long long nTypes) {
    if (mid > 2 * nTypes) { // Example threshold
        cerr << "Warning: Performance bottleneck due to large mid value in binary search!" << endl;
        abort();
    }
}

void check_transaction_allocation_invariant(long long mid, long long nTypes) {
    if (mid > 10 * nTypes) { // Example threshold
        cerr << "Warning: Performance bottleneck due to high transaction allocation!" << endl;
        abort();
    }
}

int main() {
    long long n, m, a[400005], sum = 0, le, ri, mid, mp[400005], f, ans, v[400005], cnt, raod;
    pair<long long, long long> b[400005];
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // Check for large sum which affects initialization
    check_large_sum_invariant(sum);

    for (int i = 1; i <= m; i++) {
        cin >> b[i].first >> b[i].second;
    }
    sort(b + 1, b + m + 1);
    
    le = 1;
    ri = 2 * sum;
    
    while (le <= ri) {
        raod = 0;
        mid = (le + ri) / 2;
        
        // Check for large mid value affecting binary search
        check_large_mid_invariant(mid, n);

        f = 0;
        cnt = 0;
        for (int i = 1; i <= 400005; i++) {
            v[i] = 0;
            mp[i] = 0;
        }
        for (int i = 1; i <= m; i++) {
            if (b[i].first <= mid) {
                mp[b[i].second] = b[i].first;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (mp[i]) v[mp[i]] += a[i];
        }
        
        // Check for high transaction allocation
        check_transaction_allocation_invariant(mid, n);

        raod = sum;
        for (int i = 1; i <= mid; i++) {
            cnt++;
            if (v[i] <= cnt) {
                cnt -= v[i];
                raod -= v[i];
            } else {
                raod -= cnt;
                cnt = 0;
            }
        }
        if (cnt - 2 * raod >= 0) {
            ans = mid;
            ri = mid - 1;
        } else {
            le = mid + 1;
        }
    }
    cout << ans << endl;
}