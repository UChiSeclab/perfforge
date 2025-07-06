#include <bits/stdc++.h>
using namespace std;

void fastInOut() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);
}

void check_range_invariant(long long ma, long long mi) {
    if ((ma - mi) > 100000) { // Threshold can be adjusted based on expected stick length range
        cerr << "Warning: Performance bottleneck condition triggered - large range of stick lengths!" << endl;
        abort();
    }
}

void check_unique_lengths_invariant(const map<int, long long>& cnt) {
    int odd_count = 0;
    for (const auto& pair : cnt) {
        if (pair.second % 2 == 1) {
            odd_count++;
        }
    }
    if (odd_count > 1000) { // Threshold set to a reasonable value considering input constraints
        cerr << "Warning: Performance bottleneck condition triggered - too many unique stick lengths with odd counts!" << endl;
        abort();
    }
}

void check_high_value_range(long long ma) {
    if (ma > 1000000) { // Threshold based on typical expected maximum stick lengths
        cerr << "Warning: Performance bottleneck condition triggered - high stick length values!" << endl;
        abort();
    }
}

int main() {
    map<int, long long> cnt;
    long long mi = 100000009, ma = -1, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x < mi) mi = x;
        if (x > ma) ma = x;
        cnt[x]++;
    }

    // Insert the checks at effective points
    check_range_invariant(ma, mi); // Check for large range of stick lengths
    check_unique_lengths_invariant(cnt); // Check for high number of unique stick lengths with odd counts
    check_high_value_range(ma); // Check for high stick length values

    for (int i = ma; i >= mi; i--) {
        if (cnt[i] % 2 == 1) {
            if (cnt[i - 1] > 0) cnt[i - 1]++;
            cnt[i]--;
        }
    }
    long long ans = 0;
    long long left = -1;
    for (int i = ma; i >= mi; i--) {
        long long num = i;
        if (left != -1 && cnt[i] > 0) {
            ans += left * num;
            cnt[i] -= 2;
            left = -1;
        }
        long long x = cnt[i] / 4;
        ans += (x * num * num);
        if (cnt[i] % 4 != 0) left = i;
    }
    cout << ans;
}