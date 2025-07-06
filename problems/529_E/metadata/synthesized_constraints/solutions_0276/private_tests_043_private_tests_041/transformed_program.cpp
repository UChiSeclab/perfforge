#include <bits/stdc++.h>
using namespace std;
int m[21][5010];
int n, k, x, T;

// Checker for invariant 1: Single denomination and large sums
void check_single_denomination_invariant(int n, int q, int maxSum) {
    if (n == 1 && q > 10 && maxSum > 10000000) {
        cerr << "Warning: Potential slowdown with a single denomination and large requests." << endl;
        abort();
    }
}

// Checker for invariant 2: Exhaustive combination search
void check_bills_combination_invariant(int n, int k, int q, int maxSum) {
    if (n < 5 && k > 15 && q > 10 && maxSum > 10000000) {
        cerr << "Warning: Potential slowdown due to large k value and limited denominations." << endl;
        abort();
    }
}

int find(int xx, int pos) {
    int left = 1;
    int right = n;
    if (xx == 0) return 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (m[pos][mid] == xx) return 2;
        if (m[pos][mid] > xx) right = mid - 1;
        if (m[pos][mid] < xx) left = mid + 1;
    }
    return -1;
}

int main() {
    cin >> n >> k;
    int maxSum = 0;  // Variable to track the maximum requested sum
    
    for (int i = 1; i <= n; i++) {
        cin >> m[1][i];
        for (int j = 2; j <= k; j++) m[j][i] = m[1][i] * j;
    }
    cin >> T;

    check_single_denomination_invariant(n, T, 2 * 108);  // Initially using max possible value
    check_bills_combination_invariant(n, k, T, 2 * 108); // Initially using max possible value

    while (T--) {
        cin >> x;
        maxSum = max(maxSum, x);  // Update maxSum with each input

        int res = -1;
        for (int ans = 1; ans <= k; ans++) {
            for (int i = 1; i <= ans; i++) {
                for (int j = 1; j <= n; j++) {
                    if (m[i][j] > x) break;
                    int p = x - m[i][j];
                    int leave = find(p, ans - i);
                    if (leave == 1) res = i;
                    if (leave == 2) res = ans;
                }
                if (res > 0) break;
            }
            if (res > 0) break;
        }
        cout << res << endl;
    }

    // Final check after all inputs are processed
    check_single_denomination_invariant(n, T, maxSum);
    check_bills_combination_invariant(n, k, T, maxSum);

    return 0;
}