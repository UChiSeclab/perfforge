#include <bits/stdc++.h>
using namespace std;

int dp[1000005];
int leftt = 100000000;
int rightt = 0;
int le[5005];
int ri[5005];
vector<int> ans;

// Checker for high number of overlapping lessons
void check_high_overlap(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - high number of overlapping lessons!" << endl;
        abort();
    }
}

// Checker for large time interval range
void check_large_time_range(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - large time interval range!" << endl;
        abort();
    }
}

// Checker for multiple lesson overlaps
void check_multiple_overlaps(bool condition) {
    if (condition) {
        cerr << "Warning: Performance bottleneck condition triggered - multiple lesson overlaps!" << endl;
        abort();
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    // Read input and populate lesson arrays
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        r--;
        le[i] = l;
        ri[i] = r;
        dp[l]++;
        dp[r + 1]--;
    }

    // Check for potential bottlenecks before processing
    check_large_time_range((ri[n-1] - le[0]) > 100000); // Arbitrary threshold for large time range

    for (int i = 1; i <= 1000000; i++) {
        dp[i] += dp[i - 1];
        if (dp[i] > 2) {
            cout << 0;
            return 0;
        }
    }

    check_high_overlap(dp[1000000] > 0); // Check if any time interval still has more than 2 overlaps

    for (int i = 0; i <= 1000000; i++) {
        if (dp[i] == 2) {
            leftt = min(leftt, i);
            rightt = max(rightt, i);
        }
    }

    for (int i = 0; i < n; i++) {
        if (le[i] <= leftt && rightt <= ri[i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i + 1 << " ";
    }

    check_multiple_overlaps(ans.size() > (n / 2)); // Arbitrary threshold for multiple overlaps
    return 0;
}